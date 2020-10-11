#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;

class quickUnion{
private:
    int *array;
    int length;

    int root(int i){
        while( i != this->array[i] )  i = array[i];
        return i;
    }

public:
    quickUnion(int N){
        this->length = N;
        array  = new int[N];
        for(int i = 0 ; i < this->length ; i++){
            *(array + i) = i;
        }   
    }

    bool isConnected(int p, int q){
        return root(p) == root(q);
    }

    void joinNodes(int p , int q){
        int i = root(p);
        int j = root(q);
        this->array[i] = j;
    }
};


int main(){
    int x = 10;
	quickUnion array(x);
	int choice;
	int a, b;
	while(true){
		cout << "1 to find : \n" << "2 to connect : " << endl;
		cout << "Enter : ";
        cin >> choice;
		switch (choice){
			case 1:
				cout << "Enter the numbers : " ;
				cin >> a >> b;
				cout << array.isConnected(a, b) << endl;
				break;
			case 2:
				cout << "Enter the numbers : " ;
				cin >> a >> b;
				if ( !array.isConnected(a, b) ){
					array.joinNodes(a ,b);
                    cout << "Connected "<< endl;
				}
				else cout << "Already Connected" << endl;
				break;
			default :
				break;
		}
		
	}
}
