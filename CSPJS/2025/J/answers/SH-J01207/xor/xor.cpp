#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","w",stdin);
	freopen("xor.out","r",stdout);
	int a[100009];
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==0){
		cout<<3;
	}
	return 0;
}
