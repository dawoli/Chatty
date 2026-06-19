#include<bits/stdc++.h>
using namespace std;
int fx[4]={0,1,0,-1};
int fy[4]={1,0,-1,0};
struct inf{
	int xx,yy,dd;
}r;
char dt[1001][1001];
int dt2[1001][1001];
int T,n,m,k,x,y,d,ans[10];
void cl(){
	for(int i = 0;i<1001;++i)
		for(int j = 0;j<1001;++j){
			dt[i][j]=' ';
			dt2[i][j]=0;
		}
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	for(int i =1;i<=T;++i){
		cl();
		cin>>n>>m>>k>>x>>y>>d;
		r.xx=x;r.yy=y;r.dd=d;
		ans[i]++;dt2[r.xx][r.yy]=1;
		for(int j = 1;j<=n;++j)
			for(int u = 1;u<=m;++u)
				cin>>dt[j][u];
		while(k>0){
			while(!(r.xx+fx[d]>0&&r.xx+fx[d]<=n&&r.yy+fy[d]>0&&r.yy+fy[d]<=m&&dt[r.xx+fx[d]][r.yy+fy[d]]=='.')){
				k--;
				d=(d+1)%4;
			}
			k--;
			r.xx+=fx[d];r.yy+=fy[d];
			if(dt2[r.xx][r.yy]==0)
				ans[i]++;
			dt2[r.xx][r.yy]=1;
		}
	}
	for(int i = 1;i<=T;++i)
		cout<<ans[i]<<endl;
	return 0;
}
