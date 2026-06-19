#include<bits/stdc++.h>
using namespace std;
long long n,cnt;
string card;
char hs[55][55];
int main()
{ 
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>card;
		if(hs[card[0]][card[1]]==0) 
		{
			hs[card[0]][card[1]]++;
			cnt++;
		}	
	}
	cout<<52-cnt;
	return 0;
}
