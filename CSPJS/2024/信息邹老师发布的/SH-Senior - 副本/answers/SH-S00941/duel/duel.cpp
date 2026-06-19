#include<bits/stdc++.h>
using namespace std;
int r[100005],t,n,els;
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>t;
		r[t]++;
	}
	els=r[1];
	for(int i=2;i<=100000;i++)
		if(r[i]>0)
			els=max(els,r[i]);
	cout<<els<<endl;
	return 0;
}
