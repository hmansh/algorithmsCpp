#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;


class percolations{

    size_t rows, columns;

    int root(int i){
        while(i != arr[i]) i = arr[i];
        return i;
    }


    percolations(size_t rows, size_t columns){
        
        this->rows = rows;
        this->columns = columns;

        int **arr = new int*[rows+2];
        for(int i = 1 ; i < rows + 1 ; ++i){
            arr[i] = new int[columns];
            for (int k = 0 ; k < columns ; ++k)
                arr[i][k] = i+j;
        }
    }

    bool unionJoin(int a, int b){
        int p = root(a);
        int q = root(b);
        
    }


};

int main(){

}

