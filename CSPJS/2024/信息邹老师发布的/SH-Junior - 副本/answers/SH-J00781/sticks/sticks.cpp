#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1009;
int T;
int Min[8]={-1,-1,1,7,4,2,6,8};
int num[10]={6,2,5,5,4,5,6,3,7,6}; 

void solve(int n){
	int l=(n+6)/7;  
	
	if(l==1){
		if(n==1){
			cout<<"-1"<<endl;
			return ;
		}
		else{
			cout<<Min[n]<<endl;
			return ;
		}
	}
	if(l==2){
		if(n==8){
			cout<<"10"<<endl;
			return ;
		}
		if(n==9){
			cout<<"18"<<endl;
			return ;
		}
		else if(10<=n&&n<=12){
			if(n==11){
				cout<<"20"<<endl;
			}
			else{
				cout<<'2'<<Min[n-5]<<endl;
			}
			return ;
		}
		else{
			if(n==13){
				cout<<"68"<<endl;
			}
			if(n==14){
				cout<<"88"<<endl;
			}
			return ;
		}
	}
	
	if((n-2)<=7*(l-1)){
		cout<<1;
		int n0=n-2,l0=l-1;
		int r0=7*l0-n0,r8=n0-6*(l0);
		for(int i=1;i<=r0;i++){
			cout<<0;
		}
		for(int i=1;i<=r8;i++){
			cout<<'8';
		}
		cout<<endl;
		return ;
	}
	else if((n-5)<=7*(l-1)){
		cout<<2;   
		int n0=n-5,l0=l-1;
		int r0=7*l0-n0,r8=n0-6*(l0);
		for(int i=1;i<=r0;i++){
			cout<<0;
		}
		for(int i=1;i<=r8;i++){
			cout<<'8';
		}
		cout<<endl;
		return ;
	}
	return ;
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	for(int U=1;U<=T;U++){
		int n;
		cin>>n;
		solve(n);
	}
	return 0;
}
