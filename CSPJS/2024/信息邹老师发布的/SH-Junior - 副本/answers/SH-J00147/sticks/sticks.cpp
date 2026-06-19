#include<bits/stdc++.h>
using namespace std;
int t;
int num[10]={6,2,5,5,4,5,6,3,7,6};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	while(t--){
		int n; cin>>n;
		if(n==1){ cout<<"-1\n"; continue; }
		if(n%7==0){
			while(n){ cout<<8; n-=7; }
			cout<<"\n";
			continue;
		}//特殊性质B
		if(n%7==1){
			cout<<"10";
			n-=8;
			while(n){ cout<<8; n-=7; }
			cout<<"\n";
			continue;
		}//特殊性质A
		if(n<=20){
			int ans[30]={0,-1,1,7,4,2,6,8,10,18,22,20,28,68,88,108,188,228,208,288,688};
			cout<<ans[n]<<"\n";
			continue;
		}//测试点1：打表
		if(n%7==6){
			cout<<6;
			n-=6;
			while(n){ cout<<8; n-=7; }
			cout<<"\n";
			continue;
		}
		if(n%7==5){
			cout<<2;
			n-=5;
			while(n){ cout<<8; n-=7; }
			cout<<"\n";
			continue;
		}
		if(n%7==3){
			cout<<"22";
			n-=10;
			while(n){ cout<<8; n-=7; }
			cout<<"\n";
			continue;
		}
		if(n%7==4){
			cout<<"20";
			n-=11;
			while(n){ cout<<8; n-=7; }
			cout<<"\n";
			continue;
		}
		if(n%7==2){
			cout<<"1";
			n-=2;
			while(n){ cout<<8; n-=7; }
			cout<<"\n";
			continue;
		}
	}
	return 0;
}
