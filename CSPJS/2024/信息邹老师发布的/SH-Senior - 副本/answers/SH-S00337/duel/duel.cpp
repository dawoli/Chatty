#include <bits/stdc++.h>
using namespace std;
int n,r1[100001],pai[100001];
int maxi=0, ans=0;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>r1[i];
		pai[r1[i]]+=1;
		maxi=max(maxi,r1[i]);
	}
	for(int j=1;j<maxi;j++){
		int he=0;
		for(int i=1;i<=j;i++)
			he=he+pai[i];
		if(pai[j+1]>=he)
			for(int i=1;i<=j;i++)	pai[i]=0;
		else{
			he=he-pai[j+1];
			for(int i=1;i<=j;i++)	pai[i]=0;
			pai[j]=he;
		}
	}
	for(int i=1;i<=maxi;i++)	ans=ans+pai[i];
	cout<<ans;
	return 0;
}
