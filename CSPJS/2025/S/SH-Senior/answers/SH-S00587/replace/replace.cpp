#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int n,q,l[200010],h[200010][2],h2[5000010][2],p[5000010],ans;
string s[2];
vector<int>e[800];
int get(int i,int l,int r){return (h2[r][i]-1ll*p[r-l+1]*h2[l-1][i]%mod+mod)%mod;}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q),p[0]=1;
	for(int w=1;w<=5000000;w++)p[w]=26ll*p[w-1]%mod;
	for(int w=1;w<=n;w++){
		s[0]="",s[1]="",cin>>s[0]>>s[1],l[w]=s[0].size(),e[(s[0][0]-'a')*26+(s[1][0]-'a')].push_back(w);
		for(int x=1;x<=l[w];x++)h[w][0]=(26ll*h[w][0]+(s[0][x-1]-'a'))%mod,h[w][1]=(26ll*h[w][1]+(s[1][x-1]-'a'))%mod;
	}
	while(q--){
		s[0]="",s[1]="",cin>>s[0]>>s[1],ans=0;
		int L0=s[0].size(),L1=s[1].size(),L,R;
		if(L0!=L1){printf("0\n");continue;}
		for(int w=1;w<=L0;w++)h2[w][0]=(26ll*h2[w-1][0]+(s[0][w-1]-'a'))%mod,h2[w][1]=(26ll*h2[w-1][1]+(s[1][w-1]-'a'))%mod;
		for(int w=1;w<=L0;w++)if(s[0][w-1]!=s[1][w-1]){L=w;break;}
		for(int w=L0;w;w--)if(s[0][w-1]!=s[1][w-1]){R=w;break;}
		for(int x=1;x<=L;x++)for(int w=0;w<e[(s[0][x-1]-'a')*26+(s[1][x-1]-'a')].size();w++){
			int k=e[(s[0][x-1]-'a')*26+(s[1][x-1]-'a')][w];
			if(x+l[k]-1>=R)if(h[k][0]==get(0,x,x+l[k]-1)&&h[k][1]==get(1,x,x+l[k]-1))ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
