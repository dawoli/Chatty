#include <bits/stdc++.h>
using namespace std;
int T;int res[10];
bool vis[1009][1009];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++){
		int n,m,k,xx,yy,dd;int cnt=1;
		cin>>n>>m>>k>>xx>>yy>>dd;
		char s[1009][1009];
		for(int j=1;j<=n;j++){
			for(int l=1;l<=m;l++){
				cin>>s[j][l];
			}
		}
		if(n==1&&m==1){
			cout<<1<<endl;continue;
		} 
	 	if(n==1&&m==2){
			if(k==1){
				if(s[1][1]=='x'||s[1][2]=='x') cout<<1<<endl,continue;
				else{
					cout<<(dd==0?2:1)<<endl;continue;
				}
			}
		}
		/*bool flag=1;
		for(int j=1;j<=n;j++){
			for(int l=1;l<=m;l++){
				if(s[j][l]=='x') {
					flag=0;
				}
			}
		}
		if(n==1&&flag==1) {
			if(yy!=1&&yy!=m){
				if(dd==0){
					if(n-yy<=kk) cout<<k+1<<endl;
				}
			}
		}*/
		/*vis[n][m]=1;
		char s[1009][1009];
		for(int j=1;j<=n;j++){
			for(int l=1;l<=m;l++){
				cin>>s[j][l];
			}
		}
		/*for(int j=1;j<=n;j++){
			for(int l=1;l<=m;l++){
				cout<<s[j][l];
			}
		}*/
		//cout<<cnt<<endl;
		/*int p=0;
		for(int j=1;j<=k;j++){
			//cout<<i<<" "<<j<<endl;
			if(p==k){
				cout<<cnt<<endl;
				break;
			}
			if(dd==0){
				cout<<0<<endl;
				int a=xx;int b=yy+1;
				if(a>=1&&a<=n&&b>=1&&b<=m&&s[a][b]=='.'){
					xx=a;yy=b;
					if(vis[xx][yy]==0) cnt++;
					cout<<"cnt="<<cnt<<endl;p++;
					continue;
				}
				else{
					dd=1;cout<<"cnt="<<cnt<<endl;p++;
				}
			}
			if(dd==1){
				cout<<1<<endl;
				int a=xx+1;int b=yy;
				if(a>=1&&a<=n&&b>=1&&b<=m&&s[a][b]=='.'){
					xx=a;yy=b;
					if(vis[xx][yy]==0) cnt++;cout<<"cnt="<<cnt<<endl;
					p++;
					continue;
				}
				else{
					dd=2;cout<<"cnt="<<cnt<<endl;p++;
				}
			}
			if(dd==2){
				cout<<2<<endl;
				int a=xx;int b=yy-1;
				if(a>=1&&a<=n&&b>=1&&b<=m&&s[a][b]=='.'){
					xx=a;yy=b;
					if(vis[xx][yy]==0) cnt++;cout<<"cnt="<<cnt<<endl;
					p++;
					continue;
				}
				else{
					dd=3;cout<<"cnt="<<cnt<<endl;p++;
				}
			}
			if(dd==3){
				cout<<3<<endl;
				int a=xx-1;int b=yy;
				if(a>=1&&a<=n&&b>=1&&b<=m&&s[a][b]=='.'){
					xx=a;yy=b;
					if(vis[xx][yy]==0) cnt++;cout<<"cnt="<<cnt<<endl;
					p++;
					continue;
				}
				else{
					dd=0;j--;cout<<"cnt="<<cnt<<endl;p++;
				}
			}
		}
		for(int j=1;j<=n;j++){
			for(int l=1;l<=m;l++){
				vis[j][l]=0;
			}
		}*/
		//res[i]=cnt;
	}
	//for(int i=1;i<=T;i++) cout<<res[i]<<endl;
	return 0;
}
