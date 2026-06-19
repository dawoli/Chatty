#include<bits/stdc++.h>
using namespace std;
int main{
	freopen("polygon.in","s",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	if(n==3){
		int a,b,c;
		cin>>a>>b>>c;
		int mx=max(a,max(b,c));
		if((a+b+c)>2*mx){
			cout<<1;
		}else{
			cout<<0;
		}
	}
}
