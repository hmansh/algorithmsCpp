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
	int max = NINF;
	int min = PINF;
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
	std::pair<int, int> maxmin(){};
	int reverse(){};
	int search(int key){};
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