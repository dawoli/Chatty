#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,d,x,y;
char mymap[1001][1001];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int ans;
bool flag[1001][1001];
void search(int q, int f,int ddx,int ddy){
	if(q==0){
		return ;
	}
	int myx=ddx+dx[f],myy=ddy+dy[f];
//	cout<<q<<" "<<f<<" "<<myx<<" "<<myy<<" ";
	if(mymap[myy][myx]=='.' && myx>0 && myx<=n && myy>0 && myy<=m){
		//cout<<"Y"<<endl;
		if(!flag[myy][myx]) ans++;
		flag[myy][myx]=1;
		search(q-1,f,myx,myy);
	}
	else{
		//cout<<"N"<<endl;
		search(q-1,(f+1)%4,ddx,ddy);
	}
	
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n>>m>>k>>x>>y>>d;
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				cin>>mymap[i][j];
			}
		}
		search(k,d,x,y);
		cout<<ans+1<<endl;
	}
	return 0;
}

