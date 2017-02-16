#include <stdio.h>
#include <malloc.h>

void MergeList(int* pData, int start, int middle, int end){

  int n1 = middle - start + 1;
  int n2 = end - middle;
  int* pDataBackup = (int *) malloc(sizeof(int) * (end - start + 1));
  int i, j, k;
  for (int i = start; i <= end; i++) {
    pDataBackup[i - start] = pData[i];
  }
  i = j = 0;
  k = start;
  while (i < n1 && j < n2) {
    if (pDataBackup[i] <= pDataBackup[j + n1]) {
      pData[k] = pDataBackup[i];
      i++;
    }
    else{
      pData[k] = pDataBackup[j + n1];
      j++;
    }
    k++;
  }
  while (i < n1) {
    pData[k] = pDataBackup[i];
    i++;
    k++;
  }
  while (j < n2) {
    pData[k] = pDataBackup[j + n1];
    j++;
    k++;
  }
  free(pDataBackup);
  return;
}

void MergeSort(int* pData, int start, int end){
  if (end <= start) {
    return;
  }
  int middle = (end - start) / 2 + start;
  MergeSort(pData, start, middle);
  MergeSort(pData, middle + 1, end);
  MergeList(pData, start, middle, end);
  return;
}

int main(int argc, char const *argv[]) {
  int array[8] = {6, 3, 8, 4, 0, 3, 6, 9};
  MergeSort(array, 0, 7);
  for (int i = 0; i < 8; i++) {
    printf("%d\t", array[i]);
  }
  return 0;
}
