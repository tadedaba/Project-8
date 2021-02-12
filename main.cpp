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

