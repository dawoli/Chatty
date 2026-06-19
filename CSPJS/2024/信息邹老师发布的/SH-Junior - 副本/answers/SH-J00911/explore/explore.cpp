#include<bits/stdc++.h>
using namespace std;
char kk[1009][1009];
int l[1009][1009];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	cin>>T;
	int n,m,k;
	for(int qw=0;qw<T;qw++){
		cin>>n>>m>>k;
		int nx,ny,d;
		cin>>nx>>ny>>d;
		for(int i=0;i<1002;i++){
			for(int j=0;j<1002;j++){
				l[i][j]=0;
				kk[i][j]=0; 
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>kk[i][j]; 
			}
		}
		l[nx][ny]=1;
		for(int i=0;i<k;i++){
			if(d==0){
				if(kk[nx][ny+1]=='.'){
					ny++;
				}
				else{
					d=(d+1)%4;
				}
			}
			else if(d==1){
				if(kk[nx+1][ny]=='.'){
					nx++;
				}
				else{
					d=(d+1)%4;
				}
			}
			else if(d==2){
				if(kk[nx][ny-1]=='.'){
					ny--;
				}
				else{
					d=(d+1)%4;
				}
			}
			else{
				if(kk[nx-1][ny]=='.'){
					nx--;
				}
				else{
					d=(d+1)%4;
				}
			}
			l[nx][ny]=1;
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(l[i][j]==1){
					cnt++;
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
} 
