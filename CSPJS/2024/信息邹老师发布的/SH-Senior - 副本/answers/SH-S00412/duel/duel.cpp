#include<bits/stdc++.h>
using namespace std;
long long a[100005];
int b[100005];
int main()
{
	//freopen("duel.in","r",stdin);
	//freopen("duel.out","w",stdout);
	int j,k,i,l;
	long long ans=0,n;
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a,a+n);
	for(i=0;i<n;i++)
	{
		k=a[i];
		l=0;
		for(j=i+1;j<n;j++)
		{
			if(a[j]>k&&b[j]==0)
			{
				b[j]=1;
				ans++;
				l=1;
				break;
			}
		}
		if(l==0)
			break;
	}
	printf("%lld",n-ans);
	//fclose(stdin);
	//fclose(stdout);
	return 0;
 } 
