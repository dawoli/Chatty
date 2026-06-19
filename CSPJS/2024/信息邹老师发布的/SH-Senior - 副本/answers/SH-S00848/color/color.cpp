#include <bits/stdc++.h>
using namespace std;
int t,n,a[200010],bs[1000010];
struct nd{
	int pa,pb;
};
nd prs[200010];
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int pt=1,sc=0;
		for(int j=1;j<=200009;j++)
		{
			a[j]=0;prs[j].pa=0;prs[j].pb=0;
		}
		for(int j=1;j<=1000009;j++)
		{
			bs[j]=0;
		}
		cin>>n;
		for(int j=1;j<=n;j++)
		{
			cin>>a[j];bs[a[j]]++;
			if(bs[a[j]]==2)
			{
				sc+=a[j];
			}
		}
		cout<<sc<<endl;
	}
	
}
