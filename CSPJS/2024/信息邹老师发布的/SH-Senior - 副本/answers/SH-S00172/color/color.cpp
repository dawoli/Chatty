#include<bits/stdc++.h>
#define N 200005
using namespace std;
int a[N];
int T,n;
inline int dfs(int lastb,int lastr,int i,int ans)
{
	int ans_b,ans_r,as;
	if(i==n+1)return ans;
	//这是b
	if(a[lastb]==a[i])as=ans+a[i];
	ans_b=dfs(i,lastr,i+1,as);
	//对于下一次染色 上个蓝变为本次，上个红不变 染下一个目标 答案累计
	as=ans;
	//这是r
	if(a[lastr]==a[i])as+=a[i];
	ans_r=dfs(lastb,i,i+1,as);
	//对于下一次染色 上个蓝不变，上个红变为本次 染下一个目标 答案累计 
	return max(ans_b,ans_r);
}
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	//
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		cout<<dfs(1,0,2,0)<<'\n';
		//1蓝色 没红色 染第一个 累计为0 
	}
	//
	return 0;
	fclose(stdin);
	fclose(stdout);
}
/*
3
3
1 2 1
4
1 2 3 4
8
3 5 2 5 1 2 1 4

*/
/*
ruarua.ru
  |   ---- |      |   /-----\  |   ---- |      |   /-----\       |   ---- |      |
  |  /     |      |  |      |  |  /     |      |  |      |       |  /     |      |
  |/       |      |  |      |  |/       |      |  |      |       |/       |      |
  |        |      |  |      |  |        |      |  |      |       |        |      |
  |         \----/ \ \-----/ \ |         \----/ \ \-----/ \  ||  |         \----/ \
*/
