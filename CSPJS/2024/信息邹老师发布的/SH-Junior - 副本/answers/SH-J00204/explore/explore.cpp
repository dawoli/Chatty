#include<bits/stdc++.h>
using namespace std;
#define N 1005
char a[N][N];
int t;
string b;
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int n,m,k,d,x,y,count;
	cin>>t;
	for(int g=1;g<=t;g++){
		count = 1;
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int i=0;i<=n;++i)
			for(int j=0;j<=m;++j)a[i][j]=0;
		for(int i=1;i<=n;i++){
			cin>>b;
			for(int j=0;j<m;++j)
				if(b[j]=='.')a[i][j+1]=1;
				else a[i][j+1]=2; 
		}//maps
		a[x][y]=3;
		for(int i=1;i<=k;i++){
			if(d%4==0){
				if(a[x][y+1]==1){
					a[x][y+1]=3;
					y++;
					count++;
				}
				else if(a[x][y+1]==3){
					y++;
				}
				else d++;
				//
			}else if(d%4==1){
				if(a[x+1][y]==1){
					a[x+1][y]=3;
					x++;
					count++;
				}
				else if(a[x+1][y]==3){
					x++;
				}
				else d++;
				//
			}else if(d%4==2){
				if(a[x][y-1]==1){
					a[x][y-1]=3;
					y--;
					count++;
				}
				else if(a[x][y-1]==3){
					y--;
				}
				else d++;
				//
			}else if(d%4==3){
				if(a[x-1][y]==1){
					a[x-1][y]=3;
					x--;
					count++;
				}
				else if(a[x-1][y]==3){
					x--;
				}
				else d++;
			}
		}
		
		cout<<count<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
} 
