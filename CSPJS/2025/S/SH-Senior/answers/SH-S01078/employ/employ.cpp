#include <bits/stdc++.h>
using namespace std;

int n,m;
string s;

long long jiecheng(int n){
	long long sum=1;
	for(int i=2;i<=n;i++){
		sum*=i;
		sum%=998244353;
	}
	return sum;
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	cout<<jiecheng(n);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
