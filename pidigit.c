#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double picompute(size_t n){
  double h = 2 / (double) n;
  /* trapeze, -h(1/2+1/2)/2*/
  double res = -h/2;
  for(size_t i = 0; i<n+1; i++){
    double prod = h*i-1;
    res += h / (1 + prod*prod);
  }

  return res*2;
}

int main(int argc, char* argv[argc+1]){
  size_t n;
  if (argc == 2)
    n = strtoul(argv[1], NULL, 0);
  else
    n = 1000;

  printf("pi vaut presque %f\n", picompute(n));

  return EXIT_SUCCESS;
}
