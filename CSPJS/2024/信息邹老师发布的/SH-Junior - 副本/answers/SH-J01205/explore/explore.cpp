#include<bits/stdc++.h>
using namespace std;
int xwalk[4]={0,1,0,-1};
int ywalk[4]={1,0,-1,0};
bool forest[1010][1010];
bool visit[1010][1010];
int robotwalk(int n,int m,int d,int px,int py,int k,int visnum){
	if(k==0) return visnum;
	if(((px+xwalk[d]<=n&&px+xwalk[d]>0)&&(py+ywalk[d]<=m&&py+ywalk[d]>0))&&(forest[px+xwalk[d]][py+ywalk[d]]!=1)) px+=xwalk[d],py+=ywalk[d];
	else d+=1,d%=4;
	if(visit[px][py]==0){
		visnum++;
		visit[px][py]=1;
	}
	robotwalk(n,m,d,px,py,k-1,visnum);
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		for(int i=0;i<1010;i++) for(int j=0;j<1010;j++) visit[i][j]=0;
		int n,m,k,px,py,d;
		cin>>n>>m>>k>>px>>py>>d;
		char can_go;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>can_go;
				if(can_go=='.') forest[i][j]=0;
				else forest[i][j]=1;
			}
		}cout<<robotwalk(n,m,d,px,py,k,0)<<endl;
	}
	return 0;
}
