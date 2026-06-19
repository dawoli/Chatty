#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2009;
string s[N][2],t[N][N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ll n,q;
	cin>>n>>q;
	for(ll i=1;i<=n;i++) cin>>s[i][1]>>s[i][2];
	for(ll i=1;i<=q;i++){
		string x,y;
		cin>>x>>y;
		string tmp=x;
		ll ans=0;
		for(ll i=0;i<x.size();i++)
			for(ll j=i;j<x.size();j++)
				if(j==i) t[i][j]=x[j];
				else t[i][j]=t[i][j-1]+x[j];
		for(ll i=0;i<x.size();i++){
			for(ll j=i;j<x.size();j++){
				for(ll k=1;k<=n;k++)
					if(t[i][j]==s[k][1]){
						for(ll l=i;l<=j;l++) x[l]=s[k][2][l-i];
						break;
					}
				if(x==y) ans++;
				x=tmp;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
