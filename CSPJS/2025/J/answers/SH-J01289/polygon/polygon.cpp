#include<bits/stdc++.h>
using namespace std;
int a[110],n,ans;
void stk(int num,int lst,int cnt){
	if(num==0){
		if(a[lst]<cnt) ans++,ans%=998244353;
		return;
	}
	cnt+=a[lst];
	for(int i=lst+1;i<=n-num+1;i++) stk(num-1,i,cnt);
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++) stk(i,0,0);
	cout<<ans%998244353;
	return 0;
}//24%(+?)
