#include <stdio.h> 
#include <cs50.h> 


int main()
{

    int y, spaceCounter, row=2; 
    
   //ask user for height
   
    printf("please enter the height of the half pyramid(choose a number from 1-23)\n");
    
   
    int height;
    
    do {
    //check if number enter is from 1-23
        printf("Height: ");
        height = GetInt();
    }
    
    while (height < 0 || height > 23);
    
    //generates the half pyramid
        y = height;
        for(int i=0; i<height; i++)
        {
            spaceCounter=y-1;
            while (spaceCounter > 0)
            {
                printf(" ");
                spaceCounter--;
            }
            for(int j=0; j<row; j++)
            {
                printf("#");
            }
            row++;
            printf("\n");
            y--;
         }
}
