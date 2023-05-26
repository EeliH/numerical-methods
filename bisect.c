#include <stdio.h>
#include <math.h>


double f(double x)
{
   return x*x*x - x*x - 1;
}

int main()
{
   double delta = 0.00005;

   double a = 0;
   double b = 2;

   double fa = f(a);
   double fb = f(b);

   if (fa == 0)
      printf("x = %f\n", a);
   if (fb == 0)
      printf("x = %f\n", b);

   while (fabs(a - b) > 2*delta) {
      double c = (a+b)/2; 
      double fc = f(c);
      if (fc == 0)
         printf("x = %f\n", c);

      if (signbit(fc) == signbit(fa)) {
         a = c;
         fa = fc;
      } else {
         b = c;
         fb = fc;
      }
   }

   double root = (a+b)/2;
   printf("approx root: %f\n", root);
      

   return 0;
}

