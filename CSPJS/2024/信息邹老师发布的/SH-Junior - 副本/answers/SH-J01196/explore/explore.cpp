//explore
#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,d;
char s[1002][1002]={};
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;++i){
		cin>>n>>m>>k>>x>>y>>d;
		string a;
		for(int j=0;j<n;++j){
			cin>>a;
			for(int p=0;p<m;++p){
				s[j][p]=a[p];
			}
		}
		--x,--y;
		s[x][y]='o';
		for(int j=0;j<k;++j){
			int cx=x+dx[d],cy=y+dy[d];
			if(cx>=0 && cx<n && cy>=0 && cy<m){
				if(s[cx][cy]!='x'){
					x=cx,y=cy;
					s[cx][cy]='o';
				}
				else{
					d=(d+1)%4;
				}
			}
			else{
				d=(d+1)%4;
			}
		}
		int cnt=0;
		for(int p=0;p<n;++p){
			for(int q=0;q<m;++q){
				if(s[p][q]=='o'){
					++cnt;
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
