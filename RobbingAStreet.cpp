#include<iostream>
#include<vector>

using namespace std;

int rob(vector<int>& num){
	int robbedMoney = 0;
	for(int i=0; i<num.size(); i+=2){
		if(num[i] > 0){
			robbedMoney += num[i];
		}
	}
	
	return robbedMoney;
}

int main(){
	vector<int> moneyInHouses;
	moneyInHouses.push_back(10);
	moneyInHouses.push_back(14);
	moneyInHouses.push_back(5);
	moneyInHouses.push_back(14);
	
	
	cout<<"Total robbed money "<<rob(moneyInHouses)<<endl;
	
	return 0;
}
