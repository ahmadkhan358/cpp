#include<iostream>
using namespace std;
int main(){
	int arr[6] = {12,5,4,-2,8,9};
	int arr2[2] = {0,0};
	int temp=0;
	
	for(int i=0;i<5;i++){
		temp = arr[0] + arr[i+1];
		if(temp == 10){
			arr2[0] = arr[0];
			arr2[1] = arr[i+1];
			cout<<arr2[0]<<" + "<<arr2[1]<<" = 10"<<endl;
			break;
		}
		else{
			temp=0;
		}
	}
	return 0;
}
