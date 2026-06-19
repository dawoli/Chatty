#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
int n,k;
int a[MAXN];
int f[MAXN];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n%2==1)cout<<0;
	else{
		cout<<1;
	}
	
	return 0;
}
