// binary search.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;


//void sort(int* arr, int n);                       //simple sort
void bubbleSort(int *array, int n);               //bubble sort  
void selectionSort(int list[], int length);       //selection sort
void print(int* a, int n);
void binarySearch(int arr[], int num, int size);


int main()
{
	int i, size, target;
	cout << "******************binary search******************" << endl<<endl;
	cout << "enter a size of the array: ";
    cin >> size;
	int *arr = new int[size];          //dynamic array alloacation
	//int arr[500];                    //simple array allocation
	
	cout<<endl << "enter an array: ";             //input of an array elments
	for (i = 0; i < size; i++) {
		cin >> arr[i];
	}
	//sort(arr, size);                   // simple sort of array
	//bubbleSort(arr, size);               //bubble sort of array
	selectionSort(arr, size);
	cout << endl << "**************************************************";
	cout << endl << "sorted array is: " << endl;             //sorted array output
	print(arr, size);
	cout << endl << "**************************************************";
	cout <<endl<< "enter a number which you want to search: ";
	cin >> target;
	binarySearch(arr, target, size);

	delete[] arr;
	return 0;
}

//sorting
void sort(int* arr, int n) {
	int i, j, temp;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

//bubble sort
void bubbleSort(int *array, int n)                     
{
	bool swapped = true;
	int j = 0;
	int temp;

	while (swapped)
	{
		swapped = false;
		j++;
		for (int i = 0; i < n - j; ++i)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				swapped = true;
			}
		}
	}
}


void selectionSort(int list[], int length) {
	int index;
	int smallestIndex;
	int location;
	int temp;

	for (index = 0; index < length - 1; ++index) {
		// step a (find smallest element)
		smallestIndex = index;
		for (location = index + 1; location < length; ++location) {
			if (list[location] < list[smallestIndex]) {
				smallestIndex = location;
			}
		}
		// step b (swap elements)
		temp = list[smallestIndex];
		list[smallestIndex] = list[index];
		list[index] = temp;
	}
}

//binary search
void binarySearch(int arr[], int num ,int size) {
	int mid, lower = 0, upper = size - 1;
	
	while (lower <= upper) {
		mid = (lower + upper) / 2;

		if (arr[mid] == num) {
			cout <<endl<< "The value is found.\nThe index is: " << mid+1 <<endl<< "value is: " << arr[mid] << endl;
			break;
		}
		else if (arr[mid] < num) {
			lower = mid + 1;
		}
		else {
			upper = mid - 1;
		}
	}

	if (lower > upper) {
		cout <<endl<< "The value is not found." << endl<<endl;
	}

}


//print array function
void print(int* a, int n) {
	int i;
	for (i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}


