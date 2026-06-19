#include<bits/stdc++.h>
using namespace std;

const int maxn=105;
int n,m,b,c;
struct mode
{
	int x;bool y;
}a[maxn];

bool cmp(mode a,mode b)
{
	return a.x>b.x;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>b;
		if(i==1) a[1]={b,true};
		else a[i]={b,false};
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i].y) c=i;
	}
	if((c+n-1)/n%2==1) cout<<(c+n-1)/n<<" "<<(c-1)%n+1;
	else	cout<<(c+n-1)/n<<" "<<n-(c-1)%n;
	return 0;
}
