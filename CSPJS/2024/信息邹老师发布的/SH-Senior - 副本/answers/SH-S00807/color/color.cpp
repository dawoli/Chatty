/* n^2 的 dp
设f[i][j][0/1]表示第j+1~i均为颜色0/1，而j的颜色相反的答案
首先找到最近的k使得a[k]=a[i]，则只有k,i颜色相同,k+1~i-1之间都是相反的颜色时，i处才有贡献
若k=i-1，则f[i][j][0/1] = f[k][j][0/1] + a[i]
若k 不等于 i-1，则f[i][i-1][0/1] = f[k][jp][0/1] + a[i] + s[k+1,i-1] + (a[jp]==a[k+1]) 
s[k+1,i-1]表示k+1到i-1这一段内部产生的贡献，预处理之后可以O(1)查询，若a[jp] = a[k+1],则k+1处也会产生贡献。

*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2e5+5;
const int M=1e6+5;
LL a[N],s[N];
vector<int> c[M];
int rk[N],cnt[M],n,T;
namespace BF
{
	const int NN=2e3+5;
	LL f[NN][NN][2],ans[NN][2];
	void solve()
	{
		memset(f,0,sizeof(f));
		memset(ans,0,sizeof(ans));
		s[1]=0;
		for(int i=2;i<=n;++i) 
			if(a[i]==a[i-1]) s[i]=s[i-1]+a[i];
			else s[i]=s[i-1];
		LL mx=*max_element(a+1,a+1+n);
		for(LL i=1;i<=mx;++i) c[i].resize(0),cnt[i]=0;
		for(int i=1;i<=n;++i){rk[i]=cnt[a[i]]++;c[a[i]].push_back(i);}
		for(int i=1;i<=n;++i)
		{
			int k=0;
			if(rk[i]) k = c[a[i]][rk[i]-1];
			for(int o=0;o<2;++o)
			{
				// i 和 i-1 不同色
				f[i][i-1][o] = ans[i-1][o^1]; 
				// i 和 i-1 同色
				for(int j=0;j<i-1;++j)
					f[i][j][o] = f[i-1][j][o];
				if(k)
				{
					if(k==i-1)
					{
						for(int j=0;j<i-1;++j)
							f[i][j][o] = max(f[i][j][o],f[k][j][o] + a[i]);
					}
					else
					{
						for(int jp=0;jp<k;++jp)
						{
							LL A=f[k][jp][o]+a[i]+(s[i-1]-s[k+1]);
							if(a[jp]==a[k+1]) A += a[k+1];
							f[i][i-1][o]=max(f[i][i-1][o],A);
						}
					}
				}
				
				for(int j=0;j<i;++j)
					ans[i][o]=max(ans[i][o],f[i][j][o]);
			}
		}
		cout << max(ans[n][0],ans[n][1]) << "\n";
	}
}
int main()
{
	ios::sync_with_stdio(false);
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=n;++i) cin>>a[i];
		BF::solve();
	}
	return 0;
}
