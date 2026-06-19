#include<bits/stdc++.h>
using namespace std;
int T,n,m,k,xs,ys,ds,book[1005][1005],ans,xn,yn;
void dfs(int x,int y,int d,int tu){
	if(tu==0) return;
	if(d==0){xn=x;yn=y+1;}
	if(d==1){xn=x+1;yn=y;}
	if(d==2){xn=x;yn=y-1;}
	if(d==3){xn=x-1;yn=y;}
	if(book[xn][yn]!=0&&xn>=1&&xn<=n&&yn>=1&&yn<=m){
		if(book[xn][yn]==1){
			book[xn][yn]=2;ans++;
		}
		dfs(xn,yn,d,tu-1);
	}
	else{
		d=(d+1)%4;
		dfs(x,y,d,tu-1);
	}
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++){
		memset(book,0,sizeof(book));
		cin>>n>>m>>k>>xs>>ys>>ds;
		string a;
		for(int j=1;j<=n;j++){
			cin>>a;
			for(int l=1;l<=m;l++){
				if(a[l-1]=='.') book[j][l]=1;
			}
		}
		book[xs][ys]=2;
		ans=1;
		dfs(xs,ys,ds,k);
		cout<<ans<<endl;
	}
	return 0;
}
