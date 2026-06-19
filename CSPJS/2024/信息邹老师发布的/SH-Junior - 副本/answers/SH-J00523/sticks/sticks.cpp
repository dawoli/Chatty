#include<bits/stdc++.h>
using namespace std;
int t,n,c[10]={6,2,5,5,4,5,6,3,7,6},a[9]={0,1,2,4,6,7,8},ml,k[100010],m[100010];
string dp[100010][10],s[100010],ans,u;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	scanf("%d",&t),memset(m,0x3f,sizeof(m));
	for(int w=9;w>=0;w--)dp[c[w]][w]+=(w+'0'),m[c[w]]=1,k[c[w]]=w;
	for(int w=4;w<=7;w++){
		for(int x=1;x<=6;x++){
			int y=a[x];
			if(w>=c[y]&&m[w-c[y]]+1<m[w])dp[w][y]+=(y+'0'),dp[w][y]+=s[w-c[y]],m[w]=m[w-c[y]]+1,k[w]=y;
		}
		if(w>=6&&m[w-6]+1<=m[w])dp[w][0]+='0',dp[w][0]+=s[w-6],m[w]=m[w-6]+1,s[w]=dp[w][0];
		else s[w]=dp[w][k[w]];
	}
	for(int w=8;w<=100000;w++){
		k[w]=2;
		for(int x=2;x<=6;x++)if(m[w-a[x]]<m[w-k[w]])k[w]=a[x];
		dp[w][k[w]]+='0'+k[w],dp[w][k[w]]+=s[w-k[w]],m[w]=m[w-k[w]]+1;
		if(m[w-6]+1<=m[w])dp[w][0]+='0',dp[w][0]+=s[w-6],m[w]=m[w-6]+1,k[w]=0;
		s[w]=dp[w][k[w]];
	}
	while(t--){
		scanf("%d",&n),ml=1e9,k[0]=-1;
		for(int w=1;w<=9;w++)if(n>=c[w]){
			u=dp[n][w];
			if(u.size()<ml&&u.size())ml=u.size(),k[0]=w;
		}
		if(k[0]==-1)printf("-1\n");
		else cout<<dp[n][k[0]]<<endl;
	}
	return 0;
}
