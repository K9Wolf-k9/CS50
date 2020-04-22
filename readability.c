#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <math.h>

int count_letters(char text[]);
int count_words(char text[]);
int count_sentences(char text[]);
int grade(float L, float w, float s);

int main(void)
{
    string text = get_string("Text: ");
    
    int L = count_letters(text);
    int w = count_words(text);
    int s = count_sentences(text);
    
    int g = grade(L, w, s);
    if(g < 16 && g > 0)
    {
        printf("Grade %i\n", g);
    }
    else if(g >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Before Grade 1\n");
    }
    
}

int count_letters(char text[])
{
    int count = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if(isalpha(text[i]))
        {
            count++;
        }
    }
    return count;
}

int count_words(char text[])
{
    int count = 0;
    for(int i = 0; text[i] != '\0'; i++)
    {
        if((isspace(text[i])) && (!isspace(text[i+1])))
        {
            count++;
        }
    }
    return count+1;
}

int count_sentences(char text[])
{
    int count = 0;
    for(int i = 0; text[i] != '\0'; i++)
    {
        if(text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count++;
        }
    }
    return count;
}

int grade(float L, float w, float s)
{
    float index = 0.0588 * (100 * L / w) - 0.296 * (100 * s / w) - 15.8;
    int index2 = round(index);
    return index2;
}
