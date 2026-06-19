#include<bits/stdc++.h>
using namespace std;
vector<int> v[200010];
int w[200010];
void work(){
	int n,k,q;
	cin>>n>>k>>q;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		for(int j=1;j<=x;j++){
			int q;
			cin>>q;
			v.push_back(q);
		}
		
	}
	for(int i=1;i<=q;i++){
		int r,c;
		cin>>r>>c;
		bool p=false;
		for(int j=0;j<v[r%n].size();j++){
			if(v[r%n][j]==c){
				p=true;
				break;
			}
		}
		if(p==false){
			cout<<0<<"\n";
			return;
		}
	}
	v.clear();
	memset(w,0,sizeof(w));
	return;
}
int main(){
//	freopen("chain.in","r",stdin);
//	freopen("chain.out","w",stdout);
    int T;
    cin>>T;
    for(int i=1;i<=T;i++){
    	work();
	}
	return 0;
}
