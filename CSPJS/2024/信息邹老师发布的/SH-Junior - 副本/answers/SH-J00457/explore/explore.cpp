#include<bits/stdc++.h>
using namespace std;
char a[1005][1005];
bool bobb[1005][1005];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	int n,m,k,ans;
	for(int i = 1;i<= t;++i){
		ans=1;
		cin>>n>>m>>k;
		int b,c,d,x,y;
		cin>>b>>c>>d;
		for(int j = 1;j<= n;++j){
			for(int p= 1;p<= m;++p){
				cin>>a[j][p];
				bobb[j][p]=true;
			}
		}
		bobb[b][c]=false;
		for(int q = 1;q<= k;++q){
			if(d==0){
				x=b;
				y=c+1;
			}
			if(d==1){
				x=b+1;
				y=c;
			}
			if(d==2){
				x=b;
				y=c-1;
			}
			if(d==3){
				x=b-1;
				y=c;
			}
			if(a[x][y]=='.'&&x<=n&&y<=m&&x>0&&y>0){
				b=x;
				c=y;
				if(bobb[x][y]){
					ans++;
					bobb[x][y]=false;
				}
			}
			else{
				d=(d+1)%4;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
