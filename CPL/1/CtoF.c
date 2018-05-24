#include <stdio.h>

main()
{
  float fahr, celsius;
  int lower, upper, step;
  lower = 0;
  upper = 300;
  step = 20;

  celsius = lower;
  printf("Celsius to Farenheit\n");
  while(celsius <= upper) {
    fahr = 32.0 + ((9.0/5.0) * celsius);
    printf("%3.0f %6.1f\n", celsius, fahr);
    celsius = celsius + step;
  }
}

