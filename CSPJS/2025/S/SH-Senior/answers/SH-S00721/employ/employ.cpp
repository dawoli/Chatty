#include<bits/stdc++.h>
using namespace std;
long long M=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	long long k=1;
	for(int i=1;i<=n;i++)
	k=k*i%M;
	cout<<k;
	return 0;
}
