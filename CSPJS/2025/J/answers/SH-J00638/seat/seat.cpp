#include<bits/stdc++.h>
using namespace std;
int n,m,b[100][100],tmp,ansx,ansy;
struct Node{
	int a,id;
}a[1005];
bool cmp(Node x,Node y){
	return x.a>y.a;
}
void dfs(int step,int x,int y,int fx){
	b[x][y]=step;
	if(step==tmp){
		ansx=x,ansy=y;
		return;
	}
	if(fx==1&&x==n)
		dfs(step+1,x,y+1,-1);
	else if(fx==-1&&x==1)
		dfs(step+1,x,y+1,1);
	else dfs(step+1,x+fx,y,fx);
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;++i){
		cin>>a[i].a;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;++i)
		if(a[i].id==1){
			tmp=i;
			break;
		}
	dfs(1,1,1,1);
	cout<<ansy<<' '<<ansx;
	return 0;
}

