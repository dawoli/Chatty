#include<bits/stdc++.h>
using namespace std;

const int maxn=510;
const int mod=998244353;
int n,m,g[maxn],su[maxn],c[maxn],fac[maxn],inv[maxn],invfac[maxn],cho[maxn],cho0[maxn],cnt=0;
string s;

bool speA(){
	for(int i=1;i<=n;i++){
		if(g[i]==0) return 0;
	}return 1;
}

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	fac[1]=fac[0]=1;
	for(int i=2;i<=n;i++){
		long long x=1ll*fac[i-1]*i%mod;
		fac[i]=x;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=0;i<n;i++) g[i+1]=(int)(s[i]-'0');
	/*for(int i=1;i<=n;i++) cout<<get[i]<<" ";
	cout<<"\n";*/
	if(m==n){
		bool flag=1;
		for(int i=1;i<=n;i++){
			if(g[i]==0||c[i]==0) flag=0;
		}
		if(flag) cout<<fac[n];
		else cout<<0;
	}
	else if(n<=10){
		for(int i=0;i<fac[n];i++){
			int temp=i;
			for(int j=1;j<=n;j++){
				cho0[j]=0;
			}
			for(int j=1;j<=n;j++){
				int rank=(temp/fac[n-j])+1;
				//cout<<j<<" "<<rank<<"\n";
				int cnt=1;
				for(int x=1;x<=n;x++){
					if(!cho0[x]){
						if(cnt==rank){
							//cout<<j<<" "<<rank<<" "<<x<<"\n";
							cho[j]=x;
							cho0[x]=1;
							break;
						}
						else{
							//cout<<j<<" "<<rank<<" "<<x<<" 1\n";
							cnt++;
						}
					}
				}
				temp-=(temp/fac[n-j]*fac[n-j]);
			}
			int gu=0,peo=0;
			for(int j=1;j<=n;j++){
				if(c[cho[j]]>gu&&g[j]==1){
					//cout<<j<<" ";
					peo++;
				}
				else gu++;
			}
			if(peo>=m){
				cnt++;
			}
		}
		cout<<cnt;
	}
	else{
		cout<<0;
	}
}
