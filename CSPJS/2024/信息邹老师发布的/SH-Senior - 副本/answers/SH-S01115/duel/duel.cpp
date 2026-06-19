#include<bits/stdc++.h>
using namespace std;
int n,temp,c=0,f[100001],a[100001];
void p(int x)
{
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(a[j]<=a[i])
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
}
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=n;i++) p(a[i]);
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=0)
			for(int j=i+1;j<=n;j++)
			{
				if(a[j]>a[i]&&f[j]==0)
				{
					a[i]=0;
					f[j]=1;
					break;
				}
			}
		if(f[i]!=0) break;
	}	
	for(int i=1;i<=n;i++)
		if(a[i]!=0) c++;
	cout << c;
	return 0;
}
