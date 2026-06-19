#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >>n;
	int a,b,c; 
	cin >>a>>b >> c; 
	int maxn=max(a,max(b,c)); 
	if(a+b>maxn&&b+c>maxn&&a+c>maxn)cout<<1;
	 else cout << 0; 
	
	return 0;
}
