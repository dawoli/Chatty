#include<bits/stdc++.h>
using namespace std;
vector<int>v;
int s[110][110];
int fx[]={-1,1};
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m,a;
	cin>>n>>m>>a;
	v.push_back(a);
	for(int i=1;i<n*m;i++){
		int t;
		cin>>t;
		v.push_back(t);
	}
	sort(v.begin(),v.end());
	
	int nx=0,ny=0,t=1;
	s[nx][ny]=v[v.size()-1];
	for(int i=v.size()-2;i>=0;i--){
		int dx=nx+fx[t],dy=ny;
		if(dx>=n){
			dy++;
			dx=nx;
			t=0;
		}
		if(dx<0){
			dy++;
			dx=nx;
			t=1;
		}
		s[dx][dy]=v[i];
		nx=dx,ny=dy;
		
	}
	
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(s[i][j]==a){
				cout<<j+1<<" "<<i+1;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
	
	
	
	
	
} 
