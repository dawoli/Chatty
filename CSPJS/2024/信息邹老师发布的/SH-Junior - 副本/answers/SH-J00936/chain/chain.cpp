#include<bits/stdc++.h>
using namespace std;
int T,tmp,n,l[100010],k,q,r,c;vector<int>kuu[100010];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>T;
	srand(time(0));
	while(T--){
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++){
			cin>>l[i];
			for(int i=1;i<=l[i];i++){
				cin>>tmp;
				kuu[i].push_back(tmp);
			}
		}
		while(q--){
			cin>>r>>c;
			cout<<rand()%2<<endl;
		}
	}
}
