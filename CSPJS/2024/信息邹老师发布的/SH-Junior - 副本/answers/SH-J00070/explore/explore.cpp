#include <bits/stdc++.h>
using namespace std;
long long t,n,m,k,x,y,d,cnt;
string ls[1010];
bool vis[1010][1010];
void movego(){
	long long nextx=x,nexty=y;
	if(d == 0)nexty++;
	else if(d == 1)nextx++;
	else if(d == 2)nexty--;
	else nextx--;
	if(nextx>=0 and nextx < n and nexty>=0 and nexty < m and ls[nextx][nexty] == '.'){
		x = nextx;
		y = nexty;
	}
	else d = (d+1)%4;
	if(!vis[x][y]){
		vis[x][y] = 1;
		cnt++;
	}
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	for(int h=0;h<t;h++){
		cin>>n>>m>>k>>x>>y>>d;
		x--;y--;
		for(long long i=0;i<n;i++)cin>>ls[i];
		cnt = 1;
		for(int i=0;i<n;i++)for(int j=0;j<m;j++)vis[i][j] = 0;
		vis[x][y] = 1;
		for(long long i=0;i<k;i++)movego();
		cout<<cnt<<"\n";
	}
	return 0;
}
