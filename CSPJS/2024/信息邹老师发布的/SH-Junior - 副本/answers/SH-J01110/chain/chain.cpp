#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int T,n,k,Q;
int x[N],y[N],maxx,maxxnum;
int l[2*N];
int xz[2*N][110];
bool u[2*N][110];//i 可不可以再 j 轮 寄掉
int minn(int x,int y){
	return x > y ? y : x ;
}
signed main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n>>k>>Q;
		maxx=0,maxxnum=0;
		vector<int> vec[N];
		vector<pair<int,int>> to[2*N];
		for(int i=1;i<=n;i++){
			cin>>l[i];
			for(int j=1;j<=l[i];j++){
				int x;
				cin>>x;
				maxxnum=max(maxxnum,x);
				vec[i].push_back(x);
				to[x].push_back(make_pair(i,j-1));
			}
		}
		for(int i=1;i<=Q;i++){
			cin>>x[i]>>y[i];
			maxx=max(maxx,x[i]);
		}
		for(int i=0;i<=maxxnum;i++) for(int j=0;j<=maxx;j++) xz[i][j]=u[i][j]=0;
		queue<pair<int,int>> q;
		q.push(make_pair(1,0));
		while(!q.empty()){
			int q1=q.front().first,q2=q.front().second;
			if(q2==maxx) break;
			q.pop();
			int lastv=0,lasts=0;
			for(auto v:to[q1]){
				int v1=v.first,v2=v.second;
				if(xz[q1][q2]==v1) continue;
				if(v2==l[v1]-1) continue;
				int st=v2+1;
				if(v1==lastv) st=max(st,lasts+1);
				lastv=v1;
				for(int i=st;i<=minn(l[v1]-1,v2+k-1);i++){
					int now=vec[v1][i];
					lasts=i;
					if(u[now][q2+1]){
						if(xz[now][q2+1]!=v1) xz[now][q2+1]=0;
						continue;
					}
					xz[now][q2+1]=v1;
					q.push(make_pair(now,q2+1));
					u[now][q2+1]=1;
				}
			}
		}
		for(int i=1;i<=Q;i++) cout<<u[y[i]][x[i]]<<endl;
	}
	return 0;
}
//我永远喜欢珂朵莉 
/*
2024-PJ-T4
我们发现，这道题其实就是连边问你有没有从1到yi长度为xi的路径
观察到，xi特别小，考虑sig_li*max(xi)算法
然后我们发现，理论上优化一下bfs就可以过了？
时间复杂度 O(sig_li*max(xi)) :  对于每一层，最多搜sig_li个数 
*/ 
