#include<bits/stdc++.h>
using namespace std;
constexpr int N = 100000;
int a[N][3],tar;
vector<int> vs[3];
bitset<N> vis;
struct DAT{
	int num,val,to;
	DAT(int x, int y, int z) :
		num(x),val(y),to(z){
	}
};
inline bool comp(DAT i, DAT j){
	return i.val<j.val;
}
void run(){
	for(int i=0;i<3;++i) vs[i].clear();
	int n,ans=0;
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
		const int mx=max(a[i][0],max(a[i][1],a[i][2]));
		if(mx==a[i][0]) vs[0].push_back(i);
		else if(mx==a[i][1]) vs[1].push_back(i);
		else if(mx==a[i][2]) vs[2].push_back(i);
		ans+=mx,vis[i]=false;
	}
	if(vs[0].size() > n/2) { tar=0; }
	else if(vs[1].size() > n/2) { tar=1; }
	else if(vs[2].size() > n/2) { tar=2; }
	else{ cout<<ans<<endl; return; }
	
	vector<DAT> vec;
	for(int i=0;i<vs[tar].size();++i){
		int mxj,mnj;
		const int now=vs[tar][i];
		if(a[now][(tar+1)%3]>a[now][(tar+2)%3]) mxj=(tar+1)%3,mnj=(tar+2)%3;
		else mxj=(tar+2)%3,mnj=(tar+1)%3;
		vec.push_back(DAT(now,a[now][tar]-a[now][mxj],mxj));
		vec.push_back(DAT(now,a[now][tar]-a[now][mnj],mnj));
	}
	sort(vec.begin(),vec.end(),comp);
	
	int cnt=0;
	for(int i=0;vs[tar].size()-cnt>n/2;++i){
		if(!vis[vec[i].num]){
			if(vs[vec[i].to].size()+1<=n/2){
				ans-=vec[i].val;
				vs[vec[i].to].push_back(vec[i].num);
				vis[vec[i].num]=true;
				cnt++;
				continue;
			}
			const int now=vec[i].num;
			const int func1=a[now][tar]-max(a[now][(tar+1)%3],a[now][(tar+2)%3]);
			const int func2=a[now][tar]-min(a[now][(tar+1)%3],a[now][(tar+2)%3]);
			if(vec[i].val==func2 && !vs[vec[i].to].empty()){
				auto& vc=vs[vec[i].to];
				int minj=0,minv=a[vc[0]][3-vec[i].to-tar]-a[vc[0]][vec[i].to];
				for(int j=0;j<vc.size();++j){
					auto k=vc[j];
					if(minv>a[k][3-vec[i].to-tar]-a[k][vec[i].to]) minj=k,minv=a[k][3-vec[i].to-tar]-a[k][vec[i].to];
				}
				if(minv+vec[i].val<func2){
					vc.erase(vc.begin()+minj);
					ans-=minv+vec[i].val;
					vis[vec[i].num]=true;
					cnt++;
				}
			}
		}
	}
	cout<<ans<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--) run();
	return 0;
}
