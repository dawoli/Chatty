#include<bits/stdc++.h> 
using namespace std;

int main(){
	
	int t=10,n,m,k,x,y,s,cnt=1;
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	
    cin>>t;
	for(int a=0;a<=t;a++){
		cin>>n>>m>>k>>x>>y>>s;
    	string e[1002][1002];
		cnt=1;
		for(int h=0;h<=n;h++){	
			for(int l=0;l<=m;l++){
				cin>>e[h][l];
			}
		}
		for(int c=0;c<=k;c++){
			if(s==0){
				if((y+1)<m&&e[x][y+1]!="x"){
					e[x][y]="s";
					y=y+1;
					if(e[x][y]==".")cnt++;
				}
				else s=1;
			}
			if(s==1){
				if((x+1)<n&&e[x+1][y]!="x"){
					e[x][y]="s";
					x=x+1;
					if(e[x][y]==".")cnt++;
				}
				else s=2;
			}
			if(s==2){
				if((y-1)>0&&e[x][y-1]!="x"){
					e[x][y]="s";
					y=y-1;
					if(e[x][y]==".")cnt++;
				}
				else s=3;
			}
			if(s==3){
				if((x-1)>0&&e[x-1][y]!="x"){
					e[x][y]="s";
					x=x-1;
					if(e[x][y]==".")cnt++;
				}
				else s=0;
			}
		}
		cout<<cnt;
	}
	return 0;
}
