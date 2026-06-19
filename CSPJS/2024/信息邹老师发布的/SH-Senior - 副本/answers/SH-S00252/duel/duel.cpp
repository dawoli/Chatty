#include<bits/stdc++.h>
using namespace std;
int r[100010];
int cnt0[100010];
int cnt1[100010];
int cnt;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> r[i];
		cnt0[r[i]]++;
	}
	sort(r+1,r+n+1);
	for(int i=1;i<=100000;i++){
		if(cnt0[i]!=0){
			cnt++;
			cnt1[cnt]=cnt0[i];
		}
	}
	int ans=0;
	for(int i=1;i<=cnt;i++){
		if(cnt1[i]>=ans){
			ans=cnt1[i];
		}
	}
	cout << ans;
	return 0;
} 
