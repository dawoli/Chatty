#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t;cin>>t;
	while(t--)
	{
		int n;cin>>n;
		int a[20];
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		int ans=0;
		for(int s=0;s<(1<<n);s++)//枚举状态计算得分 
		{
			int score=0;
			for(int i=0;i<n;i++)//从左往右遍历第一位数
			{
				bool st1=(1<<i)&(s);
				int j;
				for(j=i-1;j>=0;j--)
				{
					bool st2=(1<<j)&(s);
					if(st1==st2) break;//找到同色的i，j
				}
				if(a[i]==a[j]) score+=a[i];
			}
			ans=max(ans,score);
		}
		cout<<ans<<endl;
	}
}
