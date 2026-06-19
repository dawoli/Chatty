#include<bits/stdc++.h>
using namespace std;
const int N=1e6+1;
int t,n,k,q,r,c,l[N];
vector<int> s[N];
inline int dfs(int r,int c,int lastp,int tail)
{
	if(r==0) return c==tail;
	for(int p=1;p<=n;++p){
		if(p==lastp) continue;
		vector<int> a=s[p];
		//A 需要以元素 tail 开头
		int idx=1;
		while(a.size()>2){
			while(idx<a.size()&&a[idx]!=tail) ++idx;
			if(idx==a.size()) break;
			a.erase(a.begin()+1,a.begin()+idx);
			idx=1;
			vector<int> aa=a;
			while(aa.size()>2){
				if(aa.size()>k) continue;
				if(dfs(r-1,c,p,aa.back())) return 1;
				while(aa.size()>2){
					if(aa.size()>k) continue;
					aa.pop_back();
					if(dfs(r-1,c,p,aa.back())) return 1;
				}
			}
		}
	}
	return 0;
}
inline int get_answer(int r,int c)
{
	return dfs(r,c,0,1);
}
inline void solve()
{
	scanf("%d%d%d",&n,&k,&q);
	for(int i=1;i<=n;++i){
		scanf("%d",&l[i]);
		s[i]=vector<int>(l[i]+1);
		for(int j=1;j<=l[i];++j) scanf("%d",&s[i][j]);
	}
	for(int i=1;i<=q;++i){
		scanf("%d%d",&r,&c);
		printf("%d\n",get_answer(r,c));
	}
}
inline void Main()
{
	//abcdefghijklmnopqrstuvwxyz
	scanf("%d",&t);
	for(int i=1;i<=t;++i) solve();
}
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	Main();
	fclose(stdin);
	fclose(stdout);
 	return 0;
}

