#include <bits/stdc++.h>
using namespace std;
int n;
long long a[100005],b=0,k,sum,num;
bool ppp(int i,int j)
{
	for(int x = i;x<j+1;x++)
	{
		b=b^a[x];
	}
	if(b==k)
	{
		b=0;
		return true;
	}
	b=0;
	return false;
}
void pp(int begin)
{
	for(int i = begin;i<n;i++)
	{
		for(int j = i;j<n;j++)
		{
			if(ppp(i,j))
			{
				num++;
				pp(j+1);
				sum = max(sum,num);
				num--;
			}
			
		}
	}
}
int main()
{
	freopen("xor5.in","r",stdin);
	freopen("xor5.out","w",stdout);
	cin >> n >> k;
	for(int i = 0;i<n;i++)
	{
		cin >> a[i];
	}
	if(k == 0)
	{
		for(int i = 0;i<n;i++)
		{
			if(a[i]==0)
				sum++;
		}
	}
	else if(k == 1)
	{
		for(int i = 0;i<n;i++)
		{
			if(a[i]==1)
				sum++;
		}
	}
	else
		pp(0);
	cout << sum << endl;
	return 0;
}
