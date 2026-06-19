#include <bits/stdc++.h>
using namespace std;
int t,n,k,q,r,c,l,cnt;
bool f=0;
int a[10010],b[10010];
vector<int>v[100010];
struct abc{
	int x,y,l;
}A[10010];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>t;
	while(t--){
		int m=0;
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++){
			cin>>b[i];
			int l=b[i]; 
			for(int j=1;j<=l;j++){
				cin>>v[i][j];
				if(v[i][j]==1){
					A[m++].x=i;
					A[m].y=j;
				}
			}
		}
		for(int i=1;i<=q;i++){
			cin>>r>>c;
			for(int j=1;j<=m;j++){
				for(int p=1;p<=b[i];p++){
					if(p==1){
						for(int z=p;z<=p+k;z++){
							if(z==c){
								cout<<1<<endl;
								f=1;
							}
						}
					} 
				}	
			} 
			if(f==0)cout<<0<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
