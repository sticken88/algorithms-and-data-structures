#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <vector>

using namespace std;

void selection_sort(vector<int> &array, int l, int r);
void insertion_sort(vector<int> &array, int l, int r);
void bubble_sort(vector<int> &array, int l, int r);
void swap(vector<int> &array, int i, int j);
void print_array(vector<int> array);

int main(void){

  vector<int> array = vector<int>(100);

  /* initialize random seed: */
  srand (time(NULL));

  for(int i=0; i<100; i++){  
    array[i] = 100-i;
  }

  //print_array(array);

  //selection_sort(array, 0, 99);
  //insertion_sort(array, 0, 99);
  bubble_sort(array, 0, 99);
  print_array(array);

  return 0;
}


/*
 * Selection sort ordering function
 */
void selection_sort(vector<int> &array, int l, int r){
  int i, j;

  for(i=l; i<r; i++){
    int min = i;
    /* Inner loop to get the minimum */
    for(j=i+1; j<=r; j++){
      if(array[j] < array[min]) min = j;
    }
    /* swap the elements */
    swap(array, i, min);
    /*int tmp = array[i];
    array[i] = array[min];
    array[min] = tmp;*/
  }
}


/*
 * Insewrtion sort ordering function
 */
void insertion_sort(vector<int> &array, int l, int r){
  
  int i, j, tmp;

  /* Put the minimum value in the first position */
  for(i=r; i>l; i--){
    if(array[i] < array[i-1]){
      swap(array, i-1, i);
      /*tmp = array[i-1];
      array[i-1] = array[i];
      array[i] = tmp;*/
    }
  }

  /* Then run the algorithm */
  for(i=l+2; i<=r; i++){
    j = i;
    int val = array[i];

    /* Move right the numbers on the left if needed*/
    while(val < array[j-1]){
      array[j] = array[j-1];
      j--;
    }
    array[j] = val;
  }
}


/*
 * Bubble sort ordering function
 */
void bubble_sort(vector<int> &array, int l, int r){

  int i, j, tmp;
  
  for(i=l; i<r; i++){
    for(j=r; j>i; j--){
      if(array[j] < array[j-1]){
        swap(array, j-1, j);
	/*tmp = array[j-1];
        array[j-1] = array[j];
        array[j] = tmp;*/
      }
    }
  }
}


/*
 * Helper function to swap two data given their indexes
 */
void swap(vector<int> &array, int i, int j){
  int tmp = array[i];
  array[i] = array[j];
  array[j] = tmp;
}


/*
 * Helper function to print out an array
 */
void print_array(vector<int> array){
  for(int i=0; i<array.size(); i++){
    cout << array[i] << endl;
  }
}
