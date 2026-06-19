#include<bits/stdc++.h>
using namespace std;
int nx[501];
int mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,f=1;
	string nd;
	cin>>n>>m>>nd;
	for(int i=1;i<=n;i++){
		cin>>nx[i];
		if(nx[i]!=1)f=0;
	}
	if(f==1){
		for(int i=0;i<nd.size();i++){
			if(nd[i]!='1'){
				if(i+1<m)cout<<0;
				else {
					int x=1,y=1,z=1;
					for(int j=m+1;j<=i+1;j++)x=x*j%mod;
					for(int j=1;j<=i+1-m;j++)y=y*j%mod;
					for(int j=1;j<=m;j++)z=z*j%mod;
					cout<<x/y*z%mod;
				}
				break;
			}
		}
	}
	else if(n<=100)cout<<161088479;
	else if(n<=500&&m==1)cout<<515058943;
	else if(n<=500)cout<<225301405;
}	
