#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n,k,q,r[N],c[N],l;
int mk[2*N];int last;
int f=0;
vector <int>s[N];
void dfs(int d,int t,int r,int c,int last){
	if(d==r&&t==c&&!f){
		cout<<1<<endl;
		f=1;
		return;
	}
	for(int i=0;i<n;i++){
		if(i!=last){
			for(int j=0;j<s[i].size();j++){
				if(d==1&&s[i][j]==1){
					for(int l=j+1;l<s[i].size();l++){
						dfs(d+1,s[i][l],r,c,j);
					}
				}
				else if(s[i][j]==t){
					for(int l=j+1;l<s[i].size();l++){
						dfs(d+1,s[i][l],r,c,i);
					}
				}
			}
		}	
	}
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n>>k>>q;
		for(int i=0;i<n;i++){
			cin>>l;
			for(int j=0;j<l;j++){
				int t;cin>>t;
				s[i].push_back(t);
				mk[t]=1;
			}
		}
		for(int i=0;i<q;i++){
			cin>>r[i]>>c[i];
		}
		for(int k=0;k<q;k++){
			if(mk[c[k]]==0){
				cout<<0<<endl;
				continue;
			}
			if(r[k]==1){
				int flag=0;
				for(int i=0;i<n;i++&&!flag){
					for(int j=0;j<s[i].size();j++&&!flag){
						if(s[i][j]==1){
							int flag=0;
							for(int l=j+1;l<s[i].size();l++){
								if(s[i][l]==c[k]) {
									cout<<1<<endl;
									break;
								}
							}
						}
					}
				}
				if(flag==0)	cout<<0<<endl;
				continue;
			}
			int f=0;
			dfs(0,0,r[k],c[k],0);
			if(f==0)	cout<<0<<endl;
		}
	}
}
