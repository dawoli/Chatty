#include<bits/stdc++.h>
using namespace std;
int n;
string S[53];
int result=52;
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i+=1)
	{
		cin>>S[i];
	}
	sort(S+1,S+n+1);
	for(int i=1;i<=n;i+=1)
	{
		if(i==1)
		{
			result-=1;
		}
		else
		{
			if(S[i]!=S[i-1])
			{
				result-=1;
			}
		}
	}
	cout<<result;
	return 0;
}
