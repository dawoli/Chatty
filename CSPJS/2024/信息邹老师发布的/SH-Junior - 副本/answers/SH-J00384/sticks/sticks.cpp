#include<bits/stdc++.h>
using namespace std;
const int sticks[7]={6,2,5,4,6,3,7};
const char numbers[7]={0,1,2,4,6,7,8};
int array[100]={-1,-1,7,4,2,10,18,23};
int T;
int n,w;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		if(n<2){
			cout<<-1<<endl;
			continue;
		}
		if(n%7==0){
			for(int i=0;i<n/7;i++)
				cout<<'8';
			cout<<endl;
			continue;
		}else if(n%7==1){
			cout<<"10";
			for(int i=0;i<n/7-1;i++)
				cout<<'8';
			cout<<endl;
			continue;
		}else if(n%7==2){
			cout<<'1';
			for(int i=0;i<n/7;i++)
				cout<<'8';
			cout<<endl;
			continue;	
		}else if(n%7==3){
			if(n==3) cout<<3<<endl;
			else if(n==10) cout<<22<<endl;
			else{
				cout<<"200";
				for(int i=0;i<n/7-2;i++)
					cout<<'8';
				cout<<endl;
			}
			continue;
		}else if(n%7==4){
			if(n==4) cout<<4<<endl;
			else{
				cout<<"20";
				for(int i=0;i<n/7-1;i++)
					cout<<'8';
				cout<<endl;
			}
			continue;
		}else if(n%7==5){
			cout<<'2';
			for(int i=0;i<n/7;i++)
				cout<<'8';
			cout<<endl;
			continue;
		}else if(n%7==6){
			cout<<'6';
			for(int i=0;i<n/7;i++){
				cout<<8;
			}
			cout<<endl;
			continue;
		}
	}
	return 0;
}
