
/*
	This is the header file. It contains the class "sort" that hosts 
	the various public functions and three private objects. 
		=> The public functions perform different operations 
			as specified in the implimentation file. 
		=> The three private objects hold the counters to count the 
			number of recursive function calls for the three sorting.
			algorithms. 
	Precondition: - The program works for integer sorting on a randomly  
					generated integer numbers. 
	Postcondition: - The program will sort the array using insertion sort,
					 merge sort, and quicksort algorthms. It also reports the 
					 number of recursive calls for each sorting algoriths. 
*/
#include <iostream>
#ifndef _SORT
#define _SORT
using namespace std; 
class Sort{				
	private:				 
		int count1;	//the number of insertion sort operation counts 
		int count2;	//the number of merge sort  operation counts
		int count3;	//the number of quicksort operation counts
	public:
		int counter1(){return count1;}	//returns the number of insertion sort counts.
		int counter2(){return count2;}	//returns the number of merge sort counts.
		int counter3(){return count3;}	//returns the number of quicksort counts.
		void resetCounter(){
			count1 = 0;count2 = 0;count3 = 0;}	//function initializes counters to 0
		void printArray(int [], int);		// to print the array
		void insertion_sort(int [], int);	
		void merge(int [], int, int, int); 	
		void merge_sort(int [], int, int); 
		int partition(int [], int, int);		
		void quick_sort(int [], int, int);
		void swap(int*, int*);				// to swap the array elements. 
};
#endif

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

/*
	This is the main method. it promotes the user to enter inputs,
	it tests the implementations, and prints the outputs. 
*/
#include <iostream> 
#include <cstdlib>
#include "sort.cpp"
#include <cmath>
using namespace std; 
static const int MAX = 5000;
int num;
int main(int argc, const char * argv[]){
	int num1, num2, num3;
	int arr[MAX];
	int a[MAX];
	int ar[MAX];
	int seed;
	char ch;
	cout << " This program will sort an array of random numbers\n"
		 << " and return the the program execution time for merge\n"
		 << " and quick sorts."<< endl;
	cout << " =================================================="<<endl;
	cout << " You must enter a number between 1 to 5000."<<endl;
	cout << " Enter the number of values you want to generate: ";
	cin >> num;
	cout << " Enter an integer seed value: ";
	cin >> seed;
	srand(seed);
	Sort S;
	S.resetCounter();
	for(int i = 0; i < num; i++){
		a[i] = (rand()%num);
		ar[i] = a[i];
		arr[i] = a[i];
	}
	cout << " Your array is sorted successfully."<<endl;
	cout << " Do you wish to print the values? (y/n): ";
	cin >> ch;
	if(ch == 'y'|| ch == 'Y'){
		cout << " \nUnsorted array: "<<endl;
		cout << " =============="<<endl;
		S.printArray(a, num);
		
		S.insertion_sort(a, num);
		cout << "\nArray sorted by insertion sort."<<endl;
		cout << "================================"<<endl;
		S.printArray(a, num);
		
		S.merge_sort(ar, 0, num-1);
		cout << "\nArray sorted by merge sort."<<endl;
		cout << "============================="<<endl;
		S.printArray(a, num);
		
		S.quick_sort(arr, 0, num-1);
		cout << "\nArray sorted by quick sort."<<endl;
		cout << "============================="<<endl;
		S.printArray(a, num);
	}
	else if(ch == 'n'|| ch == 'N'){
		S.insertion_sort(a, num);
		num1 = S.counter1();
		int exc = pow((num1/2), 2);
		cout << " Insertion sort count: "<< exc<<endl;
		
		S.merge_sort(ar, 0, num);
		num2 = S.counter2();
		int ex = num2*log(num2);
		cout << " Merge sort count: "<< ex<<endl;
		
		S.quick_sort(arr, 0, num);
		num3 = S.counter3();
		int e = num3*log(num3);
		cout << " Quick sort count: "<< e<<endl;
	}
	else{
		cout << " The choice is unavailable."<<endl;
		cout << " Run the program again and make the right choice."<<endl;
	}	
	return 0;
}


 This program will sort an array of random numbers
 and return the the program execution time for merge
 and quick sorts.
 ==================================================
 You must enter a number between 1 to 5000.
 Enter the number of values you want to generate: 980
 Enter an integer seed value: 23
 Your array is sorted successfully.
 Do you wish to print the values? (y/n): n
 Insertion sort count: 239121
 Merge sort count: 14858
 Quick sort count: 9566

--------------------------------
Process exited after 25.03 seconds with return value 0
Press any key to continue . . .


 This program will sort an array of random numbers
 and return the the program execution time for merge
 and quick sorts.
 ==================================================
 You must enter a number between 1 to 5000.
 Enter the number of values you want to generate: 77
 Enter an integer seed value: 5
 Your array is sorted successfully.
 Do you wish to print the values? (y/n): y

Unsorted array:
 ==============
54 49 12 40 17 14 57 16 60 69 32 62 58 74 41 72 28 10 61 76
43 58 8 29 64 56 40 64 49 51 49 38 31 17 15 62 44 10 42 67
53 57 20 32 26 51 64 18 18 42 37 46 29 63 15 66 43 61 64 34
36 65 4 27 46 53 68 20 0 60 60 19 76 28 18 46 13

Array sorted by insertion sort.
================================
0 4 8 10 10 12 13 14 15 15 16 17 17 18 18 18 19 20 20 26
27 28 28 29 29 31 32 32 34 36 37 38 40 40 41 42 42 43 43 44
46 46 46 49 49 49 51 51 53 53 54 56 57 57 58 58 60 60 60 61
61 62 62 63 64 64 64 64 65 66 67 68 69 72 74 76 76

Array sorted by merge sort.
=============================
0 4 8 10 10 12 13 14 15 15 16 17 17 18 18 18 19 20 20 26
27 28 28 29 29 31 32 32 34 36 37 38 40 40 41 42 42 43 43 44
46 46 46 49 49 49 51 51 53 53 54 56 57 57 58 58 60 60 60 61
61 62 62 63 64 64 64 64 65 66 67 68 69 72 74 76 76

Array sorted by quick sort.
=============================
0 4 8 10 10 12 13 14 15 15 16 17 17 18 18 18 19 20 20 26
27 28 28 29 29 31 32 32 34 36 37 38 40 40 41 42 42 43 43 44
46 46 46 49 49 49 51 51 53 53 54 56 57 57 58 58 60 60 60 61
61 62 62 63 64 64 64 64 65 66 67 68 69 72 74 76 76

--------------------------------
Process exited after 6.248 seconds with return value 0
Press any key to continue . . .