#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,q;
ll s[200009][2];
ll t[200009][2];
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s[i][0]>>s[i][1];
	for(int i=1;i<=q;i++)cin>>t[i][0]>>t[i][1];
	return 0;
}
