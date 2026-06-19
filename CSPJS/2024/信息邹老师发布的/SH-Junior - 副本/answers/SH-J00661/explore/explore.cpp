#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int t,n,m,k,x,y,d;
char vis[1005][1005];
short int dx[4]={0,1,0,-1};
short int dy[4]={1,0,-1,0};
vector<short> s[2];
int ri(int n){
	return (n+1)%4;
}
int main(){
	freopen("explore.in","w",stdin);
	freopen("explore.out","r",stdout); 
	cin>>t;
	int res=0;
	int rep=0;
	for(int p=1;p<=t;p++){
		res=0;
		rep=0;
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		s[0].push_back(x);
		s[1].push_back(y);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>vis[n][m];
			}
		}
		for(int i=0;i<k;i++){
			if(x+dx[d]>=1 and x+dx[d]<=n and y+dy[d]>=1 and y+dy[d]<=m and vis[x+dx[d]][y+dy[d]]!='x'){
				x+=dx[d];
				y+=dy[d];
				s[0].push_back(x);
				s[1].push_back(y);
			}
			else{
				d=ri(d);
			}
		}
		sort(s[0].begin(),s[0].end());
		for(int i=1;i<s[0].size();i++){
			if(s[0][i]==s[0][i-1] and s[1][i]==s[1][i-1]){
				rep++;
				cout<<s[0][i]<<" "<<s[1][i]<<endl;
			}
		}
		cout<<s[1].size()-rep;		
	}
	return 0;
}
