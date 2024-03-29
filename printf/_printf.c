#include "main.h"

/**
 * _printf - Function receives main string and all the necessary parameters to
 * print a formated string
 * @format: String contains all the desired characters
 * Return: Total count of the characters printed
 */
int _printf(const char *format, ...)
{
	int printed_chars;
	conver_t f_list[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_percent},
		{"d", print_integer},
		{"i", print_integer},
		{"b", print_binary},
		{"u", unsigned_integer},
		{"o", print_octal},
		{"x", print_hex},
		{"X", print_heX},
		{"r", print_reversed},
		{"R", rot13},
		{NULL, NULL}
	};
	va_list arg_list;

	if (format == NULL)
		return (-1);

	va_start(arg_list, format);
	/*Call parser function*/
	printed_chars = parser(format, f_list, arg_list);
	va_end(arg_list);
	return (printed_chars);
}

