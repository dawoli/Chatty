#include<bits/stdc++.h>
using namespace std;
struct stu
{
	int s,i;
}arr[105];
bool cmp(stu a,stu b)
{
	return a.s>b.s;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,ri,a,b;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n*m;i++)
	{
		arr[i].i=i;
		scanf("%d",&arr[i].s);
	}
	sort(arr,arr+n*m,cmp);
	for(int i=1;i<=n*m;i++)
		if(arr[i].i==1)
		{
			ri=i;
			break;
		}
	a=ri/m+1;
	if(a%2==1)
		b=ri%m+1;
	else
		b=n-ri%m;
	printf("%d %d\n",a,b);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
