#include<bits/stdc++.h>
using namespace std;
int T,n[11],a[11][200005],b[11][20005],cnt[11];
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++){
		cin>>n[i];
		for(int j=1;j<=n[i];j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=T;i++){
	    while(b[i][n[i]+1]!=1){
	    	b[i][1]++;
	    	int jin=1;
	    	while(b[i][jin]==2){
	    		b[i][jin]=0;
	    		jin++;
	    		b[i][jin]++;
			}
			int maxx=0;
			for(int j=2;j<=n[i];j++){
				for(int k=j-1;k>=1;k--){
					if(b[i][j]==b[i][k]){
						if(a[i][j]==a[i][k]){
							maxx+=a[i][j];
						}
						break;
					}
				}
			}
			if(maxx>cnt[i]){
				cnt[i]=maxx;
			}
		}
		cout<<cnt[i]<<endl;
	}
	return 0;
}
