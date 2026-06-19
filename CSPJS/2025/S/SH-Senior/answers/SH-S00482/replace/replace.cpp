#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=4e6+10;
ll n,q;
string s1[maxn],s2[maxn],t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for (ll i=1;i<=n;i++) cin>>s1[i]>>s2[i];
	while (q--) {
		cin>>t1>>t2;ll ans=0;
		for (ll i=1;i<=n;i++) {//在t1中寻找s1[i]，若找到，则将他替换为s2[i],并检测是否与t2相等 
			for (ll j=0;j<t1.size()-s1[i].size()+1;j++) {
				string tmp=t1.substr(j,s1[i].size()),tmp2=t1;
				if (tmp==s1[i]) {
					for (ll k=j;k<j+s2[i].size();k++) tmp2[k]=s2[i][k-j];
				}
				if (tmp2==t2) ans++; 
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
