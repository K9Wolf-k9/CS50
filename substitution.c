// All credit for the code goes to teeschorle (Github profile)

#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

bool validate(string key);

int main(int argc, string argv[])
{
    if(argc == 2)
    {
        string key = argv[1];
        if(validate(key) == true)
        {
            string plaintext = get_string("plaintext: ");
            
            int charcount = strlen(plaintext);
            char ciphertext[charcount];
            string abc = "abcdefghijklmnopqrstuvwxyz";
            
            for(int i = 0; i < charcount; i++)
            {
                if(isupper(plaintext[i]) != 0)
                {
                    for(int j = 0; j < 26; j++)
                    {
                        if(abc[j] == tolower(plaintext[i]))
                        {
                            ciphertext[i] = toupper(key[j]);
                            break;
                        }
                    }
                }
                else if(islower(plaintext[i]) != 0)
                {
                    for(int j = 0; j < 26; j++)
                    {
                        if(abc[j] == plaintext[i])
                        {
                            ciphertext[i] = tolower(key[j]);
                            break;
                        }
                    }
                }
                else
                {
                    ciphertext[i] = plaintext[i];
                }
            }
            printf("ciphertext: %s\n", ciphertext);
            return 0;
        }
        else
        {
            printf("key must contain 26 characters\n");
            return 1;
        }
    }
    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
}

bool validate(string key)
{
    int matches = 0;
    if(strlen(key) == 26)
    {
        for(char c = 'a'; c <= 'z'; c++)
        {
            for(int i = 0; i < 26; i++)
            {
                if(tolower(key[i]) == c)
                {
                    matches++;
                    break;
                }
            }
        }
        if(matches == 26)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}