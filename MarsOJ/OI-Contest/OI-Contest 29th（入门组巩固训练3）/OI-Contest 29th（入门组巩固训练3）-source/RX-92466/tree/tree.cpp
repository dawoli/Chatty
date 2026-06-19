#include<bits/stdc++.h>
using namespace std;
int a[1000001],b[1000001];
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	cout<<1;
	for(int i=1;i<=n;i++) cout<<b[i];
	return 0;
}
