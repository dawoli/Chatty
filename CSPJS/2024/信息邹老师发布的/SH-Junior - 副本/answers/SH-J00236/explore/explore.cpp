#include<bits/stdc++.h>
using namespace std;
int T,ans,mm[1005][1005],nx[5]{0,1,0,-1},ny[5]{1,0,-1,0};
char mmap[1005][1005];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	for(int i=0,n,m,k,ii=0;i<T;i++){
		ans=1;
		cin>>n>>m>>k;
		int x,y,d;
	    cin>>x>>y>>d;
	    mm[x][y]=1;
		string s;
		for(int j=1;j<=n;j++){
			cin>>s;
			for(int a=1;a<=m;a++){
				mmap[j][a]=s[a-1];
			}
	    }
	    for(int j=0;j<k;j++){
	    	if(mmap[x+nx[d]][y+ny[d]]=='.'&&x+nx[d]>0&&x+nx[d]<=n&&y+ny[d]>0&&y+ny[d]<=m){
	    		x+=nx[d];
	    		y+=ny[d];
	    		if(mm[x][y]==0){
	    			mm[x][y]=1;
	    			ans++;
				}
			}
			else d=(d+1)%4;
		}
		cout<<ans<<endl;
		for(int j=1;j<=n;j++){
			for(int a=1;a<+m;a++){
				mm[j][a]=0;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
