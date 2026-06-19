#include <bits/stdc++.h>
using namespace std;
int n,m,a[1000],cnt=1,ans_n,ans_m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	for(int i=2;i<=n*m;i++){
		if(a[i]>a[1])cnt++;
	}
	ans_m=ceil(cnt*1.0/n);
	cnt%=n;
	if(cnt==0){
		if(ans_m%2==0){
			ans_n=1;
		}else{
			ans_n=n;
		}
	}
	else {
		if(ans_m%2==0){
			ans_n=n-cnt+1;
		}else{
			ans_n=cnt;
		}
	}
	cout<<ans_m<<" "<<ans_n;
	return 0;
}
