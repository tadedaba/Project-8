/*
	This is the implementation file.
	it contains all the function implementations.
*/
#include <iostream>
#include "sort.h"
using namespace std; 
// to swap the array elements for quicksort.
void Sort::swap(int* a, int* b){
	int t = *a;
	*a = *b;
	*b = t;
}
//print array
void Sort::printArray(int a[], int p){
	int t = 0;
	int n = 0;
	int j;
	int k;
	for(k = 0; k < p; k++){
		t++;
		for(j = 0; j < 20; j++){	//only 20 elemnt on a line.
			cout << a[n++] << " ";
			if(n == p)				// exit if all array element read
				break;
		}
		k = j*t;
		cout<<endl;
		if(n == p)
			break;
	}			
}
void Sort::insertion_sort(int b[], int n){
	++count1;
	if(n <= 1)
		return;
		insertion_sort(b, n-1);		//recursive call
		int last = b[n-1];
		int j = n-2;
		while(j >= 0 && b[j] > last){	
			b[j+1] = b[j];
			j--;
		}
		b[j+1] = last;
}
void Sort::merge(int arr[], int low, int mid, int high){
	int i1, i2, index;
	i1 = low;	
	i2 = mid + 1;
	int b[high - low + 1];		// local array 
	index = 0;	
	for(int i = low; i <= high; i++){
		if(i1 > mid)
			b[index++] = arr[i2++];
		else if(i2 > high)
			b[index++] = arr[i1++];
		else if(arr[i1] < arr[i2])
			b[index++] = arr[i1++];
		else
			b[index++] = arr[i2++];
	}
	for(int k = 0; k < index; k++)
		arr[low++] = b[k];
}
void Sort::merge_sort(int arr[], int low, int high){
	int mid;
	++count2;
	if(low < high){
		mid = (low + high)/2;
		merge_sort(arr, low, mid);
		merge_sort(arr, mid + 1, high);
		merge(arr, low, mid, high);
	}
}
void Sort::quick_sort(int a[], int low, int high){
	++count3;
	if(low < high){
		int p_pos = partition(a, low, high);	//get the pivot
		quick_sort(a, low, p_pos-1);
		quick_sort(a, p_pos+1, high);
	}
}
int Sort::partition(int a[], int low, int high){
	Sort S;
	int start = low + 1;	//start at the second element
	int pivot = a[low];   //make the first element a pivot
	for(int k = low+1; k <= high; k++){
		if(a[k] < pivot)
			S.swap(&a[start++], &a[k]);
	}
	S.swap(&a[low], &a[start-1]);
	return start-1;	//current location of pivot
}
