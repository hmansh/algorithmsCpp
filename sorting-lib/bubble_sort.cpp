#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <string>
using namespace std;

int n = 10;

class sort{

public:
	sort(){

	}

	void swap(int *a, int *b){
		int temp = *a;
		*a = *b;
		*b = temp;
	}

	void bubble_sort(int *arr, size_t n){
		for(int i = 0 ; i < n - 1; i++){
			for(int j = 0; j < n - i - 1; j++){
				if (*(arr + j) > *(arr + j + 1)){
					swap((arr + j), (arr+ j + 1 ));
				}
			}
		}
	}

};

int main(){

	int *arr = new int[10];
	int n = 10;

	for(int i = 0 ; i < n ; i++){
		if (i >= n){
			// *arr = new int[1];
		}
		arr[i] = rand()%100;
	}

	for(int i = 0 ; i < n ; i++){
		cout << arr[i] << " ";
	}
	cout << " " << endl;

	sort sorting;

	sorting.bubble_sort(arr, n);

	for(int i = 0 ; i < n ; i++){
			cout << arr[i] << " ";
	}
	cout << " " << endl;

	return 0;
}