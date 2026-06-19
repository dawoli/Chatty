#include <bits/stdc++.h>
using namespace std;
char a[100],b[100];
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,cnt=0,num=0;
	cin>>n;
	num=n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		for(int j=1;j<=i-1;j++)
		{
			if(a[i]==a[j] && b[i]==b[j])
			{
				num--;
				break;
			}
		}	
	}
	cnt=52-num;
	cout<<cnt;
	return 0;
} 
