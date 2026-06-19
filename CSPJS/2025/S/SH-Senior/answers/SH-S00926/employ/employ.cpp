#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
long long ans=0;
int c[505];
long long num[1005];
void p(){
	
}
void f(int step,int pat,int sum){
	if(step==n+1){
		if(sum>=m) ans++;
		return;
	} 
	if(pat<c[step]&&s[step-1]=='1'){
		f(step+1,pat,sum+1);
	}
	f(step+1,pat+1,sum);
}
int main(){
	freopen("employ1.in","r",stdin);
//	freopen("employ.out","w",stdout);
	
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	
	f(1,0,0);
	cout<<ans%998244353;
	return 0;
}
