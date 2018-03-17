#include <stdio.h>
#include <ctype.h>
#include <math.h>

double atof(char *s)
{
	double val, power;
	int i, sign;
	char f_e_sign;
	double f_e_power;

	for (i = 0; isspace(*(s + i)); ++i)
		;

	sign = (*(s + i) == '-') ? -1 : 1;

	if (*(s + i) == '+' || *(s + i) == '-')
		++i;

	for (val = 0.0; isdigit(*(s + i)); ++i)
		val = 10.0 * val + (*(s + i) - '0');

	if (*(s + i) == '.')
		++i;

	for (power = 1.0; isdigit(*(s + i)); ++i)
	{
		val = 10.0 *val + (*(s + i) - '0');
		power *= 10.0;
	}

	if (*(s + i) == 'e' || *(s + i) == 'E')
	{
		i++;
		if (*(s + i) == '-')
		{
			f_e_sign = '-';
			++i;
		}
		else
			f_e_sign = '+';

		for (f_e_power = 0.0; isdigit(*(s + i)); ++i)
		{
			f_e_power = f_e_power * 10.0 + (*(s + i) - '0');
		}

		if (f_e_sign == '-')
			return (sign * val / power) / (pow(10.0, f_e_power));
		else
			return (sign * val / power) * (pow(10.0, f_e_power));
	}

	return sign * val / power;

}