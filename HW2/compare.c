#include <stdio.h>
int main()
{
  int a,b,c,t;
  scanf("%d", &a);
  scanf("%d", &b);
  scanf("%d", &c);
  t = a;
  if (b>=t)
      t = b;
  if (c>=t)
      t = c;
  printf("the biggest is %d\n",t); 
}