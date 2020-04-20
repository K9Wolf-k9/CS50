#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    int coins = 0;
    float m;
    do
    {
        m = get_float("Change owed: $");
    }while(m < 0);

    m = round(m * 100);
    
    while(m >= 25)
    {
        m -= 25;
        coins++;
    }

    while(m >= 10 && m < 25)
    {
        m -= 10;
        coins++;
    }

    while(m >= 5 && m < 10)
    {
        m -= 5;
        coins++;
    }

    while(m >= 1 && m < 5)
    {
        m -= 1;
        coins++;
    }
    printf("%i\n", coins);
}
