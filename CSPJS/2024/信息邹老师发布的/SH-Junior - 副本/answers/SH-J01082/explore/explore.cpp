#include<iostream>
#include<vector> 
#include<cstring>
using namespace std;
#define maxn (1000+7)
string a[maxn]={};
bool vis[maxn][maxn]={};
int dx[]={0, 1, 0, -1};
int dy[]={1, 0, -1, 0};
vector<int> as;

int ans;
int n, m, k;
void search(int x, int y, int face){
	vis[x][y]=true;
	while(k--){		
		int newx=x+dx[face];		
		int newy=y+dy[face];
		if(newx<0 || newx>=n || newy<0 || newy>=m || a[newx][newy]=='x'){
			face=(face+1)%4;
			continue;
		}
		x=newx;
		y=newy;
		if(vis[x][y]==false){
			ans++;
			vis[x][y]=true;
		}
		continue;
	}
	
	return;
}

int main(){
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	
	int t=0;
	cin>>t;
	
	while(t--){
		cin>>n>>m>>k;
		int x=0, y=0, face=0;
		cin>>x>>y>>face;
		x--;
		y--;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		
		ans=1;
		memset(vis, false, sizeof(vis));
		search(x, y, face);
		cout<<ans<<endl;
	}
	
	return 0;
}
