#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,sum=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	    sum=(sum*i)%MOD;
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
