#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
string s;
const int maxn=500+1;
ll a[maxn],one_cnt=0;
bool vis[maxn];
const ll mod=998244353;
ll c[maxn];
ll fac[maxn];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	fac[0]=1;
	for(int i=1;i<=500;i++){
		fac[i]=(fac[i-1]*i)%mod;
	}
	bool A=1;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'){
			A=0;
		}else{
			one_cnt++;
		}
	}
	int leftmo=0;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0){
			leftmo++;
		}
		a[i]=i;
	}
	if(one_cnt==n&&leftmo==0){
		cout<<fac[n]%mod;
	}else if(m==n){
		cout<<0;
	}else if(n<=18){
		ll ans=0;
		int ds=0,nm=0;
		for(int i=1;i<=n;i++){
			if(s[i-1]=='1'&&ds<c[a[i]]){
				++nm;
			}else{
				++ds;
			}
		}
		if(nm>=m) ++ans;
		while(next_permutation(a+1,a+n+1)){
			int sb=0,total=0;
			for(int i=1;i<=n;i++){
				if(s[i-1]=='1'&&sb<c[a[i]]){
					++total;
				}else{
					++sb;
				}
			}
			if(total>=m){
				++ans;
			}
		}
		cout<<ans%mod;
	}else{
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
}
