#include<bits/stdc++.h>

using namespace std;

ifstream fin("chain.in");
ofstream fout("chain.out");
#define cin fin
#define cout fout
#define endl '\n'

#define ssiz(x) (signed)x.size()

const int N=2e5+9;
const int B=1e2;

int buc[N],stk[N],top;

int main(){
	int T;
	cin>>T;
	while(T--){
		int n,lim,q,mx=0;
		cin>>n>>lim>>q;
		vector<vector<int>> a,ept;
		for(int i=0,m;i<n;i++){
			cin>>m;
			a.push_back(vector<int>(m));
			ept.push_back(vector<int>(m,0));
			for(int j=0;j<m;j++) cin>>a.back()[j];
			for(int x:a.back()) mx=max(mx,x);
		}
		
		vector<int> ans(q,0);
		vector<vector<pair<int,int>>> qry(B+1,vector<pair<int,int>>());
		for(int i=0,x,t;i<q;i++){
			cin>>t>>x;
			qry[t].push_back({i,x});
			mx=max(mx,x);
		}
		
		auto f=ept;
		vector<int> cnt(mx+1,0),lst(mx+1,-1);
		cnt[1]=1;
		for(int clk=1;clk<=B;clk++){
			for(int i=0;i<n;i++){
				for(int j=0;j<ssiz(a[i]);j++){
					if(f[i][j]&&!buc[a[i][j]]){
						buc[a[i][j]]=1;
						stk[++top]=a[i][j];
					}
				}
				for(int j=0,pos=-1;j<ssiz(a[i]);j++){
					f[i][j]=((~pos)&&pos>=j-lim+1);
					if(cnt[a[i][j]]>buc[a[i][j]]) pos=j;
				}
				while(top) buc[stk[top--]]=0;
			}
			
			cnt=vector<int>(mx+1,0);
			lst=vector<int>(mx+1,-1);
			for(int i=0;i<n;i++){
				for(int j=0;j<ssiz(a[i]);j++){
					if(f[i][j]&&lst[a[i][j]]!=i) cnt[a[i][j]]++,lst[a[i][j]]=i;
				}
			}
			for(auto p:qry[clk]) ans[p.first]=cnt[p.second]>0;
		}
		
		for(int x:ans) cout<<x<<endl;
	}
	
	return 0;
}
