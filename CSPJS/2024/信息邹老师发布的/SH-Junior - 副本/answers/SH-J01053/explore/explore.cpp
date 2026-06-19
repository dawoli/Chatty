#include <bits/stdc++.h>
using namespace std;
int T,n,m,k;
int x,y,d,t=0;
char a[1003][1003];
int c[10];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	for(int tw=1;tw<=T;tw++){
		int ans=1;
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++)
			    cin>>a[i][j];
		}
		while(t<k){
		if((d==0&&a[x][y+1]=='.')||(d==1&&a[x+1][y]=='.')||(d==2&&a[x][y-1]=='.')||(d==3&&a[x-1][y]=='.'))
            {
            	if(d==0) y++;
            	if(d==1) x++;
            	if(d==2) y--;
            	if(d==3) x--;
				ans++;
			}
        else 
        {
        	d++;
        	if(d==4) d=0;
		}
		t++;
		  }
		c[tw]=ans;}
	for(int i=1;i<=T;i++){
		cout<<c[i]<<endl;
	}
	return 0;
}
