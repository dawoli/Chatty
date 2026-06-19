#include<bits/stdc++.h>
using namespace std;
int a[1009];
int main()
{
	freopen("polygon.in","w",stdin);
	freopen("polygon.out","r",stdout);
	int n;
	cin>>n;
	if(n==3){
		cout<<1;
		return 0;
	}
	else{
		cout<<n*2-1;
	}
}
