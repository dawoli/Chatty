#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+9;
ll n,r[N],fst=1;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>r[i];
	sort(r+1,r+n+1);
	for(ll i=1;i<=n;i++)
		if(r[fst]<r[i]) fst++;
	cout<<n-fst+1<<endl;
	return 0;
}
