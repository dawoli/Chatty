#include<bits/stdc++.h>
using namespace std;
int n,a[100010],fai;
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	fai=1;
	for(int i=2;i<=n;i++)
	{
		if(a[fai]<a[i])
		{
			fai++;
		}
	}
	cout<<n-fai+1<<endl;
	return 0;
}
