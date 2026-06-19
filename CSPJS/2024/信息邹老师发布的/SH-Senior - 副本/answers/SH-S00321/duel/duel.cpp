#include<bits/stdc++.h>
using namespace std;
int n,a[1000006],c[1000006];
bool isf[1000006],isd[1000006];
int find(int i)
{
	for(int ct=i+c[a[i]]-1;ct<=n;ct++)
	{
		if(a[ct]>a[i] && isd[ct]==0 && isf[ct]==0)return ct;
	}
	return -1;
}
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		c[a[i]]++;
	}
	sort(a+1,a+1+n);
	int ans=0;
	for(int i=1;i<=n;i++)if(isd[i]==0)
	{
		isd[i]=1;
		int k=find(i);
		if(k==-1)break;
		isf[k]=1;
		ans++;
	}
	cout<<n-ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
