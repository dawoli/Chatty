#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int T,n,k;
vector<int>vec[N];
int calc(vector<int>&A,int x){
	int ret=-1,l=0,r=A.size()-1;
	if(A.empty()){
		return 0;
	}
	while(l<=r){
		int mid=(l+r)>>1;
		if(A[mid]<=x){
			ret=mid,l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
    return ret+1;
}
int sum(vector<int>&A,int l,int r){
	return (calc(A,r)-calc(A,l-1))>0;
}
int main(){
	freopen("chain.in","r",stdin),freopen("chain.out","w",stdout); 
	cin>>T;
	while(T--){
		int T;
		cin>>n>>k>>T;
		for(int i=1,x;i<=n;i++){
			cin>>x,vec[i].clear();
			while(x--){
				int y;
				cin>>y,vec[i].push_back(y);
			}
		}
		for(int r,c;T--;){
			cin>>r>>c;
			if(r==1){
				int ans=0;
				for(int i=1;i<=n;i++){//就在这个串里面找
				    int id=0;
				    vector<int>A,B;
				    for(int j:vec[i]){
					    id++;
					    if(j==1){
					    	A.push_back(id);
					    }
					    if(j==c){
						    B.push_back(id);
					    }
				    } 
					for(int j:A){
						ans|=sum(B,j+1,k-1+j);
					}
				}
				cout<<ans<<'\n';
			}
			else{
				
			}
		}
	}
}
