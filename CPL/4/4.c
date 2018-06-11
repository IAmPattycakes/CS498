#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

#define MAX 100
#define MAXOP MAX
#define NUMBER '0'
#define MAXVAL MAX
#define BUFSIZE MAX

int getop(char []);
void push(double);
double pop();
int getch();
void ungetch(int);

//Variables for pushing
int sp = 0;
double val[MAXVAL];

//Variables for getch and ungetch
char buf[BUFSIZE];
int bufp = 0;

int main()
{
	int type;
	double op2;
	char s[MAXOP];

	while((type = getop(s)) != EOF) {
		switch(type) {
			case NUMBER:
				push(atof(s));
			break;

			case '+':
				push(pop() + pop());
			break;

			case '*':
				push(pop() * pop());
			break;

			case '-':
				op2 = pop();
				push(pop() - op2);
			break;

			case '/':
				op2 = pop();
				if(op2 != 0.0f) {
					push(pop() / op2);
				}
				else {
					printf("error: zero divisor\n");
				}
			break;

			case '%':
				op2 = pop();
				if(op2 != 0.0f)
					push(fmod(pop(), op2));
				else
					printf("error: cannot modulo by 0\n");
			break;

			case 's':
				printf("%lf\n", sin(pop()));
			break;
			case '\n':
				printf("\t%lf\n", pop());
			break;

			default:
				printf("error: unknown command %s\n", s);
			break;
		}
	}
	return 0;
}

int getop(char s[]) 
{
	int i, c;

	while((s[0] = c = getch()) == ' ' || c == '\t');
	s[1] = '\0';
	if(!isdigit(c) && c != '.') {//Not a number
		if(c == '+' || c == '-' || c == '/' || c == '*' || c == '%') {
			return c;
			i = 0;
		} else { // is letter probably
			if(c == 's') {
				int t1;
				if((t1 = getch()) == 'i') {
					int t2;
					if(getch() == 'n') {
						return 's';
					} else {
						ungetch(t2);
						ungetch(t1);
					}
				} else {
					ungetch(t1);
				}
			}
		}
	}
	if(isdigit(c)) //Collects integer part
		while(isdigit(s[++i] = c = getch()));
	if(c == '.') //Collects fraction part
		while(isdigit(s[++i] = c = getch()));
	s[i] = '\0';
	if(c != EOF)
		ungetch(c);
	return NUMBER;
}

void push(double f) 
{
	if(sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error, stack full, can't push %g\n", f);
}

double pop() 
{
	if(sp > 0)
		return val[--sp];
	else {
		printf("error: stack empty\n");
		return 0.0f;
	}
}

int getch() 
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) 
{
	if(bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}

void clearStack() 
{
	while(sp != 0) {
		pop();
	}
}

double peek() {
	double ret = pop();
	push(ret);
	return ret;
}

void duplicate() {
	double ret = pop();
	push(ret);
	push(ret);
}