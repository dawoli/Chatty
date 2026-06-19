#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+100; 

struct node{
	int begin,end;
	bool counted=false;
//	int must[MAXN];
};
struct che{
	int pos,mas;
	int belong[MAXN],have=0;
}p[MAXN];
bool cmp(che a,che b){
	return a.pos<b.pos;
}
bool ser1(int num,int n){
	for(int i=1;i<=p[num+1].have;i++){
		if(p[num+1].belong[i]==n)return true;
	}
	return false;
}
void solve(){
	int n,m,L,V;
	cin>>n>>m>>L>>V;
	node car[MAXN];
	int quick[MAXN];
	int carnum=0;
	for(int i=1;i<=n;i++){
		int d,v,a;
		cin>>d>>v>>a;
		
		if((a==0&&v>V)||(a>0&&v>V)){
			car[++carnum].begin=d;
			car[carnum].end=L;
//			for(int j=d;j<=L;j++)quick[j]++;
		}
		else if(a>0&&v<=V){
			double t=double(V-v)/(a*1.0);
			double s=v*t*1.0+0.5*a*t*t;
			if(int(s)<s)s=int(s)+1;
			if(int(s)=s)s--;
			car[++carnum].begin=d+s;
			car[carnum].end=L;
//			for(int j=d+s;j<=L;j++){
//				quick[j]++;
//			}
		}
		else if(a<0&&v>V){
			double t=double(V-v)/(a*1.0);
			double s=v*t*1.0+0.5*a*t*t;
			if(int(s)=s)s--;
			s=min(int(s),L);
			car[++carnum].begin=d;
			car[carnum].end=s+d;
//			for(int j=d;j<=s+d;j++){
//				quick[j]++;
//			}
		}
	}
	
	int maxnum=0;
	for(int j=1;j<=m;j++){
		cin>>p[j].pos;
		for(int i=1;i<=carnum;i++){
//			int mustnum=0;
			if(p[j].pos>=car[i].begin&&p[j].pos<=car[i].end){
//				car[i].must[++mustnum]=p[i];
				p[i].belong[++p[i].have]=i;//该测速仪在i号车范围 
				if(car[i].counted==false){
					car[i].counted=true;
					maxnum++;
				}
			}
		}
	}
	
	for(int i=1;i<=carnum;i++){
		if(car[i].counted==true){
			for(int j=car[i].begin;i<=car[i].end;i++){
				quick[j]++;
			}
		}
	}
	for(int j=1;j<=m;j++){
		p[j].mas=quick[p[j].pos];
	}
	sort(p,p+m+1,cmp);
	int ans=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=p[i].have;j++){
			if(ser1(i,p[i].belong[j])&&p[i+1].mas<p[i].mas){
				ans++;
			}
		}
	}
	cout<<maxnum<<" "<<ans;
}
int main(){
	freopen("detect1.in","r",stdin);
	freopen("detect1.out","w",stdout);
	int T;
	cin>>T;
	for(int i=1;i<=T;i++){
		solve();
	}
}
