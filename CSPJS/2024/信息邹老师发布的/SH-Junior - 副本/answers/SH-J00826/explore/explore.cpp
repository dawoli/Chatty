#include<bits/stdc++.h>
using namespace std;
int v[1005][1005];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","out",stdout);
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int m,n,k,x,y,d;
		cin>>m>>n>>k>>x>>y>>d;
		string s[1005];
		v[x][y]=1;
		for(int j=0;j<m;j++){
			cin>>s[i];
		}
		for(int j=0;j<k;j++){
			if(d==0){
				if(y!=n&&s[x-1][y]=='.'){
					v[x][y+1]=1;
					y++;
				}else{
					d=1;
				}
			}else if(d==1){
				if(x!=m&&s[x][y-1]=='.'){
					v[x+1][y]=1;
					x++;
				}else{
					d=2;
				}
			}else if(d==2){
				if(y!=1&&s[x-1][y-2]=='.'){
					v[x][y-1]=1;
					y--;
				}else{
					d=3;
				}
			}else if(d==3){
				if(x!=1&&s[x-2][y-1]=='.'){
					v[x-1][y]=1;
					x--;
				}else{
					d=0;
				}
			}
		}
		int count=0;
		for(int j=1;j<1005;j++){
			for(int l=1;l<1005;l++){
				if(v[j][l]==1){
					count++;
					v[j][k]=0;
				}
			}
		}
		cout<<count<<endl;
	}
}
