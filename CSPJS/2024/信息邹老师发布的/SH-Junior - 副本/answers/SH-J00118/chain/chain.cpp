#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,k,q;
		cin>>n>>k>>q;
		int a[100002][200003]={};
		for(int i=0;i<n;i++){
			int l;
			cin>>l;
			a[i][0]=l;
			for(int j=1;j<=l;j++)cin>>a[i][j];
		}
		while(q--){
			int r,c;
			cin>>r>>c;
			bool f=0;
			for(int i=0;i<n&&!f;i++){
				for(int j=1;j<=a[i][0];j++){
					if(a[i][j]==c){
						f=1;
						break;
					}
				}
			}
			cout<<f<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
