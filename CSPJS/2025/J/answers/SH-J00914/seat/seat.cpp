#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[105],j,jh=1,jl=1;
	cin>>j;
	a[1]=j;
	for(int i=2;i<=n*m;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n*m,cmp);
	int se;
	for(int i=1;i<=n*m;i++) if(a[i]==j) {se=i;break;}
	while(se>n)
	{
		se-=n;
		jl++;
	}
	if(jl%2==1)
	{
		jh=se;
	}
	else 
	{
		jh=n-se+1;
	}
	cout<<jl<<" "<<jh; 
	return 0;
	fclose(stdin);
	fclose(stdout);
}
