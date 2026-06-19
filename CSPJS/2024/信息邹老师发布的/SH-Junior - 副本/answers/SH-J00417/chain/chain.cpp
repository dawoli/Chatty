#include<bits/stdc++.h>
using namespace std;
const int MAXN=10005,MAXL=20005; 
int T,n,k,q,a[MAXN][MAXL];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n>>k>>q;
		for(int i=0;i<n;i++){
			cin>>a[i][0];
			for(int j=1;j<=a[i][0];j++){
				cin>>a[i][j];
			}
		}
		bool flag=false;
		for(int i=0;i<q;i++){
			int r,c;
			cin>>r>>c;
			if(r==1){
				for(int m=0;m<n;m++){
					int temp=0;
					if(flag) break;
					for(int j=1;j<a[m][0];j++){
						if(temp>0&&temp<=k&&a[m][j]==c){
							cout<<1<<endl;
							flag=true;
							break;
						}
						if(a[m][j]==1){
							temp++;
						}
					}
				}
				if(!flag) cout<<0<<endl;
			}
		}
	}
	return 0;
} 
