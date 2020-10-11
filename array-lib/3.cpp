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