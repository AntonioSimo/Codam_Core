/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/07 10:45:20 by asimone       #+#    #+#                 */
/*   Updated: 2023/03/08 17:12:55 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"
/**
* @brief	Write the hexadecimal representation of a pointer to the standard output.
* @param	ptr Representsthe unsigned long integer representing the pointer.
* @return	The function returns the total counter, which represents the number
* 			of characters written.
*/
int	ft_putptr(unsigned long ptr)
{
	int	counter;

	counter = 0;
	counter += write(1, "0x", 2);
	if (counter < 0)
		return (-1);
	counter += ft_itoh(ptr, 1);
	return (counter);
}

/**
* @brief	Handle and print different format specifiers in a formatted string.
* @param	format Represents the format specifier.
* @param	args Rapresents a va_list containing the variable arguments.
* @param	counter  Tracks the number of characters written
* @return	The function returns the total counter, which represents the number
* 			of characters written.
*/
int	ft_printflags(const char format, va_list args, int counter)
{
	if (format == 'c')
		counter += ft_putchar(va_arg(args, int));
	else if (format == 's')
		counter += ft_putstr(va_arg(args, char *));
	else if (format == 'p')
		counter += ft_putptr(va_arg(args, unsigned long));
	else if (format == 'd' || format == 'i')
		counter += ft_putnbr(va_arg(args, int));
	else if (format == 'u')
		counter += ft_putnnbr(va_arg(args, unsigned int));
	else if (format == 'x')
		counter += ft_itoh(va_arg(args, unsigned int), 1);
	else if (format == 'X')
		counter += ft_itoh(va_arg(args, unsigned int), 0);
	else if (format == '%')
		counter += ft_putchar('%');
	return (counter);
}

/**
* @brief	A simplified implementation of the printf function.
* @param	format Represents a format string that specifies the desired 
*			format for the output.
* @return	The function returns the total counter, which represents the number
* 			of characters written.
*/
int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		counter;

	va_start(args, format);
	counter = 0;
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '%')
				counter += ft_putchar('%');
			else
				counter += ft_printflags(format[i], args, 0);
		}
		else
			counter += ft_putchar((char)format[i]);
		if (counter < 0)
			return (-1);
		i++;
	}
	va_end(args);
	return (counter);
}

// int	main(void)
// {
// 	ft_printf("%s %d %c %x %X", "lol", 123, 'g', 1000, 1000);
// 	//printf(0);
// }