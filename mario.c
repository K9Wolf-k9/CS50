#include <cs50.h>
#include <stdio.h>

int main(void)
{
     int num;
    do
    {
        num = get_int("Height: ");
    }while(num < 1 || num > 8);

    for(int h = 0; h < num; h++)
    {
        for(int s = 1; s < num-h; s++)
        {
            printf(" ");
        }
        for(int j = 0; j <= h; j++)
        {
            printf("#");
        }
        printf("  ");
        for(int j = h-1; j >= -1; j--)
        {
            printf("#");
        }
        printf("\n");
    }
}
