#include<iostream>
using namespace std;
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n,k,q;
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++){
			int cnt=0;
			while(cin>>a[i][a[i][0]++]){
				
			}
		}
		int r,c;
		cin>>r>>c;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=a[i][0];j++){
				if(a[j]==1){
					w1=j;
				}
				if(a[j]==c){
					w2=j;
				}
			}
			if(w2-w1<=k){
				cout<<1<<endl;
			}else{
				cout<<0<<endl;
			}
		}
	}
	return 0;
}
