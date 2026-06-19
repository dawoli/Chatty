#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n;
int a[100100];
int sum;
int b[100100];

void bf()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(a[j]>a[i]&&!b[j])
			{
				sum++;
				b[j]=1;
				break;
			}
		}
	}
	cout<<n-sum;
}

int main() 
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n<=10)
	{
		bf();
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		int m=a[i];
		int l=i,r=n+i;
		while(l+1!=r)
		{
			int mid=(l+r)/2;
			if(a[mid]>m)
			{
			
				r=mid;
			}
			else
			{
				
				l=mid;
			}
			
		}

		while(b[r]&&r<=n)
		{
			r++;
		}
		if(r<=n)
		{
			b[r]=1;
			sum++;
		}
		
	}
	cout<<n-sum;
	return 0;
}
