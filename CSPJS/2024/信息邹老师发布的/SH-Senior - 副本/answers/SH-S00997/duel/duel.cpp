#include<bits/stdc++.h>
using namespace std;
int r[100010]={};
int hash1[100010]={};
int ans=0,n;
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{ 
		cin>>r[i];
		hash1[r[i]]++;
	}
	sort(r,r+n);
	for(int i=2;i<100010;i++)
	{
		hash1[i]=max(hash1[i],hash1[i-1]);
		ans=hash1[i];
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
