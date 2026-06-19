#include<bits/stdc++.h>
using namespace std;
int n;
int ans=0;
int r;
const int N=5e5+5;
int a[N];
int t[N];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>r;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]==r)
			ans++;
	}
	
	int j=1;
	while(j<n)
	{
		t[0]=a[j];
		for(int i=j;i<n;i++)
		{
			t[i]=t[i-1]^a[i];
			if(t[i]==r)
				ans++;
		}
		j++;
	}
	cout<<ans+1;
	
}
