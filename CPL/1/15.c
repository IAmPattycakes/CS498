#include <stdio.h>

float FtoC(float temp);

int main()
{
  float fahr;
  int lower, upper, step;
  lower = 300;
  upper = 0;
  step = -10;

  printf("Farenheit to Celsius\n");
  for(fahr = lower; fahr >= upper; fahr = fahr + step) {
    printf("%3.0f %6.1f\n", fahr, FtoC(fahr));
  }
}

float FtoC(float temp) 
{
  return (temp + 32) * (5.0/9.0); 
}

