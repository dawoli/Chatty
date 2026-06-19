#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5,M=1.5e6+5;
int n,k,a[N],b[M],l,ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]^=a[i-1];
	}
	memset(b,-1,sizeof(b));
	b[0]=0;
	for(int i=1;i<=n;i++){
		ll x=a[i]^k;
		if(b[x]>=l){
			ans++;
			l=i;
		}
		b[a[i]]=i;
	}
	cout<<ans<<'\n';
	return 0;
}
