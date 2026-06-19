#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	cin>>T;
	for(int zzz=0;zzz!=T;zzz++){
		set<vector<long long>> ans;
		vector<string> mp;
		long long n,m,k;
		cin>>n>>m>>k;
		long long x,y;
		int d;
		cin>>x>>y>>d;
		for(int i=0;i!=n;i++){
			string temp;
			cin>>temp;
			mp.push_back(temp);
		}
		x--;
		y--;
		long long k1=k;
		vector<long long> tmp;
		tmp.push_back(x);
		tmp.push_back(y);
		ans.insert(tmp);
		int mv[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
		long long x1,y1;
		while(k1!=0){
			k1--;
			x1=x+mv[d][0];
			y1=y+mv[d][1];
			if(x1>=0 and x1<n and y1>=0 and y1<m and mp[x1][y1]=='.'){
				x=x1;
				y=y1;
				tmp[0]=x;
				tmp[1]=y;
				ans.insert(tmp);
			}
			else{
				d+=1;
				d%=4;
			}
		}
		cout<<ans.size()<<endl;
	}
	return 0;
} 
