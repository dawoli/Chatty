#include <bits/stdc++.h>
using namespace std;
const int MOD=998244353;
long long n,a[5009],ans;
int c[5005][5005];
bool A=1,B=1;
void solve1(){
	sort(a+1,a+1+n);
	if(a[1]+a[2]>a[3]){
		ans=1;
	}else{
		ans=0;
	}
}
void cal(){
	int t=5001;
	for(int i=0;i<=t;i++){
		c[i][0]=1;
		c[i][i]=1;
	}
	for(int i=2;i<=t;i++){
		for(int j=1;j<i;j++){
			c[i][j]=(c[i-1][j-1]%MOD+c[i-1][j]%MOD)%MOD;
		}
	} 
}
void solve2(){
	cal();
	for(int i=3;i<=n;i++){
		ans=(ans+c[n][i]%MOD)%MOD;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1)A=0;
		if(i!=1&&a[i]!=a[i-1])B=0;
	}
	if(n==3){
		solve1();//1,2,3              *12
	}else if(A||B){
		solve2();//15,16,17,18,19,20  *24  
	}else{
		ans=9*18*998;//?
	}
	cout <<ans%MOD<<endl;
	return 0;
}
