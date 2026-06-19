#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++) 
#define per(i,a,b) for(ll i=(a);i>=(b);i--) 
#define fi first
#define se second
#define mk make_pair
using namespace std;
typedef long long ll;
typedef unsigned long long ull; 
typedef pair<ll,ll> pll; 
const ll maxn=1000009;
ll n,m,a[maxn];
string s;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	rep(i,0,n-1){
		if(s[i]>='0'&&s[i]<='9')
			a[++m]=s[i]-'0';
	}
	sort(a+1,a+1+m);
	per(i,m,1)	cout<<a[i];
	return 0;
}
