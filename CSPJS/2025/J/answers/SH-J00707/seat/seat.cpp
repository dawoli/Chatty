#include<bits/stdc++.h>
using namespace std;
int n,m,a[110];
int pos,k;
bool cmp(int x,int y)
{
	return x>y; 
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++)
	{
		cin >> a[i];
		if(i==1)pos=a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==pos)k=i;
	}
    int cnt=1,c=1,r=1;
	while(cnt<k)
	{
		if(c%2==1)
		{
			if(r<n)r++;
			else c++;
		}
		else
	    {
	    	if(r>1)r--;
	    	else c++;
		}
		cnt++;
	}
	cout << c << " " << r;
	return 0;
}
