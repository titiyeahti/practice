#include <stdlib.h>
#include <stdio.h>

int main(void){
  for(size_t i = 10; i; --i)
    printf("%zu\n", i);
  for(size_t i = 10; i; --i)
    printf("%zu\n", i);
  for(size_t i = 10; i <= 10; --i)
    printf("%zu\n", i);

  return EXIT_SUCCESS;
}
