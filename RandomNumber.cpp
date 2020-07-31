#include<iostream>
#include<cstdlib>
using namespace std;
int main(){
	int rnd;
	for(int i=0;i<10;i++){
	rnd=(rand()%6)+1;
	cout<<rnd<<endl;
 	}
	return 0;
}
