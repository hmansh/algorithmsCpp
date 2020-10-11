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
};

int Array::max(){
	this->max = NINF;
	i = 0;
	while(i!=n){
		if (arr[i] > max){
			max = arr[i];
		}
	i++;
	}
	return max;
}

int Array::min(){
	int i = 0;
	while(i != n){
		if (arr[i] < min){
			min = arr[i];
		}
	}
	return min;
}

std::pair<int, int> Array::maxmin(){
	for(int i : arr){
		if (i > pair.first){
			pair.first = i;
		}
		if (i < pair.second){
			pair.second = i;
		}
	}
	return pair;
}

int main(){
	Array a(10);
	cout << a.min() << endl;
	cout << a.max() << endl;
	cout << a.maxmin() << endl;
	aa.reve
	return 0;
}