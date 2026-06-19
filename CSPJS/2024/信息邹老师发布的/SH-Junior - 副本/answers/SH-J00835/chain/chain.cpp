#include<bits/stdc++.h>
using namespace std;
int t;
int n,k,q;
int l[100005],p[200005];
int r,c;
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>k>>q;
		memset(p,0,sizeof(p));
		vector<int> s[1005];
		int tmp;
		for(int i=1;i<=n;i++){
			cin>>l[i];
			s[i].push_back(0);
			for(int j=1;j<=l[i];j++){
				cin>>tmp;
				s[i].push_back(tmp);
				bool flag=false;
				for(int i=1;i<k;i++){
					if(l[j-i]==1){
						flag=true;
						break;
					}
				}
				if(flag)p[i]=true;
			}
		}
		for(int i=1;i<=q;i++){
			cin>>r>>c;
			if(r==1){
				if(p[c])cout<<1<<endl;
				else cout<<0<<endl;
				continue;
			}
		}
	}
	return 0;
}


