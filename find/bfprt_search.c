#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insert_sort(int *array, int begin, int end) {
  int i, j, key;
  for (int j = begin; j <= end; j++) {
    key = array[j];
    i = j - 1;
    while (i >= begin && array[i] > key) {
      array[i + 1] = array[i];
      i--;
    }
    array[i + 1] = key;
  }
}

void swap(int *pData, int a, int b) {
  int tmp = pData[a];
  pData[a] = pData[b];
  pData[b] = tmp;
}

int bfprt_parttion(int *pData, int begin, int end, int index) {
  int i = begin;
  swap(pData, end, index);
  for (int j = begin; j <= end - 1; j++) {
    if (pData[j] < pData[end]) {
      swap(pData, j, i);
      i++;
    }
  }
  swap(pData, end, i);
  return i;
}

int bgprt_select(int *pData, int begin, int end, int index) {
  int i;
  if (begin - end < 5) {
    insert_sort(pData, begin, end);
    return begin + index - 1;
  }
  i = begin;
  for (int first = 0; first <= end; first += 5) {
    insert_sort(pData, first, first + 5 < end ? first + 4 : end);
    swap(pData, i, first + 2 < end ? first + 2 : (first + end) / 2);
    i++;
  }
  i = bgprt_select(pData, begin, i - 1, (i - begin) / 2);
  i = bfprt_parttion(pData, begin, end, i);
  if (index == i - begin + 1) {
    return i;
  } else if (index < i - begin + 1) {
    return bgprt_select(pData, i + 1, end, index - (i - begin + 1));
  } else {
    return bgprt_select(pData, begin, i - 1, index);
  }
}

#define NUMBER_SIZE 1000
#define SEARCH_INDEX 88

int main(int argc, char const *argv[]) {
  int index;
  int *array = (int *)malloc(sizeof(int) * NUMBER_SIZE);
  srand((unsigned int)time(NULL));
  for (size_t i = 0; i < NUMBER_SIZE; i++) {
    array[i] = rand();
    printf("%d\t", array[i]);
  }
  index = bgprt_select(array, 0, NUMBER_SIZE - 1, SEARCH_INDEX);
  printf("\nNumber is %d, Index is %d\n", array[index], index);

  insert_sort(array, 0, 102);
  printf("Number is %d\n", array[SEARCH_INDEX - 1]);
  free(array);
  return 0;
}
