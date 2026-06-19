#include<bits/stdc++.h>
#define ll long long;
using namespace std;
const int N=1e4+20,M=1e6+9;
int n,m,k,ans;
int c[20];
struct Map{
	int st,e,cost;
	bool operator < (const Map &a) const{
		if(cost==a.cost) return st<a.st;
		return cost<a.cost;
	}
}ma[M];
struct sp{
	int to;
}p[N];
void solve1(){
	sort(ma+1,ma+1+m+k*n);
	for(int i=1;i<=m+k*n;i++){
//		cout<<ma[i].st<<" "<<ma[i].e<<" "<<ma[i].cost<<endl;
//		for(int j=1;j<=n+k;j++){
//			cout<<p[j].to<<" ";
//		}
//		cout<<endl<<endl;
		if(p[ma[i].e].to == p[ma[i].st].to) continue;
		for(int j=1;j<=n+k;j++){
			if(p[j].to!=ma[i].st && p[j].to==p[ma[i].e].to){
				p[j].to=p[ma[i].st].to;
			}
		}
		p[ma[i].st].to = p[ma[i].e].to;
		ans+=ma[i].cost;
	}
	cout<<ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++){
		p[i].to=i;
	}
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&ma[i].st,&ma[i].e,&ma[i].cost);
		if(ma[i].st>ma[i].e) swap(ma[i].st,ma[i].e);
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			scanf("%d",&ma[m+j*i].cost);
			ma[m+j*i].st=j;
			ma[m+j*i].e=n+i;
			if(ma[m+j*i].cost==0) p[n+i].to=j;
		} 
	}
	solve1();
	return 0;
}
