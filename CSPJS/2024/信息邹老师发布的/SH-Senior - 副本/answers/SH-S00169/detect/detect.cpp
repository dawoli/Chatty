#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+5;
int T,n,m,L,V;
ll d[maxn],v[maxn],a[maxn];
ll tec[maxn];
map<int,bool>mptec;
map<int,bool>mpntec;
map<int,bool>mpcar;
vector<int> tectag;
struct node{
	int l;
	int r;
	int id;
	bool operator<(const node &aa)const{
		if(l==aa.l)return r>aa.r;
		return l>aa.l;
	}
};
priority_queue<node> q;
void solve(int j){
	if(a[j]>0){
		if(v[j]>V)q.push({d[j],L,j});
		else{
			ll len=(V*V-v[j]*v[j])/(2*a[j])+1;
			//if((V*V-v[j]*v[j])%(2*a[j])==0)len+=1;
			if(d[j]+len>L)return;
			q.push({d[j]+len,L,j});
		}
	}
	else if(a[j]==0){
		if(v[j]>V)q.push({d[j],L,j});
		return;
	}
	else if(a[j]<0){
		if(v[j]<=V)return;
		else{
			ll len=(v[j]*v[j]-V*V)/(2*(-a[j]));
			if((v[j]*v[j]-V*V)%(2*(-a[j]))==0)len-=1;
			if(d[j]+len>L)q.push({d[j],L,j});
			else q.push({d[j],d[j]+len,j});
			return;
		}
	}
}
bool judge(int l,int r){
	if(mptec[l]||mptec[r])return true;
	if(lower_bound(tec+1,tec+m+1,l)==lower_bound(tec+1,tec+m+1,r))return false;
	return true;
}
bool njudge(int l,int r){
	sort(tectag.begin(),tectag.end());
	if(mpntec[l]||mpntec[r])return true;
	if(lower_bound(tectag.begin(),tectag.end(),l)==lower_bound(tectag.begin(),tectag.end(),r))return false;
	return true;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>T;
	for(int i=1;i<=T;i++){
		memset(d,0,sizeof(d));
		memset(v,0,sizeof(v));
		memset(a,0,sizeof(a));
		memset(tec,0,sizeof(tec));
		mpntec.clear();
		mptec.clear();
		mpcar.clear();
		tectag.clear();
		cin>>n>>m>>L>>V;
		for(int j=1;j<=n;j++){
			cin>>d[j]>>v[j]>>a[j];
			solve(j);
		}
		for(int j=1;j<=m;j++){
			cin>>tec[j];
			mptec[tec[j]]=1;
		}
		sort(tec+1,tec+m+1);
		int ans=0;
		priority_queue<node> nq(q);
		while(q.size()){
			node nd=q.top();q.pop();
			int left=nd.l,right=nd.r,car=nd.id;
			if(judge(left,right)){
				ans++;
				mpcar[car]=1;
			}
		}
		//cout<<"-----------ans-------------"<<endl;
		cout<<ans<<' ';
		//int biaoji=-1;
		int num=0;
		while(nq.size()){
			node nd=nq.top();nq.pop();
			int left=nd.l,right=nd.r,car=nd.id;
			if(!mpcar[car])continue;
			if(njudge(left,right))continue;
			//tag this car
			if(nq.size()){
				priority_queue<node> nnq(q);
				while(nnq.size()){
					node nnd=nnq.top();nnq.pop();
					int nleft=nnd.l,nright=nnd.r,ncar=nnd.id;
					if(nleft!=left&&nright<right)right=nright;
				}
			}
			int tag=upper_bound(tec+1,tec+m+1,right)-tec-1;//tec[tag]Òª±ê¼Ç
			//cout<<tec[tag]<<endl;
			tectag.push_back(tec[tag]);
			mpntec[tec[tag]]=1;
			num++;
		}
		cout<<m-num<<endl;
		//cout<<"-----------ans-------------"<<endl;
	}
	return 0;
}
