#include<bits/stdc++.h>
using namespace std;

const int N=1e7+5;
int n,m;
int a[N];
int ans=0;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) ans=max(ans,a[i]%m);
	cout<<ans;
	return 0;
} 
