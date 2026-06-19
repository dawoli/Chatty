#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],t[1100005],mx[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]^=a[i-1];
	}
	for(int i=1;i<=(1<<20);i++) t[i]=500004;
	mx[500004]=-1;
	for(int i=1;i<=n;i++){
		mx[i]=max(mx[i-1],mx[t[a[i]^k]]+1);
		t[a[i]]=i;
	}
	cout<<mx[n];
	return 0;
}
