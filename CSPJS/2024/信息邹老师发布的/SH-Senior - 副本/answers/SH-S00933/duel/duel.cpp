#include<bits/stdc++.h>
using namespace std;
int n,r,m=1,s[100005];
map<int,int> d;
map<int,int>::iterator mit;
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>r;
		d[r]++;
	}
	mit=d.begin();
	//cout<<mit->first<<" "<<mit->second<<endl;
	mit++;
	for(;mit!=d.end();mit++)
	{
		//cout<<mit->first<<" "<<mit->second<<endl;
		if(s[m-1]>mit->second)
			s[m]=s[m-1];
		else
			s[m]=mit->second;
		m++;
	}
	cout<<s[m-1]<<endl;
	return 0;
}
