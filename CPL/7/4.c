#include <stdarg.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

void minprintf(char *, ...);

int main()
{
    int month = 0, day = 0, year = 0;
    int str1;
    scanf("%d", &str1);
    printf("%d", str1);
    
    printf("Type in a date MM/DD/YYYY\n"); //None of that y2k nonsence
    minscanf("%d/%d/%d", &month, &day, &year);
    printf("%d%d%d\n", year, month, day);
    printf("Type in a sentence\n");
    char str[10000];
    minscanf("%s", str);
    printf("%s\n", str);
}

/*minprintf: minimal printf with variable argument list*/
void minscanf(char *fmt, ...)
{
    va_list ap;
    char *p, *sval;
    int *ival;
    double *dval;
    unsigned *uval;
    
    va_start(ap, fmt);
    for(p = fmt; *p; p++) {
        
        if(*p !=  '%') {
            continue;
        }
        
        switch (*++p) {
            case 'd':
                ival = va_arg(ap, int *);
                scanf("%d", ival);
            break;
            case 'f':
                dval = va_arg(ap, double *);
                scanf("%f", dval);
            break;
            case 's':
                sval = va_arg(ap, char *);
                scanf("%s ", sval);
            break;
            case 'u':
                scanf("%u", ap);
            break;
            default:
                getchar();
            break;
        }
    }
    va_end(ap);
}

