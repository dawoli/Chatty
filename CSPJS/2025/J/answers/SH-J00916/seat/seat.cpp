#include<bits/stdc++.h>
using namespace std;
int n,m,a[15][15];
struct stu{
	int mk,id;
}s[110];
bool cmp(stu a,stu b)
{
	return a.mk>b.mk;
}
void filled()
{
	
	int l=1,d=0;
	for(int i=1;1;)
	{
		for(int j=1;1;)
		{
			a[i][j]=s[l].id;
			l++;
			if(l>n*m) return;
			if(i==n&&d==0) 
			{
				d=1;
				j++;
				continue;
			}
			if(i==1&&d==1)
			{
				d=0;
				j++;
				continue;
			}
			if(d==0) i++;
			else i--;
			
		}
	}
	return;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;++i)
	{
		cin>>s[i].mk;
		s[i].id=i;
	}
	sort(s+1,s+(n*m)+1,cmp);
	filled();
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(a[i][j]==1) cout<<j<<' '<<i;
}
