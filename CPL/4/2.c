#include <stdio.h>
#include <ctype.h>

double atof(char s[]);
int atoi(char s[]);

int main()
{
    printf("%f\n", atof("123.45e12"));
}

double atof(char s[])
{
    double val, power, total;
    int i, j, sign, exponent, negExp;
    char expString[5];
    
    for(i = 0; isspace(s[i]); i++); //Skip whitespace
    
    sign = (s[i] == '-') ? -1 : 1;
    if(s[i] == '+' || s[i] == '-') i++;
    for(val = 0.0; isdigit(s[i]); i++) val = 10.0 * val + (s[i] - '0');
    if(s[i] == '.') i++;
    for(power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    total = sign * val / power;
    if(s[i] == 'e' || s[i] == 'E') {
        negExp = 0;
        i++;
        if(s[i] == '+') i++;
        if(s[i] == '-') {
            negExp = 1;
            i++;
        }
        for(j = 0; isdigit(s[i]); i++) {
            expString[j++] = s[i];
        }
        if(negExp) for(j = 0; j < atoi(expString); j++) total *= 0.1;
        else for(j = 0; j < atoi(expString); j++) total *= 10;
    }
    return total;
}

int atoi(char s[])
{
    return (int)atof(s);
}