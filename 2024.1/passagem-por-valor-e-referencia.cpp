#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> &v) 
{ 
	int i;
	for(i=0;i<v.size();i++){
		cout << v[i] << " ";
	}
	cout << endl;
}
//pass by value 
void addPassingByValue(vector<int> v, int b) 
{ 
	int i;
	for(i=0;i<v.size();i++){
		v[i] += b;
	}
	
	cout << "V dentro da função addPassingByValue(v,2)" << endl;
	print(v);
} 
 
//pass by reference 
void addPassingByReference(vector<int> &v, int b) 
{ 
	int i;
	for(i=0;i<v.size();i++){
		v[i] += b;
	}
	
	cout << "V dentro da função addPassingByReference(v,3)" << endl;
	print(v);
} 

int main() { 
	vector<int> v = {1,2,3};
	
	cout << "V incial" << endl;
	print(v);
	addPassingByValue(v,2); 
	
	cout << "V após a função addPassingByValue(v,2)" << endl;
	print(v);
	
	addPassingByReference(v,3); 
	
	cout << "V após a função addPassingByReference(v,3)" << endl;
	print(v);
	
	return 0; 
} 