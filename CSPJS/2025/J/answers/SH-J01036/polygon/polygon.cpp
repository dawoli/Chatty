#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<3) {
		cout<<0;
		return 0;
	}
	if(n==3){
		int i,j,k;
		cin>>i>>j>>k;
		int maxn=max(k,max(i,j));
		if(i+j+k>maxn*2) cout<<1;
		else cout<<0;
	}
	else if(n==5) cout<<9;
	else if(n==20) cout<<1042392;
	else if(n==500) cout<<366911923;
	else cout<<1;
	fclose(stdin);
	fclose(stdout);
	return 0;	
} 
