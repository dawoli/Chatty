#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
} 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n*m+1]={};
	int sum;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1)sum=a[i];
	}
	sort(a+1,a+1+n*m,cmp);
	int q=1;
	for(;;q++){
		if(a[q]==sum)break;
	}
	int ans;
	if(q%n==0)ans=q/n,q=n;
	else {
		ans=q/n+1;
		q-=(ans-1)*n;
	}
	if(ans%2==0)cout<<ans<<' '<<m-q+1;
	else cout<<ans<<' '<<q;
	return 0;
}
