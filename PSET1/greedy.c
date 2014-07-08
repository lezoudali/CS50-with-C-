#include <stdio.h>
#include <cs50.h>
#include <math.h>

//greedy program which counts the least amount of coins use for change
int main(void)
{
    float value;
    int counter=0;
    int change;
   
    do 
    {
        printf("Oh Hai! How much change is owned? ");
        value = GetFloat();
    }
    
    while( value<0  );
    
     
    value = value*100;
    change = round(value);
    
    
 //counts the number of coins 
    
   while ( change !=0 ) 
    {
        if (change>=25)
        {
            change = change-25;
            counter++;
        }else if (change>=10 && change <25){
            
            change = change -10; 
            counter++;    
        
        }else if (change>=5 && change <10){
            
            change = change -5; 
            counter++;    
        
        }else if ( change>=1&& change < 5){
            
            change = change -1; 
            counter++;    
        }
        
    } 
    printf("%d\n", counter);    

   

}
