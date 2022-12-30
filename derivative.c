#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <complex.h>

double identite(double x){
  return x;
}

double carre(double x){
  return x*x;
}

double complex inv_c(double complex x){
  return 1/x;
}

double deriv(double f(double), double x, double h){
  return (f(x+h)-f(x-h))/(2*h); 
}

double complex deriv_c(double complex f(double complex), 
    double complex x, double h){
  return (f(x+h)-f(x-h))/(2*h); 
}

int main(int argc, char* argv[argc+1]){
  double complex x;
  double complex res;
  double h;
  if(argc == 4){
    x = strtod(argv[1], NULL) + I*strtod(argv[2], NULL);
    h = strtod(argv[3], NULL);
  } else {
    x = 5. + I/2;
    h = 1E-3;
  }

  res = deriv_c(inv_c, x, h);
  printf("%f + I*%f\n", creal(res), cimag(res));
  return EXIT_SUCCESS;
}
