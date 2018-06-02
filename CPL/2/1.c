/*
This program tests the sizes of the various types of variable by remembering the
value before and checking to see if it rolled over or not. If it did roll over,
it sets the value back to the value before the roll over and tests with a smaller
increment. This incrementing saves a few processor cycles theoretically and a lot
of time waiting for my program to run through many longs numbers.
*/

#include <stdio.h>
#include <limits.h>
#include <float.h>

void testLong(), testInt(), testShort(), testChar(), testULong(), testUInt(), testUShort(), testUChar();

long increment = 100000000000000;
long longTest, longLast = 0;
int intTest, intLast = 0;
short shortTest, shortLast = 0;
char charTest, charLast = 0;
unsigned long uLongTest, uLongLast = 0;
unsigned int uIntTest, uIntLast = 0;
unsigned short uShortTest, uShortLast = 0;
unsigned char uCharTest, uCharLast = 0;

int main() 
{	
	printf("Testing long\n");
	while((increment = increment / 10) >= 1) testLong();
	printf("Minimum: %ld, Maximum: %ld\n", (longTest + 1), longTest);
	increment = 1000000;
	printf("Testing int\n");
	while((increment = increment / 10) >= 1) testInt();
	printf("Minimum: %d, Maximum: %d\n", (intTest + 1), intTest);
	increment = 1000000;
	printf("Testing short\n");
	while((increment = increment / 10) >= 1) testShort();
	printf("Minimum: %d, Maximum: %d\n", (short)(shortTest + 1), shortTest);
	increment = 1000000;
	printf("Testing char\n");
	while((increment = increment / 10) >= 1) testChar();
	printf("Minimum: %d, Maximum: %d\n", (char)(charTest + 1), charTest);
	increment = 100000000000000;
	printf("Testing unsigned long\n");
	while((increment = increment / 10) >= 1) testULong();
	printf("Minimum: %ld, Maximum: %lu\n", (unsigned long)(uLongTest + 1), uLongTest);
	increment = 1000000;
	printf("Testing unsigned int\n");
	while((increment = increment / 10) >= 1) testUInt();
	printf("Minimum: %d, Maximum: %u\n", (unsigned int)(uIntTest + 1), uIntTest);
	increment = 1000000;
	printf("Testing unsigned short\n");
	while((increment = increment / 10) >= 1) testUShort();
	printf("Minimum: %d, Maximum: %d\n", (unsigned short)(uShortTest + 1), uShortTest);
	increment = 1000000;
	printf("Testing unsigned char\n");
	while((increment = increment / 10) >= 1) testUChar();
	printf("Minimum: %d, Maximum: %d\n", (unsigned char)(uCharTest + 1), uCharTest);
}

void testLong()
{
	while((longTest += increment) > longLast) {
		longLast = longTest;
	}
	longTest = longLast;
}

void testInt()
{
	while((intTest += increment) > intLast) {
		intLast = intTest;
	}
	intTest = intLast;
}

void testShort()
{
	while((shortTest += increment) > shortLast) {
		shortLast = shortTest;
	}
	shortTest = shortLast;
}

void testChar()
{
	while((charTest += increment) > charLast) {
		charLast = charTest;
	}
	charTest = charLast;
}

void testULong()
{
	while((uLongTest += increment) > uLongLast) {
		uLongLast = uLongTest;
	}
	uLongTest = uLongLast;
}

void testUInt()
{
	while((uIntTest += increment) > uIntLast) {
		uIntLast = uIntTest;
	}
	uIntTest = uIntLast;
}

void testUShort()
{
	while((uShortTest += increment) > uShortLast) {
		uShortLast = uShortTest;
	}
	uShortTest = uShortLast;
}

void testUChar()
{
	while((uCharTest += increment) > uCharLast) {
		uCharLast = uCharTest;
	}
	uCharTest = uCharLast;
}
