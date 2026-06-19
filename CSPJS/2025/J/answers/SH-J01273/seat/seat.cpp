#include<bits/stdc++.h>
using namespace std;
pair<int,int> a[100011];
bool compare(pair<int,int> temp1,pair<int,int> temp2)
{
	return temp1>temp2;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)scanf("%d",&a[i].first),a[i].second=i;
	sort(a+1,a+n*m+1,compare);
	int t=0;
	for(int i=1;i<=n*m;i++)
	{
		if(a[i].second==1)
		{
			t=i;break;
		}
	}
	int temp3=t/m;
	int temp4=t%m;
	if(temp3%2==0)
	{
		if(temp4==0)printf("%d %d\n",temp3,1);
		else printf("%d %d\n",temp3+1,temp4);
	}
	else
	{
		if(temp4==0)printf("%d %d\n",temp3,n);
		else printf("%d %d\n",temp3+1,n-temp4+1);
	}
	return 0;
}
