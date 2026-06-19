#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=509;
ll n,m,ans=1;
string s;
ll c[MAXN]; 
bool flag0=true;
bool leave[MAXN];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	cin>>s;
	int remain=n;
	for(ll i=0;i<s.length();i++)flag0*=int(s[i]-'0');
	for(ll i=1;i<=n;i++)cin>>c[i];
	//if(!flag0){
		for(ll i=1;i<=n;i++){
			int all_leave=0;
			for(ll j=1;j<=n-1;j++)all_leave+=leave[j];
			if(all_leave>=c[i]){
				leave[i]=true;
				remain--;
			}
		}
		if(remain<m){cout<<0<<endl;return 0;}
		for(ll i=remain;i>=remain-m+1;i--){
			ans*=i;
			ans%=998244353;
		}
		cout<<ans<<endl;
		return 0;
	//}
	return 0;
}
