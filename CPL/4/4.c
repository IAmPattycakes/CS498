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
double peek();
void swap();
void duplicate();

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

int getop(char s[]) {
	int i, c, c2;

	while((s[0] = c = getch()) == ' ' || c == '\t');
	s[1] = '\0';
	if(!isdigit(c) && c != '.' && c != '-') //Not a number
		return c;
	i = 0;
	if(c == '-') {
		c2 = getch();
		if(isdigit(c2) || c2 == '.') {
			ungetch(c2);
		} else {
			if(c2 != EOF) ungetch(c2);
			return '-';
		}
	}
	if(isdigit(c) || c == '-') //Collects integer part
		while(isdigit(s[++i] = c = getch()));
	if(c == '.') //Collects fraction part
		while(isdigit(s[++i] = c = getch()));
	s[i] = '\0';
	if(c != EOF)
		ungetch(c);
	return NUMBER;
}

void push(double f) {
	if(sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error, stack full, can't push %g\n", f);
}

double pop() {
	if(sp > 0)
		return val[--sp];
	else {
		printf("error: stack empty\n");
		return 0.0f;
	}
}

int getch() {
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
	if(bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}

double peek() {
	double op2 = pop();
	push(op2);
	return op2;
}

void swap() {
	double op1 = pop();
	push(pop());
	push(op1);
}

void duplicate() {
	double op1 = pop();
	push(op1);
	push(op1);
}