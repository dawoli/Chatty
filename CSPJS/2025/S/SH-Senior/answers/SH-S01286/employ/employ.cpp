#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll mod=998244353;
int n,m;
string s;
int c[1234],p[12]={0,1,2,3,4,5,6,7,8,9,10},x[1234],cnt;
ll ans,y[1234],mns=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)cin>>c[i];
	if(n>10){
		for(int i=0;i<s.size();i++)
			if(s[i]=='1')x[++cnt]=i+1;
		sort(c+1,c+n+1);
		for(int i=1;i<=cnt;i++)y[i]=lower_bound(c+1,c+n+1,x[i])-c-1;
		for(int i=1;i<=cnt;i++){
			if(y[i]<=i-1){
				mns=0;
				break;
			}
			mns=mns*(y[i]-(i-1))%mod;
		}
		for(int i=1;i<=n-cnt;i++)mns=mns*i%mod;
		ans=1;
		for(int i=1;i<=n;i++)ans=ans*i%mod;
		ans=(ans-mns+mod)%mod;
		cout<<ans<<'\n';
		return 0;
	}
	do{
		int cur=0,sum=0;
		for(int i=1;i<=n;i++){
			if(c[p[i]]<=cur||s[i-1]=='0')cur++;
			else sum++;
		}
		if(sum>=m)ans++;
	}while(next_permutation(p+1,p+n+1));
	cout<<ans<<'\n';
	return 0;
}
