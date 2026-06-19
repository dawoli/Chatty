#include<bits/stdc++.h>
using namespace std;
int T,n,a[100006][5],ans[5][100001],res,cho[100001];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>T;
	while(T--)
	{
		res = 0;
		memset(ans,0,sizeof(ans));
		cin>>n;
		for(int i = 1;i<=n;i++) cin>>a[i][1]>>a[i][2]>>a[i][3];
		for(int i = 1;i<=n;i++)
		{
			int bst = 0,bstn = 0;
			for(int j = 1;j<=3;j++)
			{
				if(bstn<a[i][j])
				{
					bstn = a[i][j];
					bst = j;
				}
			}
			ans[bst][++ans[bst][0]] = i;
			res += bstn;
		}
		for(int j = 1;j<=3;j++)
		{
			if(ans[j][0]>n/2)
			{
				for(int i = 1;i<=ans[j][0];i++)
				{
					cho[i] = max(a[ans[j][i]][(j+1)%3+1],a[ans[j][i]][(j)%3+1]);
					cho[i] = a[ans[j][i]][j] - cho[i];
				}
				sort(cho+1,cho+ans[j][0]);
				for(int i = 1;i<=ans[j][0]-n/2;i++)
				{
					res -= cho[i];
				}
			}
		}
		cout<<res<<endl;
	}
	return 0;
}
