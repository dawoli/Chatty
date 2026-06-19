#include<bits/stdc++.h>
using namespace std;
int t,n,m,k;
int x,y,d;
int sum=0;
char s[10005][10005];
bool flag[10005][10005]={};
int main(){
	freopen("explore.in",r,stdin);
	freopen("explore.ans",w,stdout);
    cin>>t;
    while(t!=0){
    	memset(flag,0,sizeof(flag));
    	sum=0;
    	cin>>n>>m>>k;
    	cin>>x>>y>>d;
    	for(int i=1;i<=n;i++){
    		for(int j=1;j<=m;j++){
    			cin>>s[i][j];
			}
		}
		if(s[x][y]=='.') sum++;
		while(k!=0){
			if(d==0){
				if(x<=n && y+1<=m && s[x][y+1]=='.'){
					if(flag[x][y+1]!=1)
					    sum++;
					y=y+1;
					flag[x][y]=1;
				}else{
					d=(d+1)%4;
				}
				k--;
				continue;
			}
			else if(d==1){
				if(x+1<=n && y<=m && s[x+1][y]=='.'){
					if(flag[x+1][y]!=1) 
				    sum++;
					x=x+1;
					flag[x][y]=1;
				}else{
					d=(d+1)%4;
				}
				k--;
				continue;
			}
			else if(d==2){
				if(x<=n && y-1<=m && s[x][y-1]=='.'){
					if(flag[x][y-1]!=1) sum++;
					y=y-1;
					flag[x][y]=1;
				}else{
					d=(d+1)%4;
				}
				k--;
				continue;
			}
			else{
				if(x-1<=n && y<=m && s[x-1][y]=='.'){
					if(flag[x-1][y]!=1) sum++;
					x=x-1;
					flag[x][y]=1;
				}else{
					d=(d+1)%4;
				}
				k--;
				continue;
			}
		}
		cout<<sum<<"\n";
		t--;
	}
	return 0;
}

