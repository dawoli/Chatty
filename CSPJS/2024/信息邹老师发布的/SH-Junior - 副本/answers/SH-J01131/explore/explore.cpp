#include<bits/stdc++.h>
using namespace std;
#define int long long
char a[1005][1005];

signed main(){
	ios::sync_with_stdio(false);
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);

	int t,n,m,k,x0,y0,d0,cnt=0;
	cin>>t;
	while (t--){
		cin>>n>>m>>k>>x0>>y0>>d0;
		for (int i=1;i<=n;i++){
			for (int j=1;j<=m;j++){
				cin>>a[i][j];
			}
		}
		
		while (k--){
			if (d0==0){
				if (a[x0][y0+1]=='.'){
					cnt+=1;
					a[x0][y0]='#';
					y0+=1;
//					cout<<x0<<' '<<y0<<' '<<cnt<<endl;
				}
				else if(a[x0][y0+1]=='#'){
					y0+=1;
				}
				else{
					d0=(d0+1)%4;
//					cout<<d0<<endl;
					continue;
					
					
				}
			}
			if (d0==1){
				if (a[x0+1][y0]=='.'){
					cnt+=1;
					a[x0][y0]='#';
					x0+=1;
//					cout<<x0<<' '<<y0<<' '<<cnt<<endl;
				}
				else if(a[x0+1][y0]=='#'){
					x0+=1;
				}
				else{
					d0=(d0+1)%4;
//					cout<<d0<<endl;
					continue;
				
				}
			}
			if (d0==2){
				if (a[x0][y0-1]=='.'){
					cnt+=1;
					a[x0][y0]='#';
					y0-=1;
//					cout<<x0<<' '<<y0<<' '<<cnt<<endl;
				}
				else if(a[x0][y0-1]=='#'){
					y0-=1;
				}
				else{
					d0=(d0+1)%4;
//					cout<<d0<<endl;
					continue;
				}
			}
			if (d0==3){
				if (a[x0-1][y0]=='.'){
					cnt+=1;
					a[x0][y0]='#';
					x0-=1;
//					cout<<x0<<' '<<y0<<' '<<cnt<<endl;
				}
				else if(a[x0-1][y0]=='#'){
					x0-=1;
				}
				else{
					d0=(d0+1)%4;
//					cout<<d0<<endl;
					continue;
				}
			}
		}
		cout<<cnt+1<<endl;
		cnt=0;
	}
	
	
	return 0;
}
