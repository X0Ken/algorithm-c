#include "stdio.h"

int parent(int i){
  return ++i / 2 - 1;
}

int left(int i){
  return i * 2 + 1;
}

int right(int i){
  return left(i) + 1;
}

void max_heapify(int *pData, int length, int i){
  int l, r, largest, tmp;
  l = left(i);
  r = right(i);
  if (l < length && pData[l] > pData[i]) {
    largest = l;
  }
  else{
    largest = i;
  }
  if (r < length && pData[r] > pData[largest]) {
    largest = r;
  }
  if (largest != i) {
    tmp = pData[i];
    pData[i] = pData[largest];
    pData[largest] = tmp;
    max_heapify(pData, length, largest);
  }
  return ;
}

void build_max_heap(int *pData, int length){
  for (int i =  length / 2 ; i >= 0; i--) {
    max_heapify(pData, length, i);
  }
  return;
}

void heap_sort(int *pData, int length){
  int tmp;
  build_max_heap(pData, length);
  for (int i = length - 1; i > 0; i--) {
    tmp = pData[i];
    pData[i] = pData[0];
    pData[0] = tmp;
    max_heapify(pData, i, 0);
  }
  return;
}

int main(int argc, char const *argv[]) {
  int array[8] = {6, 3, 8, 4, 0, 3, 6, 9};
  heap_sort(array, 8);
  for (int i = 0; i < 8; i++) {
    printf("%d\t", array[i]);
  }
  return 0;
}
