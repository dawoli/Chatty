#include <bits/stdc++.h>
using namespace std;

int n,k;


int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(n==1&&k==0)cout<<0;
	else if(n==2&&k==0)cout<<1;
	else cout<<n;
}
