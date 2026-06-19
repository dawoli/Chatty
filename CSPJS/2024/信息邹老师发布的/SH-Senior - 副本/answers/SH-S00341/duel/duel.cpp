#include<bits/stdc++.h>
using namespace std;

int n,i,t,p = 0,res = 0,r[200000];

int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(i = 0;i < n;i++)
	{
		cin>>t;
		r[t]++;
	}
	for(i = 0;i < 100100;i++)res = max(res,r[i]);
	cout<<res;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
