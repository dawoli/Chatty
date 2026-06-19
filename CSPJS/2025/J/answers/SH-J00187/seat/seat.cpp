#include<bits/stdc++.h>
using namespace std;
long long n,m,t,r;
long long a[1005];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	long long num = n * m;
	for(int i = 1;i <= num;i++) cin>>a[i];
	r = a[1];
	sort(a + 1,a + num + 1);
	for(int i = 1;i <= num;i++)
	{
		if(a[i] == r) t = num - i + 1;
	}
	//cout<<t<<endl;
	long long cnt = 0;
	for(int i = 1;i <= m;i++) //i 是列 
	{
		//cout<<i<<endl;
		if(i % 2 == 1)
		{
			for(int j = 1;j <= n;j++)// j 是行 
			{
				cnt++;
				//cout<<cnt<<endl;
				if(cnt == t) cout<<i<<" "<<j<<endl; 
			}
		}
		else
		{
			for(int j = n;j >= 1;j--)
			{
				cnt++;
				if(cnt == t) cout<<i<<" "<<j<<endl;
			}
		}
	}
	return 0;
}
