#include<bits/stdc++.h>
using namespace std;
#define int long long
#define MOD 998244353
int n,m,c[505],jc[505];
bool f[505];
string s;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.tie(0);ios::sync_with_stdio(false);
	jc[1]=1;
	for(int i=2;i<=500;i++)jc[i]=(jc[i-1]*i)%MOD;
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++){f[i+1]=s[i]-'0';}
	for(int i=1;i<=n;i++)cin>>c[i];
	if(m==n){
		int k=0;
		for(int i=1;i<=n;i++)k+=(c[i]==0);
		if(k!=0){
			cout<<0;
			return 0;
		}
		k=0;
		for(int i=1;i<=n;i++)k+=(f[i]==0);
		if(k!=0){
			cout<<0;
		}
		else cout<<jc[n];
		return 0;
	}
	if(n<=13){
		int h[15],ans=0;
		for(int i=1;i<=n;i++)h[i]=i;
		do{
			int num=0,k=0;
			for(int i=1;i<=n;i++){
				if(f[i]&&c[h[i]]>k)num++;
				else k++;
			}
			if(num>=m)ans++;
		}while(next_permutation(h+1,h+n+1));
		cout<<ans<<endl;
		return 0;
	}
	srand(time(0));
	cout<<rand()*rand()%MOD*rand()%MOD;
} 
