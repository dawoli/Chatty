#include <bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,d,ans;
char s[1010][1010];
int main(){
	freopen("explore.in","r","in");
	freopen("explore.out","w","out");
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		ans=0;
		for(int j=0;j<n;j++){
			cin>>s[j];
		}
		for(;k>0;k--){
			if(d==0){
				if(s[x][y+1]=='.'||s[x][y+1]=='/'){
					y+=1;
					s[x][y+1]='/';
				}
				else{
					d=(d+1)%4;
				}
			}
			else if(d==1){
				if(s[x+1][y]=='.'||s[x+1][y]=='/'){
					x+=1;
					s[x+1][y]='/';
				}
				else{
					d=(d+1)%4;
				}
			}
			else if(d==2){
				if(s[x][y-1]=='.'||s[x][y-1]=='/'){
					y-=1;
					s[x][y-1]='/';
				}
				else{
					d=(d+1)%4;
				}
			}
			else if(d==3){
				if(s[x-1][y]=='.'||s[x-1][y]=='/'){
					x-=1;
					s[x-1][y]='/';
				}
				else{
					d=(d+1)%4;
				}
			}
		}
		for(int a=0;a<n;a++){
			for(int b=0;b<m;b++){
				if(s[a][b]=='/'){
					ans++;
				}
			}
		}
		cout<<ans;
	}
	
	return 0;
}
