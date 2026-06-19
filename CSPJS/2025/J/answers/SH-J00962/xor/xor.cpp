#include<bits/stdc++.h>
using namespace std;
const int N=5e5+9,V=(1<<20);
int n,k,a[N],x[V],f[N],b[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i]^b[i-1];
	}
	x[k]=1;
	for(int i=1;i<=n;i++){
		f[i]=max(f[i-1],x[b[i]]);
		x[b[i]^k]=max(x[b[i]^k],f[i]+1);
//		cout<<f[i]<<endl;
	}
	cout<<f[n];
	return 0;
}

