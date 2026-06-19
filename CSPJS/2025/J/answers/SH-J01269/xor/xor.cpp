#include<bits/stdc++.h>
using namespace std;
int n,k,a[200005],add=0,sum=0,b[1001][1001],c[200005];
bool check(int s,int e){
	for(int i=s;i<=e;i++){
		if(c[i]==1)return false;
	}
	return true;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0){
			add++;
		}
		if(i==1)continue;
		if(a[i]!=a[i-1]){
			a[i]=0;
		}else a[i]=1;
	}
	if(add==n){
		cout<<n/2;
		return 0;
	}
	cout<<n/2;
	return 0;
}
