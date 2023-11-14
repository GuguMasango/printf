#ifndef MAIN_H
#define MAIN_H

#include <limits.h>
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

/**
 * _printf - Custom printf function
 * @format: Format string
 *
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    int count = 0;

    while (*format != '\0') {
        if (*format == '%') {
            format++; // Move past '%'
            switch (*format) {
                case 'd':
                case 'i': {
                    int num = va_arg(args, int);
                    int num_digits = snprintf(NULL, 0, "%d", num);
                    char num_str[num_digits + 1];  // +1 for null terminator
                    snprintf(num_str, sizeof(num_str), "%d", num);
                    count += write(1, num_str, num_digits);
                    break;
                }
                case '%':
                    count += write(1, "%", 1);
                    break;
                default:
                    // Ignore unsupported format specifier
                    break;
            }
        } else {
            count += write(1, format, 1);
        }

        format++;
    }

    va_end(args);

    return count;
}

#endif /* MAIN_H */
