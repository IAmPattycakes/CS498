#include <stdio.h>

main()
{
  float fahr, celsius;
  int lower, upper, step;
  lower = 300;
  upper = 0;
  step = -20;

  printf("Farenheit to Celsius\n");
  for(fahr = lower; fahr >= upper; fahr = fahr + step) {
    celsius = (5.0/9.0) * (fahr-32.0);
    printf("%3.0f %6.1f\n", fahr, celsius);
  }
}
