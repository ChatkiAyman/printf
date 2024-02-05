#include <stdio.h>
#include "main.h"
/**
 * print_str - print string
 * @str: pointer
 * Return: int
 */
int print_str(char *str)
{
	int i = 0;
	int count = 0;
	char *null = "(null)";

	if (str ==  NULL)
	{
		for (i  = 0 ; *(null  + i) != '\0' ; i++)
		{
			_putchar(*(null + i));
			count++;
		}
	}
	else
	{
		for (i = 0; str[i] != 0; i++)
		{
			_putchar(str[i]);
			count++;
		}
	}
	return (count);
}


#include <stdio.h>
#include "main.h"
/**
 * print_num - prints a number
 * @n: variable
 * @count: pointer
 * Return: int
 */
int print_num(int n, int *count)
{
	if (n == -2147483648)
	{
		_putchar('-');
		_putchar('2');
		*count += 2;
		print_num(147483648, count);
		return (0);
	}
	else if (n < 0)
	{
		_putchar('-');
		*count += 1;
		n *= (-1);
	}
	if (n >= 10)
	{
		print_num(n / 10, count);
		_putchar((n % 10) + '0');
		*count += 1;
	}
	else if (n < 10)
	{
		_putchar(n + '0');
		*count += 1;
	}
	return (0);
}


#include <stdio.h>
#include "main.h"

/**
 * _printfBin - print string
 * @n: variable
 * @count: pointer
 * Return: int
 */
int _printfBin(unsigned int n, int *count)
{
	int binary[64] = {0};
	int j, i = 0;

	if (num == 0)
	{
		_putchar('0');
		(*count)++;
		return (0);
	}
	while (num > 0)
	{
		binary[i] = n & 1;
		n = n >> 1;
		i++;
	}
	for (j = i - 1; j >= 0; j--)
	{
		_printf("%d", binary[j]);
		(*count)++;
	}
	return (0);
}



#include <stdio.h>
#include "main.h"
/**
 * _printfSpecif - function that produces output according to a format.
 * @specifier: character string - composed of zero or more directives.
 * @args: character string - composed of zero or more directives.
 * Return: the number of characters printed without null
 */
int _printfSpecif(char specifier, va_list args)
{
	int count = 0;

	if (specifier == 'c')
	{
		_putchar(va_arg(args, int));
		count++;
	}
	else if (specifier == 's')
	{
		char *str = va_arg(args,  char*);

		count += print_str(str);

	}
	else if (specifier == '%')
	{
		count++;
		_putchar('%');
	}
	else if (specifier == 'd' || specifier == 'i')
	{
		int n = va_arg(args, int);

		count += print_num(n, &count);

	}
	else if (specifier == 'b')
	{
		int n = va_arg(args, int);

		count += _printfBin(n, &count);
	}
	return (count);
}


#include <stdio.h>
#include "main.h"
/**
 * _printf - produces output according to a format.
 * @format: character string - composed of zero or more directives.
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);

	if (format == NULL)
	{
		return (-1);
	}

	while (*format != '\0')
	{
		if (*format == '%')
		{
			count += _printfSpecif(*++format, args);
		}
		else
		{
			_putchar(*format);
			count++;
		}

		format++;
	}

	va_end(args);
	return (count);
}
