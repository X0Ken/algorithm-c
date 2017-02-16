#include <stdio.h>

void InsertSort(int* array, int count) {
  int i, j, key;
  for (int j = 0; j < count; j++) {
    key = array[j];
    i = j - 1;
    while (i >= 0 && array[i] > key) {
      array[i+1] = array[i];
      i--;
    }
    array[i+1] = key;
  }
}


int main(int argc, char const *argv[]) {
  int array[8] = {6, 3, 8, 4, 0, 3, 6, 9};
  InsertSort(array, 8);
  for (int i = 0; i < 8; i++) {
    printf("%d\t", array[i]);
  }
  return 0;
}
