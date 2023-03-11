#include <stdio.h>
int main()
{
  double f, c;
  printf("please enter the Fahrenheit degree:\n"); 
  scanf("%lf", &f);
  c = 5 / 9.0 * (f - 32);
  printf("the Celsius degree is %f\n",c); 
}