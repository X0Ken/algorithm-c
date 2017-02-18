#include <stdio.h>

int binary_search(int *pData, int begin, int end, int target){
  int mid = (begin + end) / 2;
  while (begin <= end && target != pData[mid]) {
    if (target > pData[mid]) {
      begin = mid + 1;
    }
    else{
      end = mid - 1;
    }
    mid = (begin + end) / 2;
  }
  if (begin > end) return -1;
  else return mid;
}

int main(int argc, char const *argv[]) {
  int array[8] = {1, 2, 3, 4, 5, 6, 7, 8};
  int index = binary_search(array, 0, 7, 7);
  printf("Index is %d\t", index);
  return 0;
}
