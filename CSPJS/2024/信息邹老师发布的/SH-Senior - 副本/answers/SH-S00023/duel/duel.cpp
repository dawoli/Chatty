#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1e5+5;
int n,r[N];
int l[N];
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&r[i]);
	sort(r+1,r+n+1);
	int out=0,i=1,j=1;
	while(j<=n)
	{
		if(l[i]==-2) {i++;continue;}
		if(l[j]==-1) {j++;continue;}
		if(r[i]<r[j])
		{
			l[i]=-2;
			l[j]=-1;
			i++;j++;out++;
		}
		else j++;
	}
	printf("%d",n-out);
	return 0;
}
