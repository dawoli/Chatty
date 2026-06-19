#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
const int N1=2*1e5+10;
const int N2=1e5+10;
struct Node{
	int key;
	bool f;
}w[N1];
vector<Node> e[N2];
int T,n,k,q,l,s,r,c,ks;
bool flag;
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>T;
	while(T--){
		memset(e,{},sizeof(e));
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++){
			cin>>l;
			for(int j=0;j<l;j++){
				cin>>s;
				e[i].push_back({s,0});
			}
		}
		while(q--){
			flag=0;
			cin>>r>>c;
			for(int i=1;i<=n;i++){
				ks=0;
				for(int j=0;j<e[i].size();j++){
					ks=max(0,ks-1);
					if(ks>0)e[i][j].f=1;
					else e[i][j].f=0;
					if(e[i][j].key==1)ks=k; 
				}
			}		
			for(int i=1;i<r;i++){
				memset(w,{},sizeof(w));
				for(int j=1;j<=n;j++){
					for(int v=0;v<e[j].size();v++){
						if(e[j][v].f==1){
							if(w[e[j][v].key].key==0)
								w[e[j][v].key]={j,1};
							else w[e[j][v].key].key=-1;
						}	
					}
				}
				for(int j=1;j<=n;j++){
					ks=0;
					for(int v=0;v<e[j].size();v++){
						ks=max(ks-1,0);
						if(ks>0)e[j][v].f=1;
						else e[j][v].f=0;
						if(w[e[j][v].key].f&&w[e[j][v].key].key!=j)ks=k;
					}
				}	
			}
			for(int i=1;i<=n;i++){
				for(int j=0;j<e[i].size();j++){
					if(e[i][j].key==c&&e[i][j].f==1&&flag==0){
						cout<<1;
						flag=1;
						break;
					}
				}
			}
			if(!flag)cout<<0;
			cout<<'\n';
		}
	}
	return 0;
}
