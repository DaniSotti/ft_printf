#include "ft_printf.h"

static int	ft_hexalen(unsigned int decimal)
{
	int	len;

	len = 0;
	while (decimal != 0)
	{
		len++;
		decimal = decimal /16;
	}
	return (len);
}
int	ft_printpointer(unsigned long long decimal)
{
	char hexa[25];
	int	len;
    int i = 0;
    int remain;

	len = ft_hexalen(decimal);
    write(1, "0x", 2);
	if (decimal == 0)
		return (ft_putchar('0'));
    while (decimal != 0)
    {
        remain = decimal % 16;
        if (remain < 10)
            remain = 48 + remain;
        else
            remain = remain + 87;
        hexa[i] = remain;
        decimal = decimal / 16;
        i++;
    }
    while (i--)
		ft_putchar(hexa[i]);
	return (len);
}
