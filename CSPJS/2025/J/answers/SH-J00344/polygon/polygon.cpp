#include<bits/stdc++.h>
using namespace std;

int n;
int sd[5005],ln[5005];
long long ans = 0;
long long twon[5005];

bool cmp(int a,int b){
	return a < b;
}

void s(int l,int n,int p){
	if(l > n){
		ans = (ans + twon[p - 1])%998%244%353;
		return;
	}
	for(int i = 1;i < p;i++){
		if(n - l < ln[i]){
			s(l + sd[i],n,i);
		}
	}
	return;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	twon[0] = 1;
	for(int i = 1;i < n - 1;i++){
		twon[i] = twon[i - 1] * 2;
	}
	for(int i = 1;i <= n;i++){
		cin >> sd[i];
	}
	sort(sd + 1,sd + n + 1,cmp);
	ln[0] = 0;
	for(int i = 1;i <= n;i++){
		ln[i] = ln[i - 1] + sd[i];
	}
	for(int i = 1;i <= n;i++){
		if(sd[i] < ln[i - 1]) s(0,sd[i],i);
	}
	
	cout << ans;
	return 0;
}
