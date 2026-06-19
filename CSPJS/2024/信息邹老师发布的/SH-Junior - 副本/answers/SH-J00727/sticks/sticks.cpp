#include<iostream>
#include<cmath>
using namespace std;
int main(){
	freopen("sticks.in","r",fin);
	freopen("sticks.out","w",fout);
	int w[13]={6,2,5,5,4,5,6,3,7,6}
	int t;
	double n;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		if(n<2){
			cout<<-1<<endl;
		}
		else{
			int q=ceil(n/7);
			int r=q*7-n;
			if(r==0){
				for(int i=0;i<q;i++){
					cout<<"8";
				}
				cout<<endl;
			}else if(r==1){
				cout<<"6";
				for(int i=1;i<q;i++){
					cout<<"8";
				}
				cout<<endl;
			}else if(r==2){
				cout<<"2";
				for(int i=1;i<q;i++){
					cout<<"8";
				}
				cout<<endl;
			}else if(r==3){
				if(q==1){
					cout<<4<<endl;
				}else{
					cout<<"20";
				    for(int i=2;i<q;i++){
					    cout<<"8";
				    }
				}
				cout<<endl;
			}else if(r==4){
				if(q==1){
					cout<<"7"<<endl;
				}else{
					cout<<"22";
					for(int i=2;i<q;i++){
					    cout<<"8";
				    }
				}
				cout<<endl;
			}else if(r==5){
				cout<<"1";
				for(int i=1;i<q;i++){
					cout<<"8";
				}
			}else{
				cout<<"12";
				for(int i=2;i<q;i++){
					cout<<"8";
				}
			}
		}
	}
	return 0;
} 
