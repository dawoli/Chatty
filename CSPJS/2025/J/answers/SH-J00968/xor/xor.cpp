#include<bits/stdc++.h>
using namespace std;
int n,k,a[50001];
int f[50001];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1; i<=n; i++)cin>>a[i];
	int hp,ep;
	bool bj=false;
	for(hp=1; hp<=n; hp++)
	{
		if(bj)hp--;
		bj=false;
		f[hp]=max(f[hp],f[hp-1]);
		int sxor=0;
		for(ep=hp; ep<=n; ep++)
		{
			sxor^=a[ep];
			if(sxor==k)
			{
				f[ep]=max(f[hp]+1,f[ep]);
				hp=ep+1;
				bj=true;
			}
		}
		for(int i=1; i<=n; i++)cout<<f[i]<<" ";
		cout<<endl;
	}
	cout<<f[n];
}
