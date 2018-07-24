#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <float.h>

#define MAX 100
#define MAXOP MAX
#define NUMBER '0'
#define MAXVAL MAX
#define BUFSIZE MAX
#define NAME 'N' //Signal that name/identifier/string operation was found

int getop(char []);
void push(double);
double pop();
int getch();
void ungetch(int);
double peek();
void swap();
void duplicate();
void ungets(char []);

double variables[26];

//Variables for pushing
int sp = 0;
double val[MAXVAL];

//Variables for getch and ungetch
char buf[BUFSIZE];
int bufp = 0;

int main()
{
	int type;
	double op2, ans;
	char s[MAXOP];
	int lastvar;

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
			
			case '=':
				pop(); //Throw away the previous variable value
				variables[lastvar - 'a'] = pop();
			break;
			
			case '_':
				push(ans);
			break;
			
			case NAME:
				if(strcmp(s, "sin") == 0) {
					push(sin(pop()));
				} else if(strcmp(s, "cos") == 0) {
					push(cos(pop()));
				} else if(strcmp(s, "tan") == 0) {
					push(tan(pop()));
				} else if(strcmp(s, "pow") == 0) {
					op2 = pop();
					push(pow(pop(), op2));
				} else if(strcmp(s, "exp") == 0) {
					push(exp(pop()));
				} else if(strcmp(s, "peek") == 0) {
					printf("%lf\n", peek());
				} else if(strcmp(s, "swap") == 0) {
					swap();
				} else if(strcmp(s, "dup") == 0) { //shortened for "duplicate"
					duplicate();
				} else printf("error: unknown command %s\n", s);
			break;
			
			case '\n':
			ans = pop();
				printf("\t%lf\n", ans);
			break;
			
			default:
				if(type >= 'a' && type <= 'z') {
					push(variables[type - 'a']);
					lastvar = type;
				} else {
					printf("error: unknown command %s\n", s);
				}
			break;
		}
	}
	return 0;
}

int getop(char s[]) {
	int i, c, c2;

	while((s[0] = c = getch()) == ' ' || c == '\t');
	s[1] = '\0';
	i = 0;
	if(islower(c)) {
		while(islower(s[++i] = c = getch())); //Keep filling up s with all the lowercase letters
		s[i] = '\0';
		if(c != EOF) {
			ungetch(c);
		}
		if(strlen(s) > 1) {
			return NAME;
		} else { //Only read one character, variable.
			return s[i - 1];
		}
	}
	
	if(!isdigit(c) && c != '.' && c != '-') //Not a number
		return c;
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
	double op2 = pop();
	push(op1);
	push(op2);
}

void duplicate() {
	double op1 = pop();
	push(op1);
	push(op1);
}

void ungets(char s[]) {
	int i;
	
	for(i = strlen(s) - 1; i >= 0; i++) {
		ungetch(s[i]);
	}
}