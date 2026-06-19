#include<bits/stdc++.h>
using namespace std;
long long n,k,a[1010],s[1010],t[1010],ans;
bool check(int x,int l)
{
	for(int i=x;i<=x+l-1;++i)
		if(t[i]) return 1;
	return 0;
}
void fid(int x,int l)
{
	for(int i=x;i<=x+l-1;++i)
		t[i]=1;
	return;
}
int check2(int x,int l)
{
	int ll=0;
	for(int i=x;i<=x+l-1;++i) ll^=a[i];
	return ll;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	for(int i=1;i<=n;++i)
	{
		for(int j=1;i+j-1<=n;++j)
		{
			if(check(j,i)) continue;
			if(check2(j,i)==k)
			{
				ans++;
				fid(j,i);
			}
		}
	}
	cout<<ans;
}
