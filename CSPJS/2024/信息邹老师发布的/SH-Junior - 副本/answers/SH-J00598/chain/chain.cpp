#include<bits/stdc++.h>
using namespace std;
int T,n,k,q,l[100010],s[100010][2010],r,c;
int main(){
	ios::sync_with_stdio(0);
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++){
			cin>>l[i];
			for(int j=1;j<=l[i];j++){
				cin>>s[i][j];
			}
		}
		while(q--){
            cin>>r>>c;
            if(r==1){
                bool flag=false;
                for(int i=1;i<=n;i++){
                    for(int j=1;j<=l[i];j++){
                        if(s[i][j]==1){
                            for(int t=j+1;t<=min(j+k-1,l[i]);t++){
                                if(s[i][t]==c){
                            //    	cout<<i<<' '<<j<<' '<<t<<'\n'; 
                                    flag=true;
                                    break;
                                }
                            }
                        }
                        if(flag)break;
                    }
                    if(flag)break;
                }
                cout<<flag<<'\n';
                continue;
            }
		}
	}

	return 0;
}
//Y#C*GF@24

