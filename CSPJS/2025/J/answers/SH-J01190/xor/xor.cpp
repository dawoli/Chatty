#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+7,md=9982344353,pk=(1<<23);
int n,k;
int a[N],s[N];
int g[pk],dp[N],ans;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
//	freopen("xor.in","r",stdin);
//	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(),cout.tie();
	cin>>n>>k;
	memset(g,-0x3f,sizeof g);
	dp[0]=g[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
		dp[i]=max(g[s[i]^k]+1,dp[i-1]);
		//cout<<dp[i]<<"\n";
		g[s[i]]=max(dp[i],g[s[i]]);
		ans=max(ans,dp[i]);
	}
	cout<<ans;
} 
/*
如果这个也上不了奇葩大赏的话 

律诗一首（灵感自《黄鹤楼》） 
汉阳落日不见秋，望近旷寂唯见楼。 
黄鹤临天余空塔，鹦鹉逝涯留沉洲。
秦川万里空枯草，汉江千载残落流。
浮云几了天下事，洛阳不见使人愁。

律诗一首（灵感自《使至塞上》） 
北峰临胡塞，南望冷悲秋。
夹山独赤壁，涸谷无水流。 
孤烟空寂野，落日残古丘。 
何故来此地？游客思乡愁。

老样子：
I love wcj! 
*/ 
