#include <stdio.h>

int main()
{
    char hexa[25];
    int decimal;
    int i = 0;
    char format;
    int remain;

    decimal = 10;

    format = 'X';
    while (decimal != 0)
    {
        remain = decimal % 16;
        if (remain < 10)
            remain = 48 + remain;
        else
            if (format == 'x')
                remain = remain + 87;
            else
                if (format == 'X')
                remain = remain + 55;
            hexa[i] = remain;
            decimal = decimal / 16;
            i++;
    }
    printf("Hexa number is: \n");
    while (i--)
        printf("%c", hexa[i]);
    printf("\n");
    return (0);
}