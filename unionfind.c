#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

void print(size_t n, size_t t[n]){
  for(size_t i = 0; i<n; i++){
    t[i] != SIZE_MAX ? printf("%zu -> %zu\t", i, t[i]) : 
      printf("[%zu]\t", i);
  }
  putc('\n', stdout);
}

void init_forest(size_t n, size_t t[n]){
  for(size_t i = 0; i < n; i++)
    t[i] = SIZE_MAX;
}

size_t find(size_t n, size_t t[n], size_t elt){
  size_t parent = t[elt];
  if(parent == SIZE_MAX)
    return elt;
  else
    return find(n, t, parent);
}

void find_replace(size_t n, size_t t[n], size_t elt, size_t new_root){
  size_t parent = t[elt];
  t[elt] = new_root;
  if(parent != SIZE_MAX)
    find_replace(n, t, parent, new_root);
}

size_t find_compress(size_t n, size_t t[n], size_t elt){
  size_t parent = t[elt];
  if(parent == SIZE_MAX)
    return elt;
  else{
    size_t root = find_compress(n, t, parent);
    t[elt] = root;
    return root;
  }
}

void forest_union(size_t n, size_t t[n], size_t i, size_t j){
  if(j!=i){
    find_compress(n, t, i);
    find_replace(n, t, j, i);
  }
}

int main(void){
  size_t n = 8;
  size_t t[n];
  init_forest(n, t);
  print(n,t);

  printf("2 (2 3), 2 (2 3 7), 5 (2 3 7 5), 3 (2 3 4 5 7)\n");
  forest_union(n, t, 2, 3);
  print(n,t);
  forest_union(n, t, 2, 7);
  print(n,t);
  forest_union(n, t, 5, 7);
  print(n,t);
  forest_union(n, t, 3, 4);
  print(n,t);

  return EXIT_SUCCESS;
}

