#include <bits/stdc++.h>
using namespace std;
int n,m,x,r,num,cnt,p=1,q=1;
bool f=1;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	num=n*m;
	cin>>r;
	for(int i=2;i<=num;i++)
	{
		cin>>x;
		if(x>r)
		{
			cnt++;
		}
	}
	while(cnt>0)
	{
		if(f)
		{
			p++;
			if(p>n)
			{
				p=n;
				f=!f;
				q++;
			}
		}
		else
		{
			p--;
			if(p<1)
			{
				p=1;
				f=!f;
				q++;
			}
		}
		cnt--;
	}
	cout<<q<<" "<<p;
	return 0;
}
