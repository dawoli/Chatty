#include<iostream>
#include<cstring>
using namespace std;
int l[10]={6,2,5,5,4,5,6,3,7,6};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int n,x;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x;
		if(x==1){
			cout<<-1<<endl;
		}
		else if(x%7==0){
			for(int i=0;i<x/7;i++){
				cout<<8;
			}
			cout<<endl;
		}
		else if(x%7==1){
			cout<<10;
			for(int i=0;i<(x-8)/7;i++){
				cout<<8;
			}
			cout<<endl;
		}
		else if(x%7==2){
			cout<<1;
			for(int i=0;i<(x-2)/7;i++){
				cout<<8;
			}
			cout<<endl;
		}
		else if(x%7==3){
			cout<<200;
			for(int i=0;i<(x-17)/7;i++){
				cout<<8;
			}
			cout<<endl;
		}
		else if(x%7==4){
			cout<<20;
			for(int i=0;i<(x-11)/7;i++){
				cout<<8;
			}
			cout<<endl;
		}
		else if(x%7==5){
			cout<<2;
			for(int i=0;i<(x-5)/7;i++){
				cout<<8;
			}
			cout<<endl;
		}
		else if(x%7==6){
			cout<<6;
			for(int i=0;i<(x-6)/7;i++){
				cout<<8;
			}
			cout<<endl;
		}
		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
