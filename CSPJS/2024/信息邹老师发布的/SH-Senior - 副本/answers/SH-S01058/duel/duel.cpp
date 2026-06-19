#include <cstdio>
#include <algorithm>
using namespace std;
const int N=100100;
int a[N],b[N];
int cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n,cmp);
	int last=n;
	for(int i=n-1;i>=1;i--)
	{
		if(a[i]>a[last])
		{
			b[last]=1;
			last--;
		}
	}
	int ans=n;
	for(int i=1;i<=n;i++)
	{
		if(b[i]==1)
		{
			ans--;
		}
	}
	printf("%d\n",ans);
	fclose(stdin);fclose(stdout); 
	return 0;
}
