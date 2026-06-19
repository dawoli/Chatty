#include<bits/stdc++.h>
using namespace std;

int T,n,m,ceilog[131075],fake_a[131075],c[131075],a[131075],ran[20][131075],X[4],dp[262150];
bool soul[262150],satis[262150];

int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	cin>>n>>m;ceilog[2]=1;
	for(int i=3;i<=n;i++){
		ceilog[i]=ceilog[(i+1)/2]+1;
	}
	for(int i=1;i<=n;i++){
		cin>>fake_a[i];
	}
	for(int i=1;i<=m;i++){
		cin>>c[i];
	}
	for(int i=1;i<=ceilog[n];i++){
		string s;cin>>s;
		for(int j=1;j<=(1<<ceilog[n]-i);j++)ran[i][j]=s[j-1]-'0';
	}
	cin>>T;
	while(T--){
		long long ans=0;
		for(int o=0;o<4;o++)cin>>X[o];
		for(int i=1;i<=n;i++){
			a[i]=fake_a[i]^X[i%4];a[i]=min(a[i],20);
		}
		for(int i=1;i<=m;i++){
			long long current=0;
			for(int targ=1;targ<=(1<<ceilog[c[i]]);targ++){
				for(int zt=(1<<ceilog[c[i]]+1)-1,j=(1<<ceilog[c[i]]),k=0;zt>=1;zt--){
					if(k==0){
						dp[zt]=j<=c[i]?a[j]:(targ==j?1006:0);
						soul[zt]=(j<=c[i])||(targ==j);satis[zt]=(targ==j);
					}
					else{
						if(soul[zt*2]^soul[zt*2+1]){
							if(!soul[zt*2])dp[zt*2]=k-1;
							else dp[zt*2+1]=k-1;
						}
						dp[zt]=dp[zt*2+ran[k][j]]>=k?dp[zt*2+ran[k][j]]:dp[zt*2+ran[k][j]^1];
						soul[zt]=dp[zt*2+ran[k][j]]>=k?soul[zt*2+ran[k][j]]:soul[zt*2+ran[k][j]^1];
						satis[zt]=dp[zt*2+ran[k][j]]>=k?satis[zt*2+ran[k][j]]:satis[zt*2+ran[k][j]^1];
					}
					if(j==1){
						k++;j=(1<<ceilog[c[i]]-k);
					}
					else j--;
				}
				if(satis[1])current+=targ;
			}
			ans^=current*i;
		}
		cout<<ans<<'\n';
	}
	cout<<endl;
	return 0;
}
