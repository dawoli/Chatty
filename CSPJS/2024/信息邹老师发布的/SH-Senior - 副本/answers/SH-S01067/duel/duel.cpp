#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9;
typedef long long ll;
ll n,m,a[N],ans,tot;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		a[x]++;
	}
	for(int i=1;i<=1e5+2;i++)ans=max(ans,a[i]);
	cout<<ans<<endl;
	return 0;
}
