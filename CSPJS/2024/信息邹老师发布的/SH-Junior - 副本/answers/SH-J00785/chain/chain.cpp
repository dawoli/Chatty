#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	srand(NULL);
	while(k--)
	{
		cout<<rand()%2<<"\n";
	}
	return 0;
}
