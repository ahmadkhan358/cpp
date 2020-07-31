#include<iostream>
#include<vector>

using namespace std;

int buySellStock(int values[], int size){
	int lowestValue = values[0];
	int indexOfLowestValue = 0;
	
	for(int i=1; i<size; i++){
		if(values[i] < lowestValue){
			lowestValue = values[i];
			indexOfLowestValue = i;
		}
	}
	
	int highestValue = indexOfLowestValue + 1;
	
	if(indexOfLowestValue == size-1){
		return 0;
	}
	
	for(int j = indexOfLowestValue + 1; j<size; j++){
		if(values[j] > highestValue){
			highestValue = values[j];
		}
	}
	
	return highestValue - lowestValue;
}

int main(){
	int stocks[] = {7, 3, 9, 4, 6, 1};
	
	int size = sizeof(stocks)/sizeof(int);
	
	cout<<"Max Profit : "<<buySellStock(stocks, size);
	return 0;
}
