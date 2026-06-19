#include<bits/stdc++.h>
#define int long long
using namespace std;
long long n,k;
long long a[500001],q[500001];
long long cnt=0;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	q[0]=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		q[i]=q[i-1]^a[i];
	}
	int l,r;
	int ans=-1;
	for(l=1;l<=n;l++){
		for(r=l;r<=n;r++){
			if((q[l-1]^q[r])==k){
				cnt++;
				l=r+1;
			}
		} 
		ans=max(ans,cnt); 
	}
	cout<<ans<<endl;
}
