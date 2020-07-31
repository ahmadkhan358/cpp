#include <iostream>
#include<string>
using namespace std;
class MoreInfo{
	public:
		int MP;
		string Owner;
};
class BatteryPerformance{
	public:
		double hours;
};
class Mobiles{
	public:
		string Name;
		string Model;
		static int arr[10];
		Mobiles():Name("No name"), Model("No model"){}
		Mobiles(string name):Name(name),Model("No model"){}
		Mobiles(string name, string model){
			MblName(name);
			MblModel(model);
		}
		void virtual mblModel(){
			cout<<Name<<" has a model number "<<Model<<endl;
		}
		void MblName(string n){
			for(int i=0;i<n.length();i++){
				for(int j=0;j<10;j++){
					if(n[i]==arr[j]){
						Name="No name";
						cout<<"Name can't contain numbers"<<endl;
					}
				}
			}
			Name=n;
		}	
		void MblModel(string m){
			if(m.length()>9){
				Model="No model";
				cout<<"Model number must be less than 9 characters"<<endl;
			}
			Model=m;
		}
		MoreInfo* mrin=new MoreInfo;
		void SetMoreInfo(int mp,string owner){
			mrin->MP=mp;
			mrin->Owner=owner;
		}
		void GetMoreInfo(){
			cout<<Name<<" "<<Model<<" has "<<mrin->MP<<" mega pixels camera and it is owned by "<<mrin->Owner<<endl;
		}
		BatteryPerformance* btryPer=new BatteryPerformance;
		void CheckBattery(double h){
			btryPer->hours=h;
			if(h>=1 && h<=3){
				cout<<"Your battery performance is "<<btryPer->hours<<" hour(s) and it is very bad"<<endl;
			}
			else if(h>=4 && h<=6){
				cout<<"Your battery performance is "<<btryPer->hours<<" hour(s) and it is bad"<<endl;
			}
			else if(h>=7 && h<=9){
				cout<<"Your battery performance is "<<btryPer->hours<<" hour(s) and it is good"<<endl;
			}
			else if(h>=10 && h<=12){
				cout<<"Your battery performance is "<<btryPer->hours<<" hour(s) and it is better"<<endl;
			}
			else if(h>=13 && h<=15){
				cout<<"Your battery performance is "<<btryPer->hours<<" hour(s) and it is best"<<endl;
			}
			else{
				cout<<"Wrong input"<<endl;
			}
		}
		~Mobiles(){
			delete mrin;
			delete btryPer;
		}	
};
int Mobiles::arr[10]={0,1,2,3,4,5,6,7,8,9};
class Samsung:public Mobiles{
	public:
		string Galaxy;
		Samsung(string n="No name",string g="No galaxy",string m="No model"){
			Mobiles::Name=n;
			Mobiles::Model=m;
			Galaxy=g;
		}
			void mblModel(){
			cout<<Mobiles::Name<<" "<<Galaxy<<" has a model number "<<Mobiles::Model<<endl;	
		}
};
int main(int argc, char** argv) {
	Mobiles* newMbl= new Mobiles("Huawei","LA123");
	newMbl->mblModel();
	newMbl->SetMoreInfo(8,"Aqib Khan");
	newMbl->GetMoreInfo();
	newMbl->CheckBattery(9);
	Samsung* samMbl= new Samsung("Samsung","Galaxy S7 Edge","SMG935F");
	samMbl->mblModel();
	samMbl->SetMoreInfo(12,"Ahmad Khan");
	samMbl->GetMoreInfo(); 
	samMbl->CheckBattery(13);
	Mobiles* newMbl2=new Mobiles("HTC","DES626S");
	newMbl2->mblModel();
	Mobiles* samMbl2=new Samsung("Samsung","Galaxy S6","SMG920F");
	samMbl2->mblModel();
	delete newMbl;
	delete samMbl;
	delete newMbl2;
	delete samMbl2;
	return 0;
}
