#include <stdio.h>
#define SIZEOFARRAY(a) sizeof(a)/sizeof(a[0])
int main(int argc, char const *argv[]) {
  int numbers[10];
  int i;

  for (i=0; i<SIZEOFARRAY(numbers); i++) {
    numbers[i] = 0;
  }

  for (i=0; i<SIZEOFARRAY(numbers);i++) {
    printf("%d%c", numbers[i], " \n"[(i+1)==SIZEOFARRAY(numbers)]);
  }

  return 0;
}
