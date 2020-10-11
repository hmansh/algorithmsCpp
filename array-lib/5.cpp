#include <iostream>
#include <vector>
#include <ctime>
#define NINF -9999999999;
#define PINF 9999999999;
using namespace std;

class Array{
private:
	size_t n;
	int *arr;
	int *reverse;
	int *oddeven;
	int *prevNextMul_;
	int max = NINF;
	int min = PINF;
	int secMax = max;
	int secMin = min;
	std::pair<int, int> minmax;
public:
	Array(int n){
		this->n = n;
		arr = new int[n];
		for(int i = 0 ; i < n ; ++i){
			arr[i] = rand()/100;
		}
		pair.first = NINF;
		pair.second = PINF;
	}
	int max(){};
	int min(){};
	int secondMax(){};
	int secondMin(){};
	void oddEven(){};
	std::pair<int, int> maxmin(){};
	int reverse(){};
	int search(int key){};
	void prevNextMul(){};
	void printRange(int key1, int key2){};
};

int Array::search(int key){
	index = 0;
	for(int i : arr){
		if (i == key) {
			return index;
		}
		index++;
	}
}

void Array::printRange(int key1, int key2){
	id1 = arr.search(key1);
	id2 = arr.search(key2);
	if (id1 > id2){
		cout << 'index not in proper range';
		return;
	}
	while(id1!=id2){
		cout << arr[id1++] << " ";
	}
	cout << endl;
}

int Array::secondMax(){
	for(int a : arr){
		if(a < max && a > secMax){
			secMax = a;
		}
	}
	return secMax;
}

int Array::secMin(){
	for(int a : arr){
		if(a > min && a < secMin){
			secMin = a;
		}
	}
	return secMin;
}


void Array::oddEven(){
	oddeven = new int[n];
	int i = 0;
	for(int a : arr){
		if (a%2 == 0){
			oddeven[i++] = a;
		}
	}
	for(int a : arr){
		if (a%2 != 0){
			oddeven[i++] = a;
		}	
	}
}

void Array::prevNextMul(){
	int i = 0;
	prevNextMul_ = new int[n];
	prevNextMul_[i] = arr[i+1];
	for (i = 1 ; i < n-1 ; i++){
		prevNextMul_[i] = arr[i+1]*arr[i-1];
	}
	prevNextMul_[i] = arr[i-1];
}



