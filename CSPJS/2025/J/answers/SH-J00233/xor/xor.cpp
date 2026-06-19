#include<bits/stdc++.h>
using namespace std;
int a[500010];
int n;
long long k;
int cnt0=0,cnt1=0;
void solve0(){
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(a[i]==1&&a[i+1]==0&&a[i-1]==1){
			cnt++;
		}
	}
	cout<<cnt+cnt0<<endl;
}
void solve1(){
	cout<<max(cnt0,cnt1)<<endl;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0)
			cnt0++;
		else
			cnt1++;
	}
	if(k==1){
		solve1();
	}
	else if(k==0){
		solve0();
	}
	else
		cout<<0<<endl;
	return 0;
}
