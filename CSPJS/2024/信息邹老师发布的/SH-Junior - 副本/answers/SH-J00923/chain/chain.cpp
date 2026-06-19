#include <bits/stdc++.h>
using namespace std;
int T;
struct node{
	int lun,need,p;
};
int main(){
	
	cin.tie(0);
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	
	cin >> T;
	while(T){
		T--;
		int n,k,q;
		cin >> n >> k >> q;
		map<int,vector<int> > p[2005];
		map<int,set<int> > s[2005];
		int info[2005][2005];
		int length[2005];
		for(int i=1;i<=n;i++){
			int l;
			cin >> l;
			length[i] = l;
			for(int j = 1;j<=l;j++){
				cin >> info[i][j];
				//if(ms[i].count(info[i][j])<= 0) ms[i].insert(info[i][j]);
			}
				
		}
		for(int i= 1;i<=n;i++){
			for(int j= 1;j<= length[i]-k+1;j++){
				for(int w = 1;w<=k-1;w++){
					if(s[i][info[i][j+w]].count(info[i][j]) <= 0){
						s[i][info[i][j+w]].insert(info[i][j]);
						p[i][info[i][j+w]].push_back(info[i][j]);
					}
				}
			}
		}
		while(q){
			q--;
			int r,c;
			cin >> r >> c;
			queue<node> mq;
			for(int i =1;i<=n;i++)
				mq.push({0,c,i});
			bool flag = false;
			while(!mq.empty()){
				node now = mq.front();
				mq.pop();
				if(now.lun > r) continue;
				if(now.lun == r && now.need == 1){
					cout << 1 << endl;
					flag = true;
					break;
				}
				for(int i = 0;i<p[now.p][now.need].size();i++){
					for(int j =1;j<=n;j++){
						if(now.p != j)mq.push({now.lun + 1,p[now.p][now.need][i],j});
					}
				}
			}
			if(!flag){
				cout << 0<<endl;
			}
		}
	}
	
	
	
	return 0;
} 
