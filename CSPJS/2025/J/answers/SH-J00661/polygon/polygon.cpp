#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
long long dfs(int sum,int mx,int id)
{
	if(id>n)
	{
		if(sum>mx*2)return 1;
		return 0;
	}
	return (dfs(sum+a[id],max(mx,a[id]),id+1)+dfs(sum,mx,id+1))%998244353;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	cout<<dfs(0,0,1);
	return 0;
}
/*小子。这一刀你要看好了。这一刀，会很帅。
	我陈牧野，守了这座城十年。现在，也是时候与它一起离开了。
	你还不明白吗？要杀你的不是我，是父亲啊。
	对不起，不用等我回来了。
	我种下的种子，已经成熟了。
	跑啊，队长，跑啊！只要你能跑赢时间，总有一天，我们都会回到你身后！
	灵媒，死战。
	--《我在精神病院学斩神》*/ 
