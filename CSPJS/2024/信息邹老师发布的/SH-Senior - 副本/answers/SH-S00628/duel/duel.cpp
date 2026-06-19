#include<bits/stdc++.h>
using namespace std;
int n,tong[100005];
int ct,sy=0;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	ct=n;
	int x;
	for(int i=1;i<=n;i++){
		cin>>x;
		tong[x]++;
	}
	for(int i=1;i<=100000;i++){
		if(tong[i]>0){
			ct-=min(tong[i],sy);
			sy=max(sy,tong[i]);
		}
	}
	cout<<ct;
	cout.flush();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
