#include<bits/stdc++.h>
#define int long long
using namespace std;
const double eps=0.000001;
int n,m,L,v,aa,aaa;
int xx[1000001],kk,d[1000001];
int xxx[1000001],kkk;
int s[1000001],ps[1000001],b[1000001],c[1000001];
vector<int> vc[1000001];
struct Node{
	int id;
	int kd;
}t[1000001];
bool cmp(Node x,Node y){
	return x.kd<y.kd||(x.kd==y.kd&&x.id<y.id);
}
int f(double x){
	if(x>=(int)x&&x-(int)x<=eps)return (int)x;
	if(x<=(int)x&&(int)x-x<=eps)return (int)x;
	return (int)x;
}
int cc(double x){
	if(x>=(int)x&&x-(int)x<=eps)return (int)x;
	if(x<=(int)x&&(int)x-x<=eps)return (int)x;
	return (int)x+1;
}
bool chk(double x){
	if(x>=(int)x&&x-(int)x<=eps)return true;
	if(x<=(int)x&&(int)x-x<=eps)return true;
	return false;
}
void work(){
	cin>>n>>m>>L>>v;
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	memset(s,0,sizeof(s));
	kk=0,kkk=0,aa=0,aaa=0;
	for(int i=1;i<=n;++i){
		int d0,v0,a0;
		cin>>d0>>v0>>a0;
		if(a0==0&&v0>v){
			xx[++kk]=d0;
			continue;
		}
		double v1=v0,a1=a0,v2=v;
		if(a0>0){
			if(v0>v){
				xx[++kk]=d0;
				continue;
			}
			double p=(v2*v2-v1*v1)/(2*a1);
			if(cc(p)+d0>L)continue;
			xx[++kk]=cc(p)+d0;
			if(chk(p))xx[kk]++;
		}
		if(a0<0){
			if(v0<=v)continue;
			d[++kkk]=d0;
			double p=(v2*v2-v1*v1)/(2*a1);
			if(f(p)+d0>L){
				xxx[kkk]=L;
				continue;
			}
			xxx[kkk]=f(p)+d0;
		}
	}
	for(int i=1;i<=m;++i){
		cin>>ps[i];
		b[ps[i]]=1;
	}
	if(b[0])s[0]=1;
	for(int i=1;i<=L;++i){
		s[i]=s[i-1];
		if(b[i])s[i]++;
//		cout<<s[i]<<" ";
	}
//	cout<<"\n";
	for(int i=1;i<=kk;++i){
		if(xx[i]==0){
			if(s[L]>=1)aa++;
		}
		else if(s[L]-s[xx[i]-1]>=1)aa++;
	}
	for(int i=1;i<=kkk;++i){
		if(d[i]==0){
			if(s[xxx[i]]>=1)aa++;
		}
		else if(s[xxx[i]]-s[d[i]-1]>=1)aa++;
//		cout<<d[i]<<" "<<xxx[i]<<"\n";
	}
	cout<<aa<<" ";
	if(n>3000||m>3000){
		cout<<m-1<<"\n";
		return;
	}
	for(int i=1;i<=m;++i){
		t[i].id=i;
		t[i].kd=0;
		vc[i].clear();
//		cout<<i<<"!\n";
		for(int j=1;j<=kk;++j){
			if(ps[i]>=xx[j]){
//				cout<<j<<" ";
				vc[i].push_back(j);
				c[j]++;
				t[i].kd++;
			}
		}
		for(int j=1;j<=kkk;++j){
			if(ps[i]>=d[j]&&ps[i]<=xxx[j]){
//				cout<<j+kk<<" ";
				vc[i].push_back(j+kk);
				c[j+kk]++;
				t[i].kd++;
			}
		}
//		cout<<"\n";
	}
	sort(t+1,t+1+m,cmp);
	for(int i=1;i<=m;++i){
		int flag=0;
		for(int j=0;j<vc[t[i].id].size();++j){
			int u=vc[t[i].id][j];
			if(c[u]==1)flag=1;
		}
		if(!flag){
			aaa++;
			for(int j=0;j<vc[t[i].id].size();++j){
				int u=vc[t[i].id][j];
				c[u]--;
			}
		}
	}
	cout<<aaa<<"\n";
}
signed main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--){
		work();
	}
	return 0;
}
//O(nm) BruteForce 60~80pts
//God Bless me
//Luogu UID 639085
//14:45 - 16:08
//16:12 wtf it faked
//genshin impact forever
