#include<bits/stdc++.h>
using namespace std;
long long n,m,k,c[11],a[11][10004];
vector<long long> va[10004],vw[10004];
bool ok[10020];
bool tw[11];
long long fr[11];
struct rd{
	long long a,w,fm;
	bool operator<(const rd &r)const{
		if(w<r.w){
			return 1;
		}
		if(w>r.w){
			return 0;
		}
		if(a<r.a){
			return 1;
		}
		if(w>r.w){
			return 0;
		}
		if(fm<r.fm){
			return 1;
		}
		return 0;
	}
};
set<rd> s;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int ans=0;
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		long long a,b,c;
		cin>>a>>b>>c;
		va[a].push_back(b);
		vw[a].push_back(c);
		va[b].push_back(a);
		vw[b].push_back(c);
	}
	for(int i=0;i<k;i++){
		cin>>c[i];
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	ok[1]=1;
	for(int i=0;i<va[1].size();i++){
		rd r;
		r.a=va[1][i];
		r.w=vw[1][i];
		r.fm=-1;
		s.insert(r);
	}
	for(int i=0;i<k;i++){
		rd r;
		r.a=n+1+i;
		r.w=a[i][1];
		r.fm=i;
		s.insert(r);
	}
	while(!s.empty()){
		rd ra=*s.begin();
		s.erase(s.begin());
		if(ok[ra.a]){
			continue;
		}
		ok[ra.a]=1;
		if(ra.fm==-1){
			ans+=ra.w;
		}
		else if(!tw[ra.fm]){
			tw[ra.fm]=1;
			fr[ra.fm]=ra.w;
		}
		else{
			ans+=fr[ra.fm];
			ans+=ra.w;
			fr[ra.fm]=0;
		}
		if(ra.a<=n){
			for(int i=0;i<va[ra.a].size();i++){
				rd r;
				r.a=va[ra.a][i];
				r.w=vw[ra.a][i];
				r.fm=-1;
				s.insert(r);
			}
			for(int i=0;i<k;i++){
				rd r;
				r.a=n+1+i;
				r.w=a[i][ra.a];
				r.fm=i;
				s.insert(r);
			}
		}
		else{
			int ai=ra.a-n-1;
			for(int i=0;i<n;i++){
				rd r;
				r.a=i+1;
				r.w=a[ai][i];
				r.fm=ai;
				s.insert(r);
			}
		}
	}
	cout<<ans;
	return 0;
}
