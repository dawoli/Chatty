#include <bits/stdc++.h>
using namespace std;

int n,m,c,r,id;
struct Stu
{
	int a,id;
}stu[107];

bool cmp(Stu A,Stu B)
{
	return A.a>B.a;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>stu[i].a;
		stu[i].id=i;
	}
	sort(stu+1,stu+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(stu[i].id==1)
		{
			id=i;
		}
	}
	int c=(id-1)/n+1;
	if(c&1)
	{
		r=((id-1)%n)+1;
	}
	else
	{
		r=n-((id-1)%n);
	}
	cout<<c<<" "<<r<<"\n";
	return 0;
}
/*
2 2
99 100 97 98
*/
/*
2 2
98 99 100 97
*/
