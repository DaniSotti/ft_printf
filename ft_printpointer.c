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
int	ft_printpointer(unsigned long long pointer)
{
	char hexa[25];
	int	len;
    int i = 0;
    int remain;

	//len = ft_hexalen(decimal);
    len = 0;
    len += write(1, "0x", 2);
	if (pointer == 0)
    {
		len += write(1, "0", 5);
        return (len);
    }
    else
    {
        while (pointer != 0)
        {
            len += ft_hexalen(pointer);
            remain = pointer % 16;
            if (remain < 10)
                remain = 48 + remain;
            else
                remain = remain + 87;
            hexa[i] = remain;
            pointer = pointer / 16;
            i++;
        }
        while (i--)
            ft_putchar(hexa[i]);
        return (len);
    }
}
