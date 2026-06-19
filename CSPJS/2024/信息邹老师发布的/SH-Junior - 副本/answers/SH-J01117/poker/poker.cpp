#include <bits/stdc++.h>
using namespace std;
int t,sum;
string p;
int D[14],C[14],S[14],H[14];
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin >> t;
	for(int i=1;i<=t;i++)
	{
		cin >> p;
		if(p[0]=='D')
		{
			if(p[1]>='A' && p[1]<='Z')
				
				D[p[1]-'A'+1]++;
			else
				D[p[1]-'0']++;
		}
		if(p[0]=='C')
		{
			if(p[1]>='A' && p[1]<='Z')
				C[p[1]-'A'+1]++;
			else
				C[p[1]-'0']++;
		}		
		if(p[0]=='H')
		{
			if(p[1]>='A' && p[1]<='Z')
				H[p[1]-'A'+1]++;
			else
				H[p[1]-'0']++;
		}		
		if(p[0]=='S')
		{
			if(p[1]>='A' && p[1]<='Z')
				S[p[1]-'A'+1]++;
			else
				S[p[1]-'0']++;
		}		
	}
	for(int i=1;i<=13;i++)
	{
		if(D[i]>0)
			sum++;
	}
	for(int i=1;i<=13;i++)
	{
		if(C[i]>0)
			sum++;
	}
	for(int i=1;i<=13;i++)
	{
		if(S[i]>0)
			sum++;
	}
	for(int i=1;i<=13;i++)
	{
		if(H[i]>0)
			sum++;
	}
	cout << 52-sum;
	return 0;
}
