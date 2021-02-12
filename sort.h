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
		int counter1(){return count1-1;}	//returns the number of insertion sort counts.
		int counter2(){return count2-1;}	//returns the number of merge sort counts.
		int counter3(){return count3-1;}	//returns the number of quicksort counts.
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
