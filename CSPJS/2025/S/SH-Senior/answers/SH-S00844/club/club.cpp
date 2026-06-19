#include<bits/stdc++.h>
std::ifstream fin("club.in");
std::ofstream fout("club.out");
using ll=long long;
using vi=std::vector<int>;
const int maxn=1e5+5;
int n,t,chos[maxn],cc,mid,prev[maxn],nxt[maxn];
bool isv[2];
vi a[maxn];
struct node{
	int i,val;
	bool operator<(node j) const{
		return val<j.val;
	}
};
int main(){
	fin>>t;
	while(t--){
			fin>>n;
			isv[0]=isv[1]=0;
			ll ans=0;
			nxt[0]=1;
			for(int i=1;i<=n;++i){
				prev[i]=i-1;
				nxt[i]=i+1;
				vi b(3);
				fin>>b[0]>>b[1]>>b[2];
				a[i]=b;
			}
			prev[n+1]=n,nxt[n+1]=n+1;
			std::sort(a+1,a+n+1,[&](vi i,vi j){return i[1]-i[0]<j[1]-j[0];});
			mid=n/2;
			for(int i=1;i<=n/2;++i) ans+=a[i][0],chos[i]=0;
			if(n%2==1){
				if(a[n/2+1][1]-a[n/2+1][0]>0) ans+=a[n/2+1][1],chos[n/2+1]=1;
				else ans+=a[n/2+1][0],mid=n/2+1,chos[n/2+1]=0;
			}
			for(int i=(n+1)/2+1;i<=n;++i) ans+=a[i][1],chos[i]=1;
			cc=0;
			std::priority_queue<node> anss[2];
			for(int i=1;i<=n;++i){
				int val=a[i][2]-a[i][chos[i]];
				anss[chos[i]].push(node{i,val});
			}
			while(cc<n/2){
				node x=anss[0].top(),y=anss[1].top();
				if(anss[0].size()>(n/2)){
					anss[0].pop();
					ans+=x.val;
					chos[x.i]=2;
					nxt[prev[x.i]]=nxt[x.i];
					prev[nxt[x.i]]=prev[x.i];
					if(x.i==mid) mid=nxt[mid];
					continue;
				}
				if(anss[1].size()>(n/2)){
					anss[1].pop();
					ans+=y.val;
					chos[y.i]=2;
					nxt[prev[y.i]]=nxt[y.i];
					prev[nxt[y.i]]=prev[y.i];
					continue;
				}
				if(chos[x.i]!=0){
					anss[0].pop();
					continue;
				}
				if(chos[y.i]!=1){
					anss[1].pop();
					continue;
				}
				if(!isv[chos[x.i]]){
					mid=nxt[mid];
					if(mid>0&&mid<=n&&a[mid][0]-a[mid][1]>0) x.val+=a[mid][0]-a[mid][1];
					mid=prev[mid];
				}
				if(!isv[chos[y.i]]){
					if(mid>0&&mid<=n&&a[mid][1]-a[mid][0]>0) y.val+=a[mid][1]-a[mid][0];
				}
				if(y.val>x.val) x=y;
				anss[chos[x.i]].pop();
				if(x.val<=0) break;
				nxt[prev[x.i]]=nxt[x.i];
				prev[nxt[x.i]]=prev[x.i];
				ans+=x.val;
				if(!isv[chos[x.i]]){
					if(chos[x.i]==0) mid=nxt[mid];
					if(mid>0&&mid<=n&&a[mid][chos[x.i]]-a[mid][!chos[x.i]]>0){
						chos[mid]=chos[x.i];
						anss[chos[x.i]].push(node{mid,a[mid][2]-a[mid][chos[mid]]});
						isv[!chos[x.i]]=0;
						if(chos[x.i]==1) mid=prev[mid];
					}
					else{
						isv[chos[x.i]]=1;
						if(chos[x.i]==0) mid=prev[mid];
					}
				}
				chos[x.i]=2;
				++cc;
			}
			fout<<ans<<std::endl;
	}
	return 0;
}