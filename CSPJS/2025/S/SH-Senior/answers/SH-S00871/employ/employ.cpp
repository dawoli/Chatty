#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
long long C(long long x,long long y){
	long long tmp=x;
	for(long long i = x-1;i>=1;i--){
		tmp*=x%MOD;
	}
	long long tmp1=y;
	for(long long i = y-1;y>=1;y--){
		tmp1*=y%MOD;
	}
	return tmp/(tmp1-tmp)%MOD; 
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	long long x=0;
	for(int i = m;i<=n;i++){
		x+=C(i,n);
	}
	cout<<x%MOD; 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
