#include<bits/stdc++.h>
using namespace std;
int T,n,m,k,x,y,d,ans,xa,ya;
bool a[1006][1006];
bool vst[1006][1006];
char z;
void solve(){
	ans=1,xa=x,ya=y,vst[xa][ya]=true;
	for(int p=1;p<=k;p++){
		if(d==0){
			if((ya==m)||(!(a[xa][ya+1])))
				d++;
			else
				if(!vst[xa][++ya]){
					ans++;
					vst[xa][ya]=true;
				}
		}
		else if(d==1){
			if((xa==n)||(!(a[xa+1][ya])))
				d++;
			else
				if(!vst[++xa][ya]){
					ans++;
					vst[xa][ya]=true;
				}
		}
		else if(d==2){
			if((ya==1)||(!(a[xa][ya-1])))
				d++;
			else
				if(!vst[xa][--ya]){
					ans++;
					vst[xa][ya]=true;
				}
		}
		else{
			if((xa==1)||(!(a[xa-1][ya])))
				d=0;
			else
				if(!vst[--xa][ya]){
					ans++;
					vst[xa][ya]=true;
				}
		}
	}	
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++){
		cin>>n>>m>>k>>x>>y>>d;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				vst[i][j]=false;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++){
				cin>>z;
				if(z=='.')
					a[i][j]=true;
				else
					a[i][j]=false;
			}
		solve();
		cout<<ans<<endl;	
	}
	return 0;
}
