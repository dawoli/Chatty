#include<bits/stdc++.h>
using namespace std;
int t,n,k,q,r,c;
bool b;
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>t;
	for(int no=0;no<t;no++){
		cin>>n>>k>>q;
		vector<int> l[1009];
		for(int i=0;i<n;i++){
			int w;
			cin>>w;
			for(int j=0;j<w;i++){
				int ak;
				cin>>ak;
				l[i].push_back(ak);
			}
		}
		for(int i=0;i<q;i++){
			cin>>r>>c;
			if(r==1){
				b=0;
				for(int i=0;i<n;i++){
					int sum=0;
					for(int j=0;j<l[i].size();j++){
						sum++;
						if(l[i][j]==1){
							sum=1;
						}
						if(l[i][j]==c&&sum<=k){
							b=1;
							break;
						}
					}
					if(b){
						cout<<1<<endl;
						break;
					}
				}
				if(!b){
					cout<<0<<endl;
				}
			}
			else{
				cout<<0<<endl;
			}
		}
	}
	return 0;
}
