#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	bool check[60]={};
	cin>>n;
	for(int i=0;i<n;i++){
		char c[3];
		int k,m;
		cin>>c;
		if(c[0]=='C') k=0;
		else if(c[0]=='D') k=13;
		else if(c[0]=='H') k=26;
		else if(c[0]=='S') k=39;
		if(c[1]=='T') m=10;
		else if(c[1]=='A') m=1;
		else if(c[1]=='J') m=11;
		else if(c[1]=='Q') m=12;
		else if(c[1]=='K') m=13;
		else m=c[1]-'0';
		check[m+k]=1;
	}
	int ans=0;
	for(int i=1;i<=52;i++){
		if(check[i]==0) ans++;
	}
	cout<<ans;
	return 0;
} 
