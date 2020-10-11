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

	void selection_sort(int *arr, size_t n){
		for(int curr = 0; curr < n - 1 ; ++curr){
			int smallest = curr;
			for(int i = curr+1 ; i < n ; ++i){
				if(arr[i] < arr[smallest])
					smallest = i;
			}
			swap(arr+curr, arr+smallest);
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
	sorting.selection_sort(arr, n);

	for(int i = 0 ; i < n ; i++){
			cout << arr[i] << " ";
	}
	cout << " " << endl;

	return 0;
}