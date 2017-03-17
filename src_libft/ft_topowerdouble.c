#include "libft.h"

double ft_topowerdouble(double num, int i)
{
	if (num == 0)
		return (0);
	if (i == 0)
		return (1);
	if (i < 0)
		return (ft_topowerdouble(num, i + 1) / num);
	return (num * ft_topowerdouble(num, i - 1));
}