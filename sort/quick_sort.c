#include <stdio.h>

void quick_sort(int *pData, int begin, int end){
  int i, j, key;
  if (begin >= end) {
    return;
  }
  i = begin;
  j = end;
  key = pData[i];
  while (i < j) {
    // if key equal to pData[j] must skip it.
    while(i < j && pData[j] >= key){
      j--;
    }
    pData[i] = pData[j];
    while(i < j && pData[i] <= key){
      i++;
    }
    pData[j] = pData[i];
  }
  pData[i] = key;
  quick_sort(pData, begin, i - 1);
  quick_sort(pData, i + 1, end);
}

int main(int argc, char const *argv[]) {
  int array[8] = {6, 3, 8, 4, 0, 3, 6, 9};
  quick_sort(array, 0, 7);
  for (int i = 0; i < 8; i++) {
    printf("%d\t", array[i]);
  }
  return 0;
}
