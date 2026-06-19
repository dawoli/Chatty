#include<bits/stdc++.h>
using namespace std;
long long n,t;
long long f[100007];
int nu[10]={0,0,1,7,4,2,6,8},num[10]={6,2,5,5,4,5,6,3,7,6};
struct no{
	long long numm;
	bool operator<(const no &c)const{
		return numm>c.numm;
	}
};
priority_queue<no> p;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	f[1]=-1;
	for(long long i=2;i<=7;i++) f[i]=nu[i];
	for(long long i=1;i<=t;i++){
		cin>>n;
		if(n<=7){
			cout<<f[n]<<endl;
		}else if(n%7==0){
			for(int j=1;j<=n/7;j++) cout<<8;
			cout<<endl;
		}else if(n%7==1){
			cout<<"10";
			for(int j=1;j<n/7;j++) cout<<8;
			cout<<endl;
		}else if(n%7==2){
			cout<<"1";
			for(int j=1;j<=n/7;j++) cout<<8;
			cout<<endl;
		}else if(n%7==3){
			cout<<"22";
			for(int j=1;j<n/7;j++) cout<<8;
			cout<<endl;
		}else if(n%7==4){
			cout<<"20";
			for(int j=1;j<n/7;j++) cout<<8;
			cout<<endl;
		}else if(n%7==5){
			cout<<"2";
			for(int j=1;j<=n/7;j++) cout<<8;
			cout<<endl;
		}else if(n%7==6){
			cout<<"6";
			for(int j=1;j<=n/7;j++) cout<<8;
			cout<<endl;
		}
	}
	return 0;
}
