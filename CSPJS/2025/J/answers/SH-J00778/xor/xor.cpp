#include<bits/stdc++.h>
using namespace std;

const int Maxn=5e5;
int n,k,a[Maxn+5],d[Maxn+5],f[Maxn+5];
map<int,int> m;
map<int,bool> m1;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		d[i]=d[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		f[i]=f[i-1];
		if(m1[k^d[i]]) f[i]=max(f[i],f[m[k^d[i]]]+1);
		m[d[i]]=i;
		m1[d[i]]=true;
	}
	cout<<f[n]<<endl;
	return 0;
}
