/****************************************************************************
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 6
 *
 * Implements a dictionary's functionality.
 ***************************************************************************/

#include <stdbool.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#include "dictionary.h"


//define struct for node 

typedef struct node 
{
    bool is_word;
    struct node* children[27];
}node;



//prototype 
void unload_helper(node* cursor);

//create root node 
node* root = NULL;

 
//count words
int word_count = 0;
 

/**
 * Returns true if word is in dictionary else false.
 */


bool check(const char* word)
{
    //define required variables 
    int len = strlen(word);
    
    node* cursor = root;
    
    //go through every character and check 
    for(int i=0; i<len;i++)
    {
    	int index = tolower(word[i]) - 'a';
    	
    	if(cursor->children[index] != NULL)
    	{
    		cursor = cursor->children[index];
    	
    	}
    	else if ( cursor->children[index] == NULL)
    	{
    		return false;
    	}
    	
    	if ( i== len-1 )
    	{
    		if ( cursor->is_word == true)
    		return true;
    	}
    }
    
    return false;
}



/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    //load a dictionary into the memmory using trie function
    FILE* dict = fopen(dictionary,"r");
  
    //check errors
    if (dict == NULL)
    {
        printf("Could not open dictionary");
        return 1;
    }
    
      
    //create space for root node
    root = malloc(sizeof(node));
	memset(root, 0, sizeof(node));
   	
   
    //buffer to store word
    char word[LENGTH+1];

  	//required variables
    node* cursor = NULL;
    
    int index = 0;
    //loop through the dictionary
    
    while (fscanf(dict, "%s" , word) == 1)
    {
        cursor = root;
        
        //loop through every character and add to trie
        
        for (int i=0,n=strlen(word);i<n;i++)
        {
        	
        	index = word[i] - 'a';
        	
        	
        	if (cursor->children[index] == NULL)
        	{
				cursor->children[index] = malloc(sizeof(node));
        		memset(cursor->children[index], 0, sizeof(node));
        			
        	}
    		
    		if (i==n-1)
    		{
    			
    			cursor->children[index]->is_word = true;
    			word_count++;
 				
    		}
    		
    		cursor = cursor->children[index];
    		
    	}
    	
	}
   //close file
   fclose(dict);
   return true;
}



/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // return word_count
    
    if (word_count > 0 )
    {
    	return word_count;
    }
    else
    	return 0;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
	//call the destroyer
	
	unload_helper(root);
    return true;
}

/**
 * frees all the pointers recursively.A.K.A Destroyer
 */
void unload_helper(node* cursor)
{
	if (cursor == NULL)
		return;
		
	for (int i=0; i<27;i++)
	{
		
		unload_helper(cursor->children[i]);
	
	}
	
	free(cursor);
}

