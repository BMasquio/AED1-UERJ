#include <iostream>
using namespace std;

void qualASaida() {
    int *arr;
    int size = 15000;
    int i,j;
    int numberOfNonZeroValues = 0;

    for(i=0;i<20;i++){
    	arr = new int[size];  
    	for(j=0;j<size;j++){
    		if(arr[j] != 0){
    			numberOfNonZeroValues++;
                //cout << "i = " << i << ", arr[" << j << "] = " << arr[j] << endl; 
    		}
    		arr[j] = i*j;
    	}
        delete arr;
    }  

    cout << numberOfNonZeroValues << endl;
}


int main() {
	qualASaida();
	return 0;
}