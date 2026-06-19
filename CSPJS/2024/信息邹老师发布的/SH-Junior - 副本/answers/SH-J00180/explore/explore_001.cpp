#include<bits/stdc++.h>
using namespace std;
int T,n,m,k,x,y,d;
string s;
vector<string> v;
vector<vector<bool> > vec;
int go(vector<string>& v,vector<vector<bool> >& vec){
	int cnt=1;
	for(int i=0;i<k;i++){
		if(d==0){
			if(y+1<=m){
				if(v[x-1][y]=='.'&& !vec[x-1][y]){
					y++;
					cnt++;
					vec[x-1][y]=1;
				}
				else d=1;
			}
			else d=1;
		}
		else if(d==1){
			if(x+1<=n){
				if(v[x][y-1]=='.'&&!vec[x][y-1]){
					x++;
					cnt++;
					vec[x][y-1]=1;
				}
				else d=2;
			}
			else d=2;
		}
		else if(d==2){
			if(y-1>0){
				if(v[x-1][y-2]=='.'&& !vec[x-1][y-2]){
					y--;
					cnt++;
					vec[x-1][y-2]=1;
				}
				else d=3;
			}
			else d=3;
		}
		else if(d==3){
			if(x-1>0){
				if(v[x-2][y-1]=='.'&& !vec[x-2][y-1]){
					x--;
					cnt++;
					vec[x-2][y-1]=1;
				}
				else d=0;
			}
			else d=0;
		}
	}
	return cnt;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	vector<int> ans(T);
	for(int i=0;i<T;i++){
		cin>>n>>m>>k>>x>>y>>d;
		vec.resize(n);
		for(int i=0;i<n;i++)
			vec[i].resize(m);
		for(int i=0;i<n;i++){
			cin>>s;
			v.push_back(s);
		}
		ans.at(i)=go(v,vec);
		v.clear();
	}
	for(int i=0;i<ans.size();i++)
		cout<<ans.at(i)<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
