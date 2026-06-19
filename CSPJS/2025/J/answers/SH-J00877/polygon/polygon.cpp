#include<bits/stdc++.h>
#define Mod 998244353
using namespace std;
int N,l[5005],pre[5005],Ans;
int main(){
	freopen("polygon.in","r",stdin);freopen("polygon.out","w",stdout);
	cin>>N;
	for(int i=1;i<=N;i++){
		cin>>l[i];
	}sort(l+1,l+1+N);
	for(int i=1;i<(1<<N);i++){
		int now=0,mx=0;
		for(int j=0;j<N;j++){
			if(i&(1<<j))now+=l[j+1],mx=max(mx,l[j+1]);
		}if(now>mx*2){
			Ans=(Ans+1)%Mod;
		}
	}
	cout<<Ans<<endl;
	return 0;
}
