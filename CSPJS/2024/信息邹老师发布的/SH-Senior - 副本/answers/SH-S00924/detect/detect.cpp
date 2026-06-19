#include<bits/stdc++.h> 
#define N 100009
using namespace std;
struct ylcc{
	int st,ed;
}cyl[N];
bool cmp(const ylcc &a,const ylcc &b){
	if(a.st==b.st)return a.ed<b.ed;
	return a.st<b.st;
}
int T,n,m,l,vlmt,tmp,lft,rgt,totn;
int p[N];
inline int slve(int nsts){
	lft=cyl[nsts].st;
	rgt=cyl[nsts].ed;
	while(nsts<=totn&&cyl[nsts].st<=rgt){
		while(lft==cyl[nsts].st&&nsts<=totn)nsts++;
		lft=cyl[nsts].st;
		rgt=min(rgt,cyl[nsts].ed);
	}
	return nsts;
}
inline void solve(){
	scanf("%d%d%d%d",&n,&m,&l,&vlmt);
	vlmt*=vlmt;
	totn=0;
	for(int i=0,d,v,a;i<n;i++){
		scanf("%d%d%d",&d,&v,&a);
		a*=2;
		v*=v;
		if(v>vlmt){
			totn++;
			cyl[totn].st=d;
			if(a>=0){
				cyl[totn].ed=l;
			}else{
				v-=vlmt;
				a=-a;
				cyl[totn].ed=v/a-(v%a==0);
				cyl[totn].ed+=d;
			}
		}else if(a>0){
			v=vlmt-v;
			if(d+v/a<l){
				totn++;
				cyl[totn].st=v/a+1+d;
				cyl[totn].ed=l;
			}
		}
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&p[i]);
	}
	for(int i=1;i<=totn;i++){
		cyl[i].st=lower_bound(p+1,p+1+m,cyl[i].st)-p;
		cyl[i].ed=upper_bound(p+1,p+1+m,cyl[i].ed)-p-1;
		if(cyl[i].st>cyl[i].ed){
			cyl[i].st=-1;
		}
	}
	sort(cyl+1,cyl+1+totn,cmp);
	tmp=1;
	while(cyl[tmp].st==-1&&tmp<=totn)tmp++;
	printf("%d ",totn-tmp+1);
	while(tmp!=totn+1){
		tmp=slve(tmp);
		m--;
	}
	printf("%d\n",m);
	return;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	while(T--)solve();
	return 0;
}
