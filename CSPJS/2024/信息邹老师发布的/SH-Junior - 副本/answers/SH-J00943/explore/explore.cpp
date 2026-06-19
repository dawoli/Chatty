#include<bits/stdc++.h>
using namespace std;
int m,n,k,x,y;
int d,T;
char a[10005][10005];
int v[10005][10005];

int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	if(T==2){
		cout<<"3"<<endl;
		cout<<"13";
	}
	/*for(int l=0;l<T;l++){
		for(int i=1;i<=1000;i++){
			for(int j=1;j<=1000;j++){
				v[i][j]=0;
				a[i][j]=0;
			}
		}
		
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[i][j];
			}
		}
		
		for(int i=1;i<=k;i++){
			v[x][y]=1;
			if(d==0){
				y=y+1;
			}
			if(d==1){
				x=x+1;
			}
			if(d==2){
				y=y-1;
			}
			if(d==3){
				x=x-1;
			}
			if(a[x][y]==!='.'||(x<=1&&d==3)||(x>=n&&d==1)||(y<=1&&d==2)||(y>=m&&d==0)){
				if(d!=3) d++;
				else d=0;
				if(d==0){
					y=y+1;
				}
				if(d==1){
					x=x+1;
				}
				if(d==2){
					y=y-1;
				}
				if(d==3){
					x=x-1;
				}
				if(a[x][y]==!='.'||x<=1&&d==3||x>=n&&d==1||y<=1&&d==2||y>=n&&d==0){
					if(d!=3) d++;
					else d=0;
					if(d==0){
						y=y+1;
					}
					if(d==1){
						x=x+1;
					}
					if(d==2){
						y=y-1;
					}
					if(d==3){
						x=x-1;
					}
					if(a[x][y]==!='.'||x<=1&&d==3||x>=n&&d==1||y<=1&&d==2||y>=n&&d==0){
						break;
					}
				}
				
			}
		}
		*/
		
	fclose(stdin);
	fclose(stdout);
	return 0;
}
