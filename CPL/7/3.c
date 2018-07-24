#include <stdarg.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

void minprintf(char *, ...);

int main()
{
    char *string = "%s World";
    char *hello = "Hello";
    minprintf(string, hello);
    minprintf("%u\n", 1234);
}

/*minprintf: minimal printf with variable argument list*/
void minprintf(char *fmt, ...)
{
    va_list ap;
    char *p, *sval;
    int ival;
    double dval;
    unsigned uval;
    
    va_start(ap, fmt);
    for(p = fmt; *p; p++) {
        
        if(*p !=  '%') {
            putchar(*p);
            continue;
        }
        
        switch (*++p) {
            case 'd':
                ival = va_arg(ap, int);
                printf("%d", ival);
            break;
            case 'f':
                dval = va_arg(ap, double);
                printf("%f", dval);
            break;
            case 's':
                for(sval = va_arg(ap, char *); *sval; sval++)
                    putchar(*sval);
            break;
            case 'u':
                uval = va_arg(ap, unsigned);
                printf("%u", uval); 
            break;
            default:
                putchar(*p);
            break;
        }
    }
    va_end(ap);
}

