#include<bits/stdc++.h>
using namespace std;
const int N=1009;
char ch[N][N];
int cnt[N][N],cn;
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n,m,k;
		cin>>n>>m>>k;
		int x0,y0,d0;
		cin>>x0>>y0>>d0;
		int x=x0,y=y0,d=d0;
		cnt[x0][y0]++;
		for(int i=1;i<=n;i++)
		    for(int j=1;j<=m;j++)
		        cin>>ch[i][j];
	    for(int i=1;i<=k;i++){
	    	if(d==0){
	    		y++;
	    		if(x>n||y>m||x<1||y<1||ch[x][y]=='x') {
	    			y--;
	    			d=1;
				}
	    		cnt[x][y]++;
			}
			else if(d==1){
	    		x++;
	    		if(x>n||y>m||x<1||y<1||ch[x][y]=='x') {
	    			x--;
	    			d=2;
				}
	    		cnt[x][y]++;
			}
			else if(d==2){
	    		y--;
	    		if(x>n||y>m||x<1||y<1||ch[x][y]=='x') {
	    			y++;
	    			d=3;
				}
	    		cnt[x][y]++;
			}
			else{
	    		x--;
	    		if(x>n||y>m||x<1||y<1||ch[x][y]=='x') {
	    			x++;
	    			d=0;
				}
	    		cnt[x][y]++;
			}
		}
		for(int i=1;i<=n;i++)
		    for(int j=1;j<=m;j++)
		        if(cnt[i][j]) cn++; 
		cout<<cn<<endl;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++)
				cnt[i][j]=0;
		}
		cn=0;
	}
	return 0;
}
