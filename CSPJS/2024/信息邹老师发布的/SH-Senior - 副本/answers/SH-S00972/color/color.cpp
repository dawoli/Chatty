#include<iostream>
#include<cstdio>
using namespace std;

int T,n,a[3][200009],ans[200009],t1,t2,t,ans1,temp;

void solve(int d){
	if(d==n){
		temp=0;
		ans[t]=0;
		for(int i = 0; i < t1; i++){
			if(a[1][i]==temp){
				ans[t]+=a[1][i];
			}
			temp = a[1][i];
		}
		temp = 0;
		for(int i = 0; i < t2; i++){
			if(a[2][i]==temp){
				ans[t]+=a[2][i];
			}
			temp=a[2][i];
		}
		t++;
		return;
	}
	a[1][t1]=a[0][d];
	t1++;
	solve(d+1);
	t1--;
	a[2][t2]=a[0][d];
	t2++;
	solve(d+1);
	t2--;
	return;
}

int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin >> T;
	for(;T > 0; T--){
		t=0;
		cin >> n;
		for(int i = 0; i < n; i++)
		cin >> a[0][i];
		solve(0);
		ans1=0;
		for(int i = 0; i < t; i++){
			if(ans1<ans[i]){
				ans1=ans[i];
			}
		}
		cout << ans1;
	}
	return 0;
}
