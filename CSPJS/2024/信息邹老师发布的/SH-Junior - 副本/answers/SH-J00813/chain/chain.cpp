#include <bits/stdc++.h>
using namespace std;
bool canBe(int k,int exception,int character,vector<int> * S,int n,int depth){
	if(depth==0&&character==1) return true;
	if(depth==0) {
		return false;
	}
	bool out=false;
	for(int i=0;i<n;i++){
		if(i==exception){
			continue;
		}
		for(int j=0;j<S[i].size();j++){
			if(S[i][j]==character){
				for(int l=j-1;l>=0&&l>j-k;l--){
					//cout<<S[i][j]<<"->"<<S[i][l]<<" "; 
					out=out||canBe(k,i,S[i][l],S,n,depth-1);
					if(out){
						//cout<<"success"<<endl;
						break;
					}
				    //cout<<"break"<<endl; 
				}
			}if(out){
						break;
					}
		}
	}
	return out;
} 
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int T;
	cin>>T;
	for(int AzertyNovem=0;AzertyNovem<T;AzertyNovem++){
		int n,k,q;
		cin>>n>>k>>q; 
		vector<int> S[n];
		for(int i=0;i<n;i++){
			int num;cin>>num;
			S[i].resize(num);
			for(int j=0;j<num;j++){
				cin>>S[i][j]; 
			}
		}
		for(int i=0;i<q;i++){
			int r,c;
			cin>>r>>c;
			bool cb=canBe(k,-1,c,S,n,r);
			cout<<cb<<endl;
		}
	}
	return 0; 
} 
