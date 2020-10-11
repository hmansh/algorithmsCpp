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

	void intertion_sort(int *arr, size_t n){
		for(int i = 1 ; i < n ; ++i){
			int key = arr[i];
			int j = i - 1;
			while(j >= 0 && key < arr[j]){
				arr[j+1] = arr[j];
				j--;
			}
			arr[j+1] = key;
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
	sorting.intertion_sort(arr, n);

	for(int i = 0 ; i < n ; i++){
			cout << arr[i] << " ";
	}
	cout << " " << endl;

	return 0;
}