#include<bits/stdc++.h>
using namespace std;
int N,K,s[500005],Ans,Xor[500005],ls=1,cnt;
int main(){
	freopen("xor.in","r",stdin);freopen("xor.out","w",stdout);
	cin>>N>>K;
	for(int i=1;i<=N;i++){
		cin>>s[i];Xor[i]=s[i]^Xor[i-1];
	}
	for(int r=1;r<=N;r++){
		int nx=Xor[r]^Xor[ls-1];
		if(nx==K||s[r]==K){
			ls=r+1;Ans++;continue;
		}
		for(int l=ls;l<=r;l++){
			nx=Xor[r]^Xor[l-1];
			if(nx==K){
				ls=r+1;Ans++;break;
			}
		}
	}cout<<Ans<<endl;
	return 0;
}
