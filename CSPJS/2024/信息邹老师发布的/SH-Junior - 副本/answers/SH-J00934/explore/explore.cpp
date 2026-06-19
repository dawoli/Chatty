#include<bits/stdc++.h>
using namespace std;
int T,n,m,k,x,y,d,ans=1;
char s[(int)1e3+5][(int)1e3+5];
int mk[(int)1e3+5][(int)1e3+5];
void F(){
	int tx=x,ty=y;
	if(d==0){
		ty++;
		if(tx>=1&&ty>=1&&tx<=n&&ty<=m){
			if(s[tx][ty]=='.'){
				if(mk[tx][ty]==0){
					ans++;
					mk[tx][ty]=1;
				}
				y++;
			}
			else	d=(d+1)%4;
		}
		else	d=(d+1)%4;
	}
	else if(d==1){
		tx++;
		if(tx>=1&&ty>=1&&tx<=n&&ty<=m){
			if(s[tx][ty]=='.'){
				if(mk[tx][ty]==0){
					ans++;
					mk[tx][ty]=1;
				}
				x++;
			}
			else	d=(d+1)%4;
		}
		else	d=(d+1)%4;
	}
	else if(d==2){
		ty--;
		if(tx>=1&&ty>=1&&tx<=n&&ty<=m){
			if(s[tx][ty]=='.'){
				if(mk[tx][ty]==0){
					ans++;
					mk[tx][ty]=1;
				}
				y--;
			}
			else	d=(d+1)%4;
		}
		else	d=(d+1)%4;
	}
	else if(d==3){
		tx--;
		if(tx>=1&&ty>=1&&tx<=n&&ty<=m){
			if(s[tx][ty]=='.'){
				if(mk[tx][ty]==0){
					ans++;
					mk[tx][ty]=1;
				}
				x--;
			}
			else	d=(d+1)%4;
		}
		else	d=(d+1)%4;
	}
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	while(T--){
		memset(mk,0,sizeof(mk));
		ans=1;
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		mk[x][y]=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>s[i][j];
			}
		}
		while(k){
			F();
			k--;
		}
		cout<<ans<<endl;
	}
}
