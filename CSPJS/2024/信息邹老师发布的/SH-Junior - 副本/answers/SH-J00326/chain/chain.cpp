#include<bits/stdc++.h>
using namespace std;
//QAQ
//WAW
//AWA
//OWO
//TWT
//TOT
//TTOTT
int t;
int n,k,q,l;
int ci[10001][20001];
struct Node{
	int r,c;
}te[100005];
int main(){
	freopen("chain.in","r",stdin);freopen("chain.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++){
			cin>>l;
			for(int j=1;j<=l;j++){
				cin>>ci[i][j];
			}
		}
		for(int i=1;i<=q;i++){
			cin>>te[i].r>>te[i].c;
		}
		for(int i=1;i<=q;i++){
			if((te[i].r+te[i].c)%n==0)cout<<1<<"\n";
			else cout<<0<<"\n";
		}
	}
	return 0;
}
