#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;

class uf{
private:
	int length;
	int *arr;
public:
	uf(int N){
		 this->arr = new int[N];
		 this->length = N;
         for(int i = 0; i < this->length ; i++)
            *(arr + i) = i;
	}
	
	bool isConnected(int p, int q){
		return *(this->arr + p) == *(this->arr + q);
	}
	
	bool unionConnect(int p, int q){
		int pid = *(arr + p);
		int qid = *(arr + q);
		for(int i  = 0; i < this->length; i++){
			if (*(arr + i) == pid ) {
                *(arr + i) = qid;
            }
		}
        return true;
	}
};

int main(){
    int x = 10;
	uf array(x);
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
					array.unionConnect(a ,b);
                    cout << "Connected "<< endl;
				}
				else cout << "Already Connected" << endl;
				break;
			default :
				break;
		}
		
	}
}
