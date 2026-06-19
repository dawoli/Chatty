#include<bits/stdc++.h>
using namespace std;
int n,sum;
string s;
char a[55],b[55];
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		for(int j=1;j<i;j++)
		{
			if(a[i]==a[j]&&b[i]==b[j])
			{
				sum--;
				break;
			}
		}
		sum++;
	}
	cout<<52-sum;
	return 0;
}
