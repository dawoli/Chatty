#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int T,n,k,q,r,c,len,nxt[100003],ans;
bool arv[100003][11][11];
bool legal(int pl,int r,int c){
//	cout<<pl<<' '<<r<<' '<<c<<endl;
	if(!arv[pl][10][c]) return 0;
	if(r==0&&c==1)return 1;
	if(r==0&&c!=1)return 0;
	for(int j=0;j<10;j++){
		if(arv[pl][j][c]){
			for(int u=0;u<n;u++)
				if(u!=pl) if(legal(u,r-1,j)) return 1;
		}
	}
	return 0;
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
    cin>>T;
    for(int o=0;o<T;o++){
        cin>>n>>k>>q;
        for(int i=0;i<n;i++){
        	cin>>len;
        	for(int j=0;j<len;j++) cin>>nxt[j];
        	for(int j=0;j<len;j++){
        		for(int e=1;e<k&&j+e<len;e++){
        			arv[i][nxt[j]][nxt[j+e]]=1;
        			arv[i][10][nxt[j+e]]=1; 
				}
			}
		}
		for(int i=0;i<q;i++){
			cin>>r>>c;
			ans=0; 
			for(int u=0;u<n;u++){
				if(r==1&&!arv[u][1][c])continue;
				if(legal(u,r,c)){
					ans=1;
					break;
				} 
			}
			if(ans)cout<<"1"<<endl;
			else cout<<"0"<<endl; 
    	}
    }
    return 0;
} 
