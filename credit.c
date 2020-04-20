/* All credit for the code goes to mitrnsplt (Github profile)
 * Excelent code, i learn a lot from it
 *
 * This code was the only one that got stuck, so i turned
 * to people who managed
 */

#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    long long cardnumber = 0;

    do
    {
        cardnumber = get_long_long("What's your card number?: ");
    }while(cardnumber < 0);

    int count = 0;
    long long digits = cardnumber;
    while(digits > 0)
    {
        digits /= 10;
        count++;
    }
    if((count != 13) && (count != 15) && (count != 16))
    {
        printf("INVALID\n");
    }

    int number[count];

    for(int i = 0; i < count; i++)
    {
        number[i] = cardnumber % 10;
        cardnumber /= 10;
    }

    int originalnumber[count];
    for(int i = 1; i < count; i++)
    {
        originalnumber[i] = number[i];
    }

    for(int i = 1; i < count; i += 2)
    {
        number[i] *= 2;
    }

    int v = 0;
    int temp;

    if(count == 13)
    {
        for(int i = 0; i < count; i++)
        {
            temp = (number[i] % 10) + (number[i]/10 %10);
            v += temp;
        }
        if(originalnumber[12] == 4 && v % 10 == 0)
        {
            printf("Visa\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }

    if(count == 15)
    {
        for(int i = 0; i < count; i++)
        {
            temp = (number[i] % 10) + (number[i]/10 %10);
            v += temp;
        }
        if(originalnumber[14] == 3 && v % 10 == 0 && (originalnumber[13] == 4 || originalnumber[13] == 7))
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }

    if(count == 16)
    {
        for(int i = 0; i < count; i++)
        {
            temp = (number[i] % 10) + (number[i]/10 %10);
            v += temp;
        }
        if(originalnumber[15] && v % 10 == 0)
        {
            printf("VISA\n");
        }
        else if(originalnumber[15] == 5 && v % 10 == 0 && (originalnumber[14] == 1 || originalnumber[14] == 2 || originalnumber[14] == 3 || originalnumber[14] == 4 || originalnumber[14] == 5))
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
}
