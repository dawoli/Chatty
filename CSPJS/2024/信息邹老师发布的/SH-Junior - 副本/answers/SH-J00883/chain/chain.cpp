#include<iostream> 
#include<vector>
#include<cstring>
using namespace std;
int T,n,k,q,l,x,r,c,z;
vector<int> S[100000];
bool u[200000];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout); 
	cin>>T;
	for(int i=0;i<T;i++){
		for(int j=0;j<100000;j++){
			while(!S[j].empty()){
				S[j].pop_back();
			}
		}
		memset(u,0,sizeof(u));
		cin>>n>>k>>q;
		for(int j=0;j<n;j++){
			cin>>l;
			for(int m=0;m<l;m++){
				cin>>x;
				S[j].push_back(x);
			}
			for(int m=0;m<l;m++){
				if(S[j][m]!=1)continue;
				for(int n=m+1;n<min(m+k,l);n++){
					u[S[j][n]]=1;
				}
			}
		}
		for(int j=0;j<q;j++){
			cin>>r>>c;
			cout<<u[c]<<endl;
		}
	}
	return 0;
}
