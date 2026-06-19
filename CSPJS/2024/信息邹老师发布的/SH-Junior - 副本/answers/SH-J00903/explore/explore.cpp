#include<iostream>
using namespace std;
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,m,k,ans=1;
		cin>>n>>m>>k;
		int x,y,d;
		cin>>x>>y>>d;
		char mp[1010][1010];
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>mp[i][j];
			}
		}
		x--;
		y--;
		mp[x][y]='1';
		while(k--){
			if(d==0){
				if(y+1<m&&mp[x][y+1]!='x'){
					if(mp[x][y+1]=='.'){
						ans++;
						mp[x][y+1]='1';
					}
					y++;
				}
				else d=(d+1)%4;
			}
			else if(d==1){
				if(x+1<n&&mp[x+1][y]!='x'){
					if(mp[x+1][y]=='.'){
						ans++;
						mp[x+1][y]='1';
					}
					x++;
				}
				else d=(d+1)%4;
			}
			else if(d==2){
				if(y-1>=0&&mp[x][y-1]!='x'){
					if(mp[x][y-1]=='.'){
						ans++;
						mp[x][y-1]='1';
					}
					y--;
				}
				else d=(d+1)%4;
			}
			else{
				if(x-1>=0&&mp[x-1][y]!='x'){
					if(mp[x-1][y]=='.'){
						ans++;
						mp[x-1][y]='1';
					}
					x--;
				}
				else d=(d+1)%4;
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
