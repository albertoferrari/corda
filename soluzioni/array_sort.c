#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/timeb.h>

#define DIM_ARRAY 10000   //# array elements
#define MAXVAL 10000  // 0..MAXVAL value of an element

void swap(int *x, int *y) {
   int temp = *x;
   *x = *y;
   *y = temp;
}

/* print array */
void printArray(int array[], int size) {
    int i;
    for(i = 0; i < size; i++)
        printf("array[%d] = %d \n",i,array[i]);
}

/* fill array with random values */
void fillArray(int array[], int size) {
    srand(time(NULL));
    int i;
    for(i = 0; i < size; i++)
        array[i] = rand()%MAXVAL;
}

/* insertion sort */
void insertion_sort(int array[], int size) {
  int i, j, app;
  for (i=1; i<size; i++) {
    app = array[i];
    j = i-1;
    while (j>=0 && array[j]>app) {
      array[j+1] = array[j];
      j--;
    }
    array[j+1] = app;
  }
  return;
}

/* selection sort */
void selection_sort(int array[],int size){
    int i,j,min;
    for (i=0; i<size; i++) {
        min = i;
        for (j=i+1; j<size; j++)
            if (array[min]> array[j])
                min = j;
        if (min != i)
            swap(&array[i],&array[min]);
    }
}

/* bubble sort */
void bubble_sort(int array[], int size) {
    int i,last;
    for (last = size - 1; last > 0; last-- ){
        for (i=0; i<last; i++){
            if (array[i]>array[i+1])
                swap(&array[i],&array[i+1]);
        }
    }
}

/* merge function for merge_sort */
void merge(int array[], int left, int center, int right)
{
  int i = left;                     //index first array
  int j = center+1;                 //index second array
  int k = 0;                        //index new temporary array
  int temp[DIM_ARRAY];              //temporary array

  while ((i<=center) && (j<=right)) {
    if (array[i] <= array[j]) {
      temp[k] = array[i];
      i++;
    }
    else {
      temp[k] = array[j];
      j++;
    }
    k++;
  }

  while (i<=center) {
    temp[k] = array[i];
    i++;
    k++;
  }

  while (j<=right) {
    temp[k] = array[j];
    j++;
    k++;
  }

  //copy
  for (k=left; k<=right; k++){
    array[k] = temp[k-left];
  }
}

/* merge sort */
void merge_sort(int array[], int left, int right) {
  int center; // middle index
  if(left<right) {
     center = (left+right)/2;
     merge_sort(array, left, center);        //sort first half
     merge_sort(array, center+1, right);     //sort first half
     merge(array, left, center, right);      //merge sorted arrays
  }
}

/* partition function for quick_sort */
int partition( int array[], int left, int right) {
   int pivot;   //pivot
   int i;       //index first part
   int j;       //index second part
   int temp;
   pivot = array[left];
   i = left;
   j = right+1;

   while(1){
    do ++i; while( array[i] <= pivot && i <= right );
    do --j; while( array[j] > pivot );
    if( i >= j ) break;
    swap(&array[i],&array[j]);
   }
   swap(&array[left],&array[j]);
   return j;            // index of pivot
}

/* quick sort */
void quick_sort(int array[], int left, int right) {
   int p_index;     // pivot index
   if( left < right ) {
    p_index = partition( array, left, right);
    quick_sort( array, left, p_index-1);
    quick_sort( array, p_index+1, right);
   }
}

/* return 1 if array is sorted */
int testSort(int array[],int size){
    int i,j;
    for (i=0;i<size-1;i++)
        for (j=i+1;j<size;j++)
            if (array[i]>array[j])
                return 0;
    return 1;
}

/* print time difference in seconds and milliseconds */
void printTime(struct timeb start, struct timeb end){
    int sec,mil;
    sec = end.time - start.time;
    mil = end.millitm - start.millitm;
    if (mil < 0) {
        mil += 1000;
        sec--;
    }
    printf("elapsed time %ds %dms\n",sec,mil);
}

void copyArray(int m[], int c[], int n) {
    int i;
    for (i=0;i<n;i++)
        c[i] = m[i];
}

int main(void)
{
    printf("Program start - Array size: %d\n",DIM_ARRAY);
    struct timeb start,end;
    int master[DIM_ARRAY];                  // master array with random valued
    int cp_array[DIM_ARRAY];                // copy of master array
    fillArray(master,DIM_ARRAY);            // fill with random values

    copyArray(master,cp_array,DIM_ARRAY);   // copy master to cp_array
    //printArray(cp_array,DIM_ARRAY);
    ftime(&start);
    insertion_sort(cp_array,DIM_ARRAY);     // insertion sort
    ftime(&end);
    printf("insertion sort ");
    if (! testSort(cp_array,DIM_ARRAY))
       printf("insertion sort error \n");
    else
       printTime(start,end);
    //printArray(cp_array,DIM_ARRAY);

    copyArray(master,cp_array,DIM_ARRAY);   // copy master to cp_array
    //printArray(cp_array,DIM_ARRAY);
    ftime(&start);
    selection_sort(cp_array,DIM_ARRAY);     // selection sort
    ftime(&end);
    printf("selection sort ");
    if (! testSort(cp_array,DIM_ARRAY))
       printf("selection sort error \n");
    else
       printTime(start,end);
    //printArray(cp_array,DIM_ARRAY);

    copyArray(master,cp_array,DIM_ARRAY);   // copy master to cp_array
    //printArray(cp_array,DIM_ARRAY);
    ftime(&start);
    bubble_sort(cp_array,DIM_ARRAY);     // bubble sort
    ftime(&end);
    printf("bubble sort ");
    if (! testSort(cp_array,DIM_ARRAY))
       printf("bubble sort error \n");
    else
       printTime(start,end);
    //printArray(cp_array,DIM_ARRAY);

    copyArray(master,cp_array,DIM_ARRAY);   // copy master to cp_array
    //printArray(cp_array,DIM_ARRAY);
    ftime(&start);
    merge_sort(cp_array,0,DIM_ARRAY-1);     // merge sort
    ftime(&end);
    printf("merge sort ");
    if (! testSort(cp_array,DIM_ARRAY))
       printf("merge sort error \n");
    else
       printTime(start,end);
    //printArray(cp_array,DIM_ARRAY);

    copyArray(master,cp_array,DIM_ARRAY);   // copy master to cp_array
    //printArray(cp_array,DIM_ARRAY);
    ftime(&start);
    quick_sort(cp_array,0,DIM_ARRAY-1);     // quick sort
    ftime(&end);
    printf("quick sort ");
    if (! testSort(cp_array,DIM_ARRAY))
       printf("quick sort error \n");
    else
       printTime(start,end);
    //printArray(cp_array,DIM_ARRAY);

    return 0;
}
