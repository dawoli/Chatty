#include<bits/stdc++.h>
using namespace std;
int n,k,a[100111][3]={0};
bool cmp(int c,int d)
{
	return (a[c][k]-max(a[c][(k+1)%3],a[c][(k+2)%3]))<=(a[d][k]-max(a[d][(k+1)%3],a[d][(k+2)%3]));
}
int solve()
{
	int ma=0,len;
	vector<int> b[3];
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i][0]>>a[i][1]>>a[i][2];
		if(a[i][0]>a[i][1] && a[i][0]>a[i][2])
		{
			b[0].push_back(i);
		}
		else
			if(a[i][1]>a[i][2])
				b[1].push_back(i);
			else
				b[2].push_back(i);
	}
	if(b[0].size()>b[1].size() && b[0].size()>b[2].size())
	{
		k=0;
	}
	else
		if(b[1].size()>b[2].size())
			k=1;
		else
			k=2;
	len=b[k].size();
	for(int i=0;i<b[(k+2)%3].size();i++)
		ma+=a[b[(k+2)%3][i]][(k+2)%3];
	for(int i=0;i<b[(k+1)%3].size();i++)
		ma+=a[b[(k+1)%3][i]][(k+1)%3];
	sort(b[k].begin(),b[k].end(),cmp);
	for(int i=0;i<len;i++)
	{
		if(i<len-n/2)
			ma+=max(a[b[k][i]][(k+2)%3],a[b[k][i]][(k+1)%3]);
		else
			ma+=a[b[k][i]][k];
	}
	cout<<ma<<endl;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int m=0;m<t;m++)
		solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
