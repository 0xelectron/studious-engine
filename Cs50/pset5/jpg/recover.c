/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Recovers JPEGs from a forensic image.
 */

#include<stdio.h>
#include<stdlib.h>
#include <stdint.h>

int main(void)
{
     // open input file 
    FILE* inptr = fopen("card.raw", "r");
    if (inptr == NULL)
    {
        printf("Could not open card file");
        return 1;
    }
     
     //initialize buffer to store raw data
     uint8_t buffer[512];
     
     //counter to count no. of file
     int counter = 0;
             
    char title[8]; 
    //reapeat until end of file
    while(fread(&buffer, sizeof(buffer),1, inptr) == 1)
    {
        FILE* img;
        //read a block of data
       
       if(feof(inptr))
       {
            return 0;
       }
        
        //check the starting of jpg and if found, open a new file and write the data to the file
        
        if ((buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && buffer[3] == 0xe0) || (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && buffer[3] == 0xe1))
        {
           
           sprintf(title,"%03d.jpg",counter);
           img = fopen(title,"a");
           fwrite(&buffer,sizeof(buffer),1,img);
           fclose(img);
           counter++;
        }
        
        //else write to the exsisting file
        
        else
        {
           
             if (counter == 1)
            {
                img = fopen("000.jpg","a");
                fwrite(&buffer,sizeof(buffer),1,img);
                fclose(img); 
            }
            
            if( counter > 1)
            {
                sprintf(title,"%03d.jpg",counter-1);
                img = fopen(title,"a");
                fwrite(&buffer,sizeof(buffer),1,img);
                fclose(img);
            
            }
        }

    }

}

