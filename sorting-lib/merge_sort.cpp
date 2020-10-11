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

	void merge(int *arr, int low, int mid, int high){
		
		int barr[n];
		int i = low;
		int j = mid + 1;
		int k = low;

		while(i <= mid && j <= high){
			if(arr[i] <= arr[j]){
				barr[k++] = arr[i++];
			}
			else{
				barr[k++] = arr[j++];	
			}
		}
		while(i <= mid){
			barr[k++] = arr[i++];
		}
		while(j <= high){
			barr[k++] = arr[j++];	
		}
		for(i = low; i <= high; i++){
			arr[i] = barr[i];
		}
	}

	void merge_sort(int *arr, size_t low, size_t high){
		if(low < high){
			int mid = (low + high)/2;
			merge_sort(arr, low, mid);
			merge_sort(arr, mid+1, high);
			merge(arr, low, mid, high);
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
	sorting.merge_sort(arr, 0, n-1);
	
	for(int i = 0 ; i < n ; i++){
			cout << arr[i] << " ";
	}
	cout << " " << endl;

	return 0;
}