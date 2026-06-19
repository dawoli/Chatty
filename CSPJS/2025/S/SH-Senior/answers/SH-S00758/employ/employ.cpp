#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+5;
const int mod=998244353;

int n, m, a[N], c[N];
string s;
signed main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	if(n<=10){
		for(int i=1;i<=n;i++)a[i]=i;
		cin>>s;
		s=" "+s;
		for(int i=1;i<=n;i++)cin>>c[i];
		int cnt=0, tot=0, ans=0;
		do{
			cnt=0;tot=0;
			for(int i=1;i<=n;i++){
				if(s[i]=='0'){
					cnt++;
				}
				else if(cnt>=c[a[i]]){
					cnt++;
				}
				else tot++;
			}
//			cout<<endl;
			if(tot>=m){
				ans++;ans%=mod;
			}
		}while(next_permutation(a+1, a+n+1));
		cout<<ans;
	}
	else{
		for(int i=1;i<=n;i++)a[i]=i;
		cin>>s;
		s=" "+s;
		bool flag=0;
		for(int i=1;i<=n;i++){
			if(s[i]!='1'){
				flag=1;break;
			}
		}
		for(int i=1;i<=n;i++)cin>>c[i];
		if(!flag){
			int ans=1;
			for(int i=1;i<=n;i++){
				ans=(ans*i)%mod;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
