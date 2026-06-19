#include<bits/stdc++.h>
using namespace std;
int times;
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>times;
	for(int zzz=1;zzz<=times;zzz++){
		int caiguo=0;
		char forest[1005][1005];
		int n,m,ttt;
		cin>>n>>m>>ttt;
		int xxx,yyy,d;
		cin>>xxx>>yyy>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>forest[i][j];
			}
		}
		forest[xxx][yyy]='0';
		for(int i=1;i<=ttt;i++){
			if(d==0){
				if(yyy+1>m or forest[xxx][yyy+1]=='x'){
					d++;
				}
				else{
					yyy++;
					if(forest[xxx][yyy]!='0'){
						caiguo++;
						forest[xxx][yyy]='0';
					}
				}
			}
			else if(d==1){
				if(xxx+1>n or forest[xxx+1][yyy]=='x'){
					d++;
				}
				else{
					xxx++;
					if(forest[xxx][yyy]!='0'){
						caiguo++;
						forest[xxx][yyy]='0';
					}
				}
			}
			else if(d==2){
				if(yyy-1==0 or forest[xxx][yyy-1]=='x'){
					d++;
				}
				else{
					yyy--;
					if(forest[xxx][yyy]!='0'){
						caiguo++;
						forest[xxx][yyy]='0';
					}
				}
			}
			else{
				if(xxx-1==0 or forest[xxx-1][yyy]=='x'){
					d=0;
				}
				else{
					xxx--;
					if(forest[xxx][yyy]!='0'){
						caiguo++;
						forest[xxx][yyy]='0';
					}
				}
			}
		}
		cout<<caiguo+1<<endl;
	}
	return 0;
} 
