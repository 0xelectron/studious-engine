//
// breakout.c
//
// Computer Science 50
// Problem Set 4
//

// standard libraries
#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Stanford Portable Library
#include "gevents.h"
#include "gobjects.h"
#include "gwindow.h"

// height and width of game's window in pixels
#define HEIGHT 600
#define WIDTH 400

//height and width of the paddle 
#define PHeight 10
#define PWidth 60

//height and width of brick
#define BHeight 10
#define BWidth 35
 
// number of rows of bricks
#define ROWS 5

// number of columns of bricks
#define COLS 10

// radius of ball in pixels
#define RADIUS 10

// lives
#define LIVES 3

// prototypes
void initBricks(GWindow window);
GOval initBall(GWindow window);
GRect initPaddle(GWindow window);
GLabel initScoreboard(GWindow window);
void updateScoreboard(GWindow window, GLabel label, int points);
GObject detectCollision(GWindow window, GOval ball);

int main(void)
{
    // seed pseudorandom number generator
    srand48(time(NULL));

    // instantiate window
    GWindow window = newGWindow(WIDTH, HEIGHT);

    // instantiate bricks
    initBricks(window);

    // instantiate ball, centered in middle of window
    GOval ball = initBall(window);

    // instantiate paddle, centered at bottom of window
    GRect paddle = initPaddle(window);

    // instantiate scoreboard, centered in middle of window, just above ball
    GLabel label = initScoreboard(window);

    // number of bricks initially
    int bricks = COLS * ROWS;

    // number of lives initially
    int lives = LIVES;

    // number of points initially
    int points = 0;

    //vertical height for the paddle 
    double y = HEIGHT - 50-PHeight;
    
    //initial velocity of ball
    double Xvelocity = drand48();
    double Yvelocity = 2.0;
    
    //wait for the user to click before starting the game
    waitForClick();
    
    // keep playing until game over
    while (lives > 0 && bricks > 0)
    {
        // follow the mouse horizontally
        
        //check for mouse event
        GEvent event = getNextEvent(MOUSE_EVENT);
        
        //check if something happened 
        if (event!=NULL)
        {
            //check if mouse moved
            if(getEventType(event) == MOUSE_MOVED)
            {
                //x position of the mouse 
                double x = getX(event) - (PWidth/2) ;
                //if paddle is at the right edge
                if (x + (PWidth/2) >= WIDTH-(PWidth/2))
                {
                    setLocation(paddle,WIDTH - PWidth,y);
                }
                //if paddle is at the left edge
                else if ( x <= 0)
                {
                    setLocation(paddle,0,y);
                } 
                
                else
                {
                    setLocation(paddle,x,y);
                }
            }
        }
        
        // move ball
        move(ball, Xvelocity, Yvelocity);

        
        // bounce off top edge of window
        if (getY(ball) <= 0)
        {
            Yvelocity = -Yvelocity;
        }
        
        //bounce of edges
        else if (getX(ball)+getWidth(ball) >=WIDTH)
        {
            Xvelocity = - Xvelocity;
        }
        
        else if(getX(ball) <=0)
        {
            Xvelocity = -Xvelocity;
        }
  
         // decrease life if the ball touches the bottom and pause until mouse clicked
       
        else if (getY(ball) >= getHeight(window))
        {
            lives--;
            if (lives)
            {
                ball=initBall(window);
                waitForClick();
            }
        }
         
        //detect collision
        GObject object = detectCollision(window, ball);
        
        if (object != NULL)
        {
            //take  care of collisions 
            if (object == paddle)
            {
                //bounce back if collided with the paddle
                 Yvelocity = -Yvelocity;
            }
        
            else if (strcmp(getType(object), "GRect") == 0)
            {
                //remove brick and increase if collided with brick
                removeGWindow(window,object);
                points++;
                bricks--;
                updateScoreboard(window,label,points);
                Yvelocity = -Yvelocity;
            }      
       
       }
        
       
       // linger before moving again
       pause(5);
    
    }
    // wait for click before exiting
    waitForClick();

    // game over
    closeGWindow(window);
    return 0;
}

/**
 * Initializes window with a grid of bricks.
 */
void initBricks(GWindow window)
{
    //create a array for colors
    char* colors[5] = {"RED","RED","BLACK","BLUE","BLUE"};
    
    //create a variable for y position of bricks
    double b = 50;
    
    // create a block of bricks 
    for (int i=0;i<ROWS;i++)
    {
        //create a variable for X position of bricks
        double a = 2;
 
        for (int j=0; j<COLS;j++)
        {
           
           GRect brick = newGRect(a,b,BWidth,BHeight);
           setColor(brick, colors[i]);
           setFilled(brick,true); 
           add(window,brick);
           a+= BWidth + 5;
           
        }
       b+=BHeight + 5;
    }
}

/**
 * Instantiates ball in center of window.  Returns ball.
 */
GOval initBall(GWindow window)
{
    //create a ball 
    GOval ball = newGOval(WIDTH-(WIDTH/2)-RADIUS,HEIGHT-(HEIGHT/2)-RADIUS,RADIUS * 2,RADIUS *2);
    setColor(ball,"BLACK");
    setFilled(ball,true);
    add(window,ball);
    return ball;
}

/**
 * Instantiates paddle in bottom-middle of window.
 */
GRect initPaddle(GWindow window)
{
    // create a paddle of required dimensions
    GRect paddle = newGRect(WIDTH-(WIDTH/2)-(PWidth/2),HEIGHT- 50 - PHeight,PWidth,PHeight);
    //set the color to black
    setColor(paddle,"BLACK");
    setFilled(paddle,true);
    //add the paddle to window
    add(window,paddle);
    return paddle;
}

/**
 * Instantiates, configures, and returns label for scoreboard.
 */
GLabel initScoreboard(GWindow window)
{
    // initialize scoreboard and update
    GLabel scoreboard = newGLabel("0");
    double x = (WIDTH - getWidth(scoreboard)-10)/2;
    double y = (HEIGHT - getHeight(scoreboard)-10)/2;
    setLocation(scoreboard,x,y);
    setFont(scoreboard, "SansSerif-36");
    add(window,scoreboard);
    return scoreboard;
    
}

/**
 * Updates scoreboard's label, keeping it centered in window.
 */
void updateScoreboard(GWindow window, GLabel label, int points)
{
    // update label
    char s[12];
    sprintf(s, "%i", points);
    setLabel(label, s);

    // center label in window
    double x = (getWidth(window) - getWidth(label)) / 2;
    double y = (getHeight(window) - getHeight(label)) / 2;
    setLocation(label, x, y);
}

/**
 * Detects whether ball has collided with some object in window
 * by checking the four corners of its bounding box (which are
 * outside the ball's GOval, and so the ball can't collide with
 * itself).  Returns object if so, else NULL.
 */
GObject detectCollision(GWindow window, GOval ball)
{
    // ball's location
    double x = getX(ball);
    double y = getY(ball);

    // for checking for collisions
    GObject object;

    // check for collision at ball's top-left corner
    object = getGObjectAt(window, x, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's top-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-left corner
    object = getGObjectAt(window, x, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // no collision
    return NULL;
}
