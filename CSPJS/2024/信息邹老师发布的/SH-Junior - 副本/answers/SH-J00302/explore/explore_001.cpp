#include<bits/stdc++.h>
using namespace std;
const int N=1005;
struct po{
	int n,m,k,x,y,d,cnt=1;
	char p[N][N];
	bool vis[N][N];
};
po cz[10];
void walk(int a,int b){
	if(a==0){
		cz[b].y+=1;
	}
	else if(a==1){
		cz[b].x+=1;
	}
	else if(a==2){
		cz[b].y-=1;
	}
	else{
		cz[b].x-=1;
	}
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>cz[i].n>>cz[i].m>>cz[i].k;
		cin>>cz[i].x>>cz[i].y>>cz[i].d;
		for(int j=1;j<=cz[i].n;j++){
			for(int q=1;q<=cz[i].m;q++){
				cin>>cz[i].p[j][q];
			}
		}
		cz[i].vis[cz[i].x][cz[i].y]=true;
	}
	for(int i=1;i<=t;i++){
		for(int j=1;j<=cz[i].k;j++){
			int tmp1=cz[i].x,tmp2=cz[i].y;
			walk(cz[i].d,i);
			if(cz[i].x<1||cz[i].y<1||cz[i].x>cz[i].n||cz[i].y>cz[i].m||cz[i].p[cz[i].x][cz[i].y]=='x'){
				cz[i].x=tmp1;cz[i].y=tmp2;
				cz[i].d=(cz[i].d+1)%4;
			}
			else{
				if(cz[i].vis[cz[i].x][cz[i].y]==false){
					cz[i].cnt++;
					cz[i].vis[cz[i].x][cz[i].y]=true;
				}
			}

		}
	}
	for(int i=1;i<=t;i++){
		cout<<cz[i].cnt<<endl;
	}
	return 0;
}
