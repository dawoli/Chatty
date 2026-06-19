#include<bits/stdc++.h>
using namespace std;
int t,n,m,k;
int _xx,_yy,_dd;
int walk_wayhen[5]={1,0,-1,0};
int walk_wayshu[5]={0,1,0,-1};
char fost_mp[1005][1005];
bool _used[1001][1001];
long long int ans;
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--){
		ans=1;
		memset(_used,0,sizeof(_used));
		cin>>n>>m>>k;
		cin>>_xx>>_yy>>_dd;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
			cin>>fost_mp[i][j];
			}
		}
		_used[_xx][_yy]=1;
		for(int i=1;i<=k;i++){
			_xx+=walk_wayshu[_dd];
			_yy+=walk_wayhen[_dd];
			if(_xx<1||_xx>n||_yy<1||_yy>m||fost_mp[_xx][_yy]=='x'){
			_xx-=walk_wayshu[_dd];
			_yy-=walk_wayhen[_dd];
			_dd=(_dd+1)%4;
			}
			else{
				if(_used[_xx][_yy]==0){
					_used[_xx][_yy]=1;
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
