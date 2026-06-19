#include<bits/stdc++.h>
using namespace std;
int T,n,k,q,l,r,a[2000002],b;
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++){
		cin>>n>>k>>q;
		int index=1;
		for(int j=1;j<=n;j++){
			cin>>l;
			int x=0,y;
			for(int m=1;m<=l;m++){
				cin>>y;
				if(x){
					a[index++]=y;
					x--;
				}
				if(y==1)x=k-1;
			}
		} 
		for(int j=1;j<=q;j++){
			cin>>r>>b;
			bool flag=false;
			for(int m=1;m<index;m++){
				if(a[m]==b){
					flag=true;
					cout<<1<<endl;
					break;
				}
			}
			if(!flag)cout<<0<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
