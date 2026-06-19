#include<bits/stdc++.h>
using namespace std;
int n=0,k=0,a[100005],s=0,maxt=0,ans=0;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);	
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]==k)
		{
			if(s>maxt)maxt=s;
			s=0;
			ans++;
		}
		else s++;
	}
	if(s>maxt)maxt=s;
	if(maxt<=1)printf("%d",ans);
	else printf("%d",ans+1);	
	return 0;
}
