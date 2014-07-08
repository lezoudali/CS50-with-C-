#include <stdio.h> 
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{

    //make sure user enters only 2 commands and the second command must a number
    if (argc != 2 || atoi(argv[1]) == 0)
    {   
        printf("You've entered an invalid command.\n");  
        return 1;
    }
    
    //gets key
    int k; 
    k = atoi(argv[1]); // converts k from string to int
    
    if ( k > 26)
    k = k % 26; // avoids looping over alphabet multiple times
    
    //asks user to enter plaintext and saves it in a string
    string text = GetString();
    int n = strlen(text); //stores length of text into n
    
    //encrypts text 
    for (int i = 0; i < n; i++)
    {    
        if (isalpha(text[i]) && isupper(text[i])) //check if characters are alphabetical
        {
           text[i] = ( (((text[i]-'A')+ k) % 26)+'A' ); //algorithm 
        }
        else if(isalpha(text[i]) && islower(text[i]))
        {
           text[i] = ( (((text[i]-'a')+ k) % 26)+'a' ); //algorithm
        }
    }  
        
    printf("%s\n", text); //prints encrypted text
   
     return 0;
  
      
}
