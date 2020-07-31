#include<iostream>
using namespace std;
int main(){
	int n;
	long int temp=1;
	cout<<"Enter a number to find factorial\n";
	cin>>n;
	for(int i=0;i<n;i++){
		temp*=n;
		--n;
	}
	cout<<"Factorial : "<<temp<<endl;
	return 0;
}
