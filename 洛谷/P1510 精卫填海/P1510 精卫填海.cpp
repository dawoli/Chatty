#include<bits/stdc++.h>
using namespace std;
/*事实上，东海未填平的区域还需要至少体积为 v 的木
石才可以填平，而西山上的木石还剩下 n 块，
每块的体积和把它衔到东海需要的体力分别为 k 和 m。
精卫已经填海填了这么长时间了，她也很累了，
她还剩下的体力为 c。
输入文件的第一行是三个整数：v,n,c。
从第二行到第 n+1 行分别为每块木石的体积
和把它衔到东海需要的体力。*/
namespace Soaring_Wings
{
int v,n,c,ans;
vector<int> k,m,f;
vector<vector<int>> used;
void Soar()
{
	cin>>v>>n>>c;
	k.resize(n+1);
	m.resize(n+1);
	used.resize(n+1,vector<int>(c+1,0));
	f.resize(c+1,0);
	ans=c;
	for(int i=1;i<=n;i++)cin>>k[i]>>m[i];
	for(int i=1;i<=n;i++)
	{
		for(int l=c;l>=m[i];l--)
		{
			if(f[l-m[i]]+k[i]>f[l])
			{
				f[l]=f[l-m[i]]+k[i];
				used[i][l]=1;
			}
		}
	}
	if(f[c]>=v)
	{
		for(int i=0;i<=c;i++)
		{
			if(f[i]>=c)
			{
				cout<<c-i<<endl;
				return;
			}
		}
	}
	else cout<<"Impossible"<<endl;
	return;
}
}
int main()
{
	Soaring_Wings::Soar();
	return 0;
}
