#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	int a,b;
	if(n==1) cin>>a;
	else cin>>a>>b;
	int ans=0;
	if(a==m) ans++;
	if(b==m) ans++;
	if(a&b==m) ans++;
	cout<<ans;
	return 0;
	}
