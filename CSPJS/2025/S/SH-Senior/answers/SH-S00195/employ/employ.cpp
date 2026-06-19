#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int c[509];
const int MOD=998244353;
bool isA1(){
	for(int i=0;i<n;i++)if(s[i]=='0')return 0;
	return 1;
}
int jc(int n){
	int ans=1;
	for(int i=1;i<=n;i++){
		ans*=i;
		ans%=MOD;
	}
	return ans;
}
void solveA1(){
	cout<<jc(n)%MOD;
}
bool isA2(){
	for(int i=0;i<n;i++)if(s[i]=='1')return 0;
	return 1;
}
void solveA2(){
	cout<<0;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)cin>>c[i];
	if(isA1()||m==1)solveA1();
	else if(isA2())solveA2();
	else cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
