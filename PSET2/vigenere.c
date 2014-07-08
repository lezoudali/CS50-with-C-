#include <stdio.h> 
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    //make sure user enters 2 commands
    if (argc != 2)
    {   
        printf("You've entered an invalid command.\n");  
        return 1;
    }
    for (int i = 0; i < strlen(argv[1]); i++)//2nd command (key) must only contains alphabetical char
    {
        if (!(isalpha(argv[1][i])))
        {
            printf("You've entered an invalid command.\n");
            return 1;
        }
    }
     
    string key = argv[1]; //store key in a string, key
    string text = GetString(); // gets text and stores it in a string, text
    int len = strlen(text);    //stores the length text in an int variable, len
    int keylen = strlen(key);  //stores length of key in an int variable, keylen
    int j = 0;
    
    //converts each key char to the corresponding shift number (0-25)
    for(int i =0; i<keylen; i++)
    {
        if(isupper(key[i]))
            key[i] -= 'A';
        else
            key[i] -= 'a';
    }
     //encrypts text
    for (int i=0; i<len; i++)          
    {        
        if (isalpha(text[i]))          //only encrypt alphabetical char  
        {
            if(isupper(text[i]))       //checks if the character to be encrypted is upper case
                text[i] = ( (((text[i]-'A')+ key[j]) % 26)+'A' ); //algorithm
                
            else if (islower(text[i])) //checks if the character to be encrypted is lower case
                text[i] = ( (((text[i]-'a')+ key[j]) % 26)+'a' ); //algorithm
            j++;                       //goes to the next character in the key
            j %= keylen;               //makes sure j does not go over the length of the key
        }     
    } 
    
   printf("%s\n", text);  //prints encrypted text 
    return 0;
}
