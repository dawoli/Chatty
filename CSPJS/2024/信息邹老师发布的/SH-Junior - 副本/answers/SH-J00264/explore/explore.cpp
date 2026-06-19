#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<queue>
typedef long long ll;
using namespace std;

int t;

ll k[10],m[10],n[10],d,cnt;

char w[1005][1005];
int cm[1005][1005];
bool chk(int x,int y,int v){
	if(x<=n[v]&&x>=1&&y<=m[v]&&y>=1&&w[x][y]=='.'){
		return true;
	}
	return false;
}
ll xx,yy,x,y;
void mk(){
	if(d==0){
		yy++;
	}
	if(d==1){
		xx++;
	}
	if(d==2){
		yy--;
	}
	if(d==3){
		xx--;
	}
}

int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n[i]>>m[i]>>k[i];
		cin>>x>>y>>d;
		
		for(int j=1;j<=n[i];j++){
			for(int s=1;s<=m[i];s++){
				cin>>w[j][s];
				cm[j][s]=0;
			}
		}
		cm[x][y]=1;
		for(int j=1;j<=k[i];j++){
			xx=x;
			yy=y;
			mk();
			bool flag=chk(xx,yy,i);
			if(flag==1){
				x=xx;
				y=yy;
				cm[x][y]=1;
			}
			else{
				d=(d+1)%4;
			}

		} 
		for(int j=1;j<=n[i];j++){
			for(int s=1;s<=m[i];s++){
				cnt+=cm[j][s];
			}
		} 
		cout<<cnt<<endl;
		cnt=0;
	}
	return 0;
} 
