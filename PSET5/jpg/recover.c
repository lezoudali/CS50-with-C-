/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Recovers JPEGs from a forensic image.
 */
 
 
 #include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <cs50.h>
 
typedef uint8_t BYTE;
#define BLOCKSIZE 512

int main(void)
{
    // TODO
    
    string forensic = "card.raw";

    // open card image
    FILE *fp = fopen(forensic, "r");
    if ( fp == NULL)
    {
        printf("Could not open forensic image: %s.\n", forensic);
        return 1;
    }
 
    FILE *outfile;
    outfile = NULL;
    int jpgname = 0;
    while (1)
    {
       
        //the read buffer for the blocks
        BYTE block[BLOCKSIZE] = {};
        for (int c = 0; c < BLOCKSIZE; c++)
        {
            if (feof(fp))
            {
            
                //reached the end of file
                fclose(fp);
                if (outfile != NULL)
                    fclose(outfile);        
                return (EXIT_SUCCESS);
            }
            //read one byte
            fread(&block[c], sizeof (BYTE), 1, fp);
        }
        if (block[0] == 0xff && block[1] == 0xd8 && block[2] == 0xff && (block[3] == 0xe0 || block[3] == 0xe1))
        {
            //this is a the start of a new jpeg
            // close previously opened out file ptr
            if (outfile != NULL)
            {
                fclose(outfile);
            }
            //make a new filename for each jpg found.
            char filename[10];
            sprintf(filename, "%03d.jpg", jpgname);
            jpgname++;
            //open the outfile pointer
            if ((outfile = fopen(filename, "w")) == NULL)
            {
                printf("Could not write jpg image.\n");
                return 2;
            }
 
            fwrite(&block[0], BLOCKSIZE * sizeof (BYTE), 1, outfile);
        }
        else if (jpgname && outfile != NULL) 
            fwrite(&block[0], BLOCKSIZE * sizeof (BYTE), 1, outfile);
    }
 
    // close forensic image
    fclose(fp);
 
    // that's all folks
    return (EXIT_SUCCESS);
}
