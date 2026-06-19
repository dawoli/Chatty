#include<iostream>
using namespace std;

int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	
	int t;
	cin>>t;
	while(t--){
//		int n,k,p;
//		cin>>n>>k>>p;
//		int c[100];
//		int a[100][100]={{0}};
//		for(int i=0;i<n;i++){
//			int size;
//			cin>>size;
//			for(int j=0;j<size;j++){
//				cin>>a[i][j];
//			}
//		}
//		for(int i=0;i<p;i++){
//			int r;
//			cin>>r>>c[i];
//			for(int j=0;j<n;j++){
//				if(a[i][j]==c[i]) cout<<1<<endl;
//				else cout<<0<<endl;
//			}
//		}
		int n,p,a;
		cin>>n>>p>>a;
		int b[100][100]={{-1}};
		for(int i=0;i<n;i++){
			int size;
			cin>>size;
			for(int j=0;j<size;j++){
				cin>>b[i][j];
			}
		}
		bool ans=false;;
		for(int i=0;i<p;i++){
			int c;
			cin>>a>>c;
			for(int j=0;j<n;j++){
				for(int k=0;k<n;k++){
					if(b[j][k]==c){
						ans=true;
					}
				}
			}
		}
		if(ans) cout<<1<<endl;
		else cout<<0<<endl;
	}
	return 0;
}
