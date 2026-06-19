#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+9,M=1100000;
int n,k,a,s,id[M],ls,mf[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>k;
	for(int i=1;i<M;i++)id[i]=-1;
	for(int i=1;i<=n;i++){
		cin>>a;s^=a;
		ls=id[s^k];id[s]=i;
		if(ls>=0)mf[i]=max(mf[i-1],1+mf[ls]);
		else mf[i]=mf[i-1];
	}
	cout<<mf[n];
	return 0;
}
