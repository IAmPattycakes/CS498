#include <stdio.h>

#define SEARCHSIZE 1000000
#define LOOPS 1
int binsearch(int x, int v[], int n);
int slowbinsearch(int x, int v[], int n);

/*Tests the rough average runtime of the binary search tree by
testing every possible derivation on a strictly counting dataset. */

int main()
{
	int searchArray[SEARCHSIZE];
	for(int i = 0; i < SEARCHSIZE; i++) {
		searchArray[i] = i;
	}
	for(int j = 0; j <= LOOPS; j++) {
		for(int i = 0; i < SEARCHSIZE; i++)	{
			printf("%d\n", slowbinsearch(i, searchArray, SEARCHSIZE));
		}
	}
}

int binsearch(int x, int v[], int n)
{
	int low, high, mid;
	
	low = 0;
	high = n - 1;
	while(low <= high) {
		mid = (low + high) / 2;
		if(x < v[mid]) high = mid - 1;
		else if(x > v[mid]) low = mid + 1;
		else return mid; //Found match
	}
	return -1; //No match
}

int slowbinsearch(int x, int v[], int n)
{
	int low, high, mid;
	
	low = 0;
	high = n - 1;
	while(low + 1 < high) {
		mid = (low + high) / 2;
		if(x < v[mid]) high = mid - 1;
		else low = mid;
		//printf("%d\t%d\t%d\n", low, mid, high);
	}
	if(low == x) return low;
	return -1; //No match
}