#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5007,md=998244353;
int n,a[N],dp[N],ans;
int ksm(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=a*a%md)
		if(b&1)
			ans=ans*a%md;;
	return ans;
}
int mode(int x){
	return (x%md+md)%md;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(),cout.tie(); 
	cin>>n;
	ans=mode(ksm(2,n)-1);
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	dp[0]=1;
	for(int i=1;i<=n;i++){
		int sum=0;
		for(int j=0;j<=a[i];j++)
			sum=mode(sum+dp[j]);
		ans=mode(ans-sum);
		for(int j=5000-a[i];j>=0;j--)
			dp[j+a[i]]=mode(dp[j+a[i]]+dp[j]);
	}
	cout<<ans<<"\n";
}
/*
45分钟写完全部正解代码 
只能说，太水了

律诗一首 （灵感自 黛玉《葬花吟》（她写的也就一般，比宝琴的好）） 

花谢花飞花满天，红消香断有谁怜。

一心空守悲秋近，半风萧吹待春还。

零落散作故梦后，残谢掩起今恨前。

千古几多惜玉士，莫以冷情借谎言。 


绝句一首 （灵感自 宝琴《赤壁怀古》（她写的什么玩意）） 

满江胭脂水不流，宦海浮沉岂敢留。 

长泪漫挥天下梦，一身至死踏清秋。 
 
 
哦对了，I love wcj!

（让我上奇葩大赏！！！） 
*/ 
