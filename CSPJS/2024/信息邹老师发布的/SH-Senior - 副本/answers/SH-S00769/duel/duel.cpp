#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int n,r[maxn],num[maxn],a[maxn],v[maxn],sum=0;

int main () {
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) num[i]=0;
	for(int i=1;i<=n;i++) {
		cin>>r[i];
		num[r[i]]++;
	}
	
	sort(r+1,r+n+1);
	int k=1;
	v[0]=0;
	for(int i=1;i<=n;i++) if(v[k-1]!=r[i]) v[k]=r[i],k++;
	
	for(int i=1;i<=k;i++) a[v[i]]=num[v[i]];
	for(int l=1,r=2;r<k;) {
		int t=min(num[v[l]],a[v[r]]);
		a[v[r]]-=t,num[v[l]]-=t;
		if(num[v[l]]==0) l++;
		if(a[v[r]]==0) r++;
		if(l==r) r++;
		sum+=t;
	}
	
	cout<<n-sum<<endl;
	return 0;
}
