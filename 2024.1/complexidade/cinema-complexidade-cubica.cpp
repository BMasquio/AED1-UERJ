#include <iostream>
using namespace std;

int main() {
	int rows = 11;
	int collumns = 11;
	
	int M[rows][collumns] = 
	{{0,0,0,0,0,0,0,0,0,0,0},
	{0,0,1,2,2,2,2,3,3,4,4},
	{0,1,3,4,5,5,6,7,8,10,11},
	{0,1,4,5,7,7,9,11,12,14,15},
	{0,2,5,6,8,9,11,13,15,18,20},
	{0,2,5,6,8,9,12,14,16,19,21},
	{0,2,5,6,8,10,13,15,17,20,23},
	{0,3,7,8,11,13,17,19,22,25,28},
	{0,3,7,8,11,13,18,20,23,26,30},
	{0,4,9,11,15,18,23,26,30,33,37},
	{0,4,10,12,16,19,25,27,33,36,41}};
	
	int rowI;
	int rowF;
	
	int c = 8;
	int minArea = M[rows-1][collumns-1]+1;
	
	for(rowI=1;rowI<rows;rowI++){
		for(rowF=1;rowF<rows;rowF++){
			//cout << "rowI = " << rowI << ", rowF = " << rowF << endl;
			int i = 1;
			int j = 1;
			int currentArea = -1;
			int currentSeats = -1;
			while(i<collumns && j<collumns){
				while(currentSeats < c && j < collumns){
					currentSeats = M[rowI-1][i-1]+M[rowF][j]-M[rowF][i-1]-M[rowI-1][j];
					currentArea = (j-i+1)*(rowF-rowI+1);
					//cout << "rowI = " << rowI << ", rowF = " << rowF << ", i = " << i << ", j = " << j << ", currentSeats = " << currentSeats << ", currentArea = " << currentArea << endl;
					j++;
				}
				if(j == collumns) break;
				
				//cout << "rowI = " << rowI << ", rowF = " << rowF << ", i = " << i << ", j = " << j << ", currentSeats = " << currentSeats << ", currentArea = " << currentArea << endl;
				if(currentArea < minArea){
					minArea = currentArea;
					cout << "Melhor área encontrada" << endl;
					cout << "linha inicial = " << rowI << ", linha final = " << rowF << ", coluna inicial = " << i << ", coluna final = " << j-1 << ", assentos disponíveis = " << currentSeats << ", área = " << currentArea << endl;
				}
				
				
				i++;
				currentSeats = M[rowI-1][i-1]+M[rowF][j]-M[rowF][i-1]-M[rowI-1][j];
				currentArea = (j-i+1)*(rowF-rowI+1);
			}
		}
	}
	
	cout << minArea << endl;
	
	
	return 0;
}