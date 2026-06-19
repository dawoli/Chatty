#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=1e9;
const int N=5e2+9;
const int MOD=998244353;
ll n,m;
string s1;
ll c[N];
void solveA(){
	ll ans=1;
	for(ll i=0;i<m;i++){
		ans*=(n-i);
		ans%=MOD;
	}
	cout<<ans<<endl;
	return ; 
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s1;
	ll length=s1.size();
	int s[N];
	ll all_s=0;
	bool is_A=true;
	for(int i=0;i<length;i++){
		s[i+1]=s1[i]-'0';
		all_s+=s[i+1];
		if(s[i+1]!=1){
			is_A=false;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(all_s<m){
		cout<<0<<endl;
		return 0;
	}
	if(is_A){
		solveA();
		return 0;
	}
	return 0;
}
