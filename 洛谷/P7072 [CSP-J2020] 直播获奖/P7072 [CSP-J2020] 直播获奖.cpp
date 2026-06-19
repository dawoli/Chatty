#include<bits/stdc++.h>
using namespace std;
double n,w;
int a[601];
int main()
{
	cin>>n>>w;
	for(int i=1;i<=n;i++)
	{
		int x,ed,cnt=0;
		cin>>x;
		a[x]++;
		ed=max(1.00,floor(i*w/100));
		for(int j=600;j>=0;j--)
		{
			cnt+=a[j];
			if(cnt>=ed)
			{
				cout<<j<<' ';
				break;
			}
		}
	}
	return 0;
}
