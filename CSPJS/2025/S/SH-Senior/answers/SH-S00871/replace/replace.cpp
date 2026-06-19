#include<bits/stdc++.h>
using namespace std;
map<string,string>mp;
map<string,int> vis;
const int N=2e5;
string dir[N] ;
int ans=0; 
int n,m;
void bfs(string x,string y){
	queue<string> q; 
	q.push(x);
	while(!q.empty()){
		if(x==y){
			ans+=1;
			q.pop();
		}
		for(int i = 1;i<=n;i++){
			string x1=dir[i];
			string x2=q.front();
			if(x.find(x1)<=50){
				x2.replace(x.begin()+x.find(x1),x.begin()+x1.size(),mp[x]);
				if(vis[x2]==0){
					q.push(x2); 
				}
			}
		} 
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	cin>>n>>m;
	int k=1;
	for(int i = 0;i<n;i++){
		string x1,y1;
		cin>>x1>>y1;
		mp[x1]=y1;
		mp[y1]=x1;
		dir[k]=x1; 
		k++;
	}
	for(int i = 0;i<m;i++){
		string x1,x2;
		cin>>x1>>x2;
		bfs(x1,x2);
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
