#include<bits/stdc++.h>
using namespace std;

const int N=1e4+25;

struct t{
	long long fr,to,co;
};

long long n,m,k,ans;
vector<t>a;
t s;
long long c[15];
int cnt,xz;
long long f[N];

bool cmp(t x,t y){
	return x.co<y.co;
}

long long find(long long u){
	if(f[u]==u){
		return u;
	}
	f[u]=find(f[u]);
	return f[u];
}

bool hb(long long x,long long y){
	long long fx=find(x),fy=find(y);
	if(fx==fy){
		return 0;
	}
	f[fx]=fy;
	return 1;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>s.fr>>s.to>>s.co;
		a.push_back(s);
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		xz=0;
		s.fr=n+i;
		for(int j=1;j<=n;j++){
			s.to=j;
			cin>>s.co;
			if(s.co==0){
				xz=1;
			}
			a.push_back(s);
		}
	}
		sort(a.begin(),a.end(),cmp);
		for(int i=1;i<=n+k;i++){
			f[i]=i;
		}
		cnt=1;
		for(int i=0;i<a.size();i++){
			s=a[i];
			if(hb(s.fr,s.to)){
				cnt++;
				ans+=s.co;
			}
			if(cnt==n+k){
				break;
			}
		}
	
	cout<<ans;
	
	
	
	return 0;
}
