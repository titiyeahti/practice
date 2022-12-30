#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>

#define RAND_D() (double) (rand() * rand())/(double) rand()

void print(size_t n, double a[n]){
  for(size_t i = 0; i < n; i++){
    printf("a[%zu] = %f\t ", i, a[i]);
  }
  putc('\n', stdout);
}

int check(size_t n, double a[n]){
  for(size_t i = 0; i < n-1; i++){
    if(a[i] > a[i+1]) 
      return 1;
  }
  return 0;
}

void y_quicksort(size_t n, double a[n]){
  double temp;
  if(n == 2){
    if(a[0] > a[1]) {
      temp = a[0];
      a[0] = a[1];
      a[1] = a[0];
    }
  } else if(n > 2){
    /* pivot is a[0] */
    size_t count = 0;
    size_t i = 1;
    while (i+count < n){
      if (a[i] > a[0]){
        temp = a[i];
        a[i] = a[n-1-count];
        a[n-1-count] = temp;
        count ++;
      } else {
        i++;
      }
    }
    
    temp = a[0];
    a[0] = a[i-1];
    a[i-1] = temp;

    y_quicksort(i-1, a);
    y_quicksort(count, a+i); 
  }
}

void y_merge(size_t n, size_t m, double a[n+m]){
  size_t i=0, j=0;
  double t[n+m];
  while(i < n && j < m){
    if(a[i] < a[j+n]){
      t[i+j] = a[i];
      i++;
    } else {
      t[i+j] = a[n+j];
      j++;
    }
  }

  if(i == n){
    memcpy(a, t, (n+j)*sizeof(double));
  } else {
    memcpy(a+i+m, a+i, (n-i)*sizeof(double));
    memcpy(a, t, (i+m)*sizeof(double));
  }
}

void y_mergesort(size_t n, double a[n]){
  if(n>1){
    size_t mid = n>>1;
    y_mergesort(mid, a);
    y_mergesort(n-mid, a+mid);
    y_merge(mid, n-mid, a);
  }
}

void randinit(size_t n, double a[n]){
  for(size_t i = 0; i < n; i++){
    a[i] = RAND_D();
  }
}

int main(int argc, char* argv[]){
  int result;
  size_t n = 6;

  if (argc == 2){
    if (!(n=strtoul(argv[1], NULL, 0)))
      n=6;
  }

  double a[n];
  randinit(n, a);
  y_quicksort(n, a);
  print(n,a);
  result = check(n, a);
  assert(!result);

  randinit(n, a);
  y_mergesort(n, a);
  print(n,a);
  result = check(n, a);
  assert(!result);
  return EXIT_SUCCESS;
}
