#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		if(n==1)cout<<-1<<endl;
		else if(n==2)cout<<1<<endl;
		else if(n==3)cout<<7<<endl;
		else if(n==4)cout<<4<<endl;
		else if(n==5)cout<<2<<endl;
		else if(n==6)cout<<6<<endl;
		else{
			int k=n/7;
			n%=7;
			if(n==0){
				for(int i=1;i<=k;i++)cout<<"8";
				cout<<endl;
			}
			if(n==1){
				cout<<"10";
				for(int i=1;i<k;i++)cout<<"8";
				cout<<endl;
			}
			if(n==2){
				cout<<"1";
				for(int i=1;i<=k;i++)cout<<"8";
				cout<<endl;
			}
			if(n==3){
				if(k==1)cout<<"22";
				else{
					cout<<"200";
					for(int i=2;i<k;i++)cout<<"8";
				}
				cout<<endl;
			}
			if(n==4){
				cout<<"20";
				for(int i=1;i<k;i++)cout<<"8";
				cout<<endl; 
			}
			if(n==5){
				cout<<"2"; 
				for(int i=1;i<=k;i++)cout<<"8";
				cout<<endl;
			}
			if(n==6){
				cout<<"6";
				for(int i=1;i<=k;i++)cout<<"8";
				cout<<endl;
			}
		}
	}
	return 0;
} 
