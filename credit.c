#include <stdio.h>

int main()
{
    //Counting how many numbers the credit card has

    unsigned long cardn; //cardnumber
    int count=0; // int used to count how many numbers were inserted

    printf("Put the number of your credit card: ");
    scanf("%lu", &cardn);

    unsigned long num = cardn; // used to not alter cardn value

    while( num != 0)
    {
        num = num/10;
        count++;
    }

    //Luhm's Algorithm
    int x1 = cardn %10;
    int x2 = ((cardn/10) %10)*2;
    if (x2 > 9)
        {
            x1 -= 9;
        }
    int x3 = (cardn/100) %10;
    int x4 = ((cardn/1000) %10)*2;
    if (x4 > 9)
        {
            x1 -= 9;
        }
    int x5 = (cardn/10000) %10;
    int x6 = ((cardn/100000) %10)*2;
    if (x6 > 9)
        {
            x1 -= 9;
        }
    int x7 = (cardn/1000000) %10;
    int x8 = ((cardn/10000000) %10)*2;
    if (x8 > 9)
        {
            x1 -= 9;
        }
    int x9 = (cardn/100000000) %10;
    int x10 = ((cardn/1000000000) %10)*2;
    if (x10 > 9)
        {
            x1 -= 9;
        }
    int x11 = (cardn/10000000000) %10;
    int x12 = ((cardn/100000000000) %10)*2;
    if (x12 > 9)
        {
            x1 -= 9;
        }
    int x13 = (cardn/1000000000000) %10;
    int x14 = ((cardn/10000000000000) %10)*2;
    if (x14 > 9)
        {
            x1 -= 9;
        }
    int x15 = (cardn/100000000000000) %10;
    int x16 = ((cardn/1000000000000000) %10)*2;
    if (x16 > 9)
        {
            x1 -= 9;
        }

    int odd_num = x1+x3+x5+x7+x9+x11+x13+x15;
    int even_num = x2+x4+x6+x8+x10+x12+x14+x16;
    int total = (odd_num+even_num) %10;

    switch(count)
    {
        case 13:
            if (total== 0 && x13== 4)
                {
                    printf("VISA\n");
                }
            else
                {
                    printf("INVALID\n");
                }
            break;
        case 15:
            if (total== 0 && x15== 3 && (x14/2)== 4|| (x14/2)==7)
                {
                    printf("AMEX\n");
                }
            else
                {
                    printf("INVALID\n");
                }
            break;
        case 16:
            if (total== 0 && (x16/2)== 5 && x15 < 6)
                {
                    printf("MASTERCARD\n");
                }
            else if (total== 0 && (x16/2)== 4 )
                {
                    printf("VISA\n");

                }
            else
                {
                    printf("INVALID\n");
                }
            break;
        default:
            printf("INVALID\n");
    }
    return 0;
}
