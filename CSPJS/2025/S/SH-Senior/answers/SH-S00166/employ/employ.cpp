#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
ll n,m,ans,h;
string s;
ll c[509],f[509];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		f[i]=i;
	}
	sort(c+1,c+1+n);
	if(n<=10){
		do{
			ll t=0;
			h=0; 
			for(int i=1;i<=n;i++){
				if(t>=c[f[i]])t++;
				else if(s[i-1]=='1')h++;
				else t++;
				//cout<<c[i]<<" ";
			}
			//cout<<endl;
			if(h>=m)ans++;
			ans%=mod;
		}while(next_permutation(f+1,f+1+n));
		cout<<ans;
		return 0;
	}
	ll cnt=0,ling=0;
	for(int i=0;i<n;i++){
		if(s[i]=='1')cnt++;
		if(c[i]==0)ling++;
	}
	if(cnt==n){
		ans=1;
		for(int i=1;i<=n;i++){
			
		}
	}
	return 0;
}
