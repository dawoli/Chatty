#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,d,ans,a[1010][1010];
char s[1010][1010];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--){
		memset(a,0,sizeof(a));
		cin>>n>>m>>k>>x>>y>>d;
		ans=0;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				cin>>s[i][j];
			}
		}
		for(int i=1;i<=k;++i){
			a[x][y]=1;
			if(d==0){
			    if(y+1<=m&&s[x][y+1]=='.')
				   y++;
				else
				   d=1;
		    }else{
		    	if(d==1){
		    	   if(x+1<=n&&s[x+1][y]=='.')
		    	       x++;
		    	    else
		    	       d=2;
			    }else{
			    	if(d==2){
		    	       if(y-1>=1&&s[x][y-1]=='.')
		    	           y--;
		    	        else
		    	           d=3;
			        }else{
			        	if(d==3){
			        		if(x-1>=1&&s[x-1][y]=='.')
			        		   x--;
			        		else
			        		   d=0;
						}
					}
				}
			}
		}
		a[x][y]=1;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				if(a[i][j]==1) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
