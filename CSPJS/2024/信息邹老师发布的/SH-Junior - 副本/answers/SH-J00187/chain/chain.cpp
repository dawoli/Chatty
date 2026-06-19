#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#define ll long long
using namespace std;
int T;
ll n,k,q;
vector<ll> w[1001];
ll f=1;
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++){
		cin>>n>>k>>q;
		int x,j=1;
		for(j=1;j<=n;j++){
			while(cin>>x){
				w[j].push_back(x);
			}
		}
		for(j=1;j<=q;j++){
			f=0;
			int r,c;
			cin>>r>>c;
			bool flag=0;
			int s,e;
			for(int k=1;k<=n;k++){
				s=-1,e=-1;
				for(int q=0;q<w[k].size();q++){
					if(w[k][q]==1){
						s=q;
					}
					if(w[k][q]==c){
						e=q;
					}
				}
				if(s!=-1 && e!=-1 && e-s+1<=k){
					f=1;
				}
			}
			cout<<f<<endl;
		}
	}
	return 0;
}
