#include "main.h"
/**
 * _printf - main function (printf)
 * @format: parameter (string name)of main function (printf)
 * Return: return output
 */
int _printf(const char *format, ...)
{
	int prichar_act = 0;
	va_list arglist;

	if (format == NULL)
		return (-2);
	va_start(arglist, format);
	while (*format)
	{
		if (*format == '%')
	{
		format++;
		prichar_act++;
		if (*format == '\0')
			break;
		if (*format == 'c')
		{
			char c = va_arg(arglist, int);

			write(1, &c, 1);
			prichar_act++;
		}
		else if (*format == 's')
		{
		char *str_ing = va_arg(arglist, char*);
		int lenofst = 0;

		while (str_ing[lenofst] != '\0')
			lenofst++;
		write(1, str_ing, lenofst);
		prichar_act += lenofst;
		}
		else if (*format == '%')
		{
			write(1, format, 1);
		prichar_act++;
		}
	}
		else
			write(1, format, 1);
	format++;
	}
va_end(arglist);
return (prichar_act);
}
