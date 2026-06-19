#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
const int MAXN=100005;
int a[MAXN];
//map<int> M[MAXN];
int ti[MAXN],inum=0;
int t[MAXN],tt[MAXN];
void print()
{
	for(int i=1;i<=inum;i++)
	{
		cout<<ti[i]<<' '<<t[ti[i]]<<' '<<tt[ti[i]]<<endl;
	}
}
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n,ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		t[a[i]]++;
		tt[a[i]]++;
		if(t[a[i]]==1)
			ti[++inum]=a[i];
	}
	sort(ti+1,ti+inum+1);
	for(int i=1;i<inum;i++)
	{
		int k=0;
		for(int j=i+1;j<=inum;j++)
		{
			if(tt[ti[j]]==0)	continue;
			if(tt[ti[j]]+k>=t[ti[i]])
			{
				ans+=t[ti[i]]-k;
				tt[ti[j]]-=t[ti[i]]-k;
				break;
			}
			else
			{
				k+=tt[ti[j]];
				ans+=tt[ti[j]];
				tt[ti[j]]=0;
			}
		}
	}
	printf("%d",n-ans); 
	return 0;
 } 
