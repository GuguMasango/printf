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
                case 'c': {
                    int ch = va_arg(args, int);
                    count += write(1, &ch, 1);
                    break;
                }
                case 's': {
                    const char *str = va_arg(args, const char *);
                    while (*str != '\0') {
                        count += write(1, str, 1);
                        str++;
                    }
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
