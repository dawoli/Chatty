#include<bits/stdc++.h>
using namespace std;
int n,kkksc03,a[100005],x,y,ans;
void solve1(){
	cout<<x/2;
	return;
}
void solve2(){
	if(kkksc03==1){
		cout<<x;
	}
	else{
		for(int i=1;i<=n;i++){
			if(a[i]==0)ans++;
			else if(a[i]==1&&a[i-1]==1){
				ans++;
				a[i+1]==0;
			}
		}
		cout<<ans;
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin.tie();
	cin>>n>>kkksc03;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1)x++;
		else if(a[i]==0)y++;
	}
	if(x==n){
		solve1();
	}
	else if(x+y==n){
		solve2();
	}
	return 0;
}
