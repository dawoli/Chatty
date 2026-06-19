#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int num[100005],conc[100005],par[100005];
int act=0,r,n,ans=0,curpos=1;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>r;
		num[r]++;
	}
	for(int i=0;i<=100002;i++){
		if(num[i]!=0){
			conc[act]=num[i];
			par[act]=num[i];
			act++;
		}
	}
	for(int i=0;i<act;i++){
		if(curpos<=i){
			curpos=i+1;
		}
		while(conc[i]>0 and curpos<act and curpos>i){
			if(conc[i]>par[curpos]){
				conc[i]-=par[curpos];
				curpos++;
			}
			else{
				par[curpos]-=conc[i];
				conc[i]=0;
			}
		}
		if(curpos>=act){
			ans+=conc[i];
		}
	}
	cout<<ans;
	return 0;
}
