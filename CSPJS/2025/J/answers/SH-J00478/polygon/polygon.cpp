#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int n,m;
int a[maxn];
int ans1,ans2;
int main(){
	freopen("polygon.in","r",stdin);freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	cout<<n*2-1<<endl;
	return 0;
}
