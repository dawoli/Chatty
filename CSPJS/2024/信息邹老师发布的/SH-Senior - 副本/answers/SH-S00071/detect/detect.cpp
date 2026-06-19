//滑动窗口+贪心 
#include <bits/stdc++.h>
using namespace std;
struct node{
	int l,r;
};
int t,n,m,l,V;
int d[100009],v[100009],a[100009];
int p[100009];
node q[100009];

void calculate(){
	for(int i=1;i<=n;i++){
		if(a[i]==0){
			if(v[i]>V) {q[i].l=d[i];q[i].r=l;}
			else {q[i].l=-1;q[i].r=-1;}
		} else if(a[i]>0){
			if(v[i]>V) {q[i].l=d[i];q[i].r=l;}
			else if(v[i]==V){q[i].l=d[i]+1;q[i].r=l;}
			else {
				double tm=(double)(V-v[i])/(double)a[i];
				double dis=(double)d[i]+(double)v[i]*tm+0.5*(double)a[i]*tm*tm;
				q[i].l=dis+1;
				if(q[i].l>l){q[i].r=q[i].l;}
				else {q[i].r=l;}
			}
		} else {
			if(v[i]<=V) {q[i].l=-1;q[i].r=-1;}
			else {
				double tm=(double)(V-v[i])/(double)a[i];
				double dis=(double)d[i]+(double)v[i]*tm+0.5*(double)a[i]*tm*tm;
				q[i].r=dis;
				if((int)dis==dis)q[i].r--;
				if(q[i].r>l){q[i].l=d[i];q[i].r=l;}
				else {q[i].l=d[i];}
			}
		}
	}
}
bool cmp(node x,node y){
	return x.l<y.l;
}
node qu[100009];
bool flag[100009];
int nev[100009];
int beg[100009];
int main() {
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout); 
	cin>>t;
	while(t--){
	memset(flag,0,sizeof(flag));
	memset(nev,0,sizeof(nev));
	memset(beg,0,sizeof(beg));
	memset(qu,0,sizeof(qu));
	scanf("%d%d%d%d",&n,&m,&l,&V);
	for(int i=1;i<=n;i++) scanf("%d%d%d",&d[i],&v[i],&a[i]);
	for(int i=1;i<=m;i++) scanf("%d",&p[i]);
	sort(p,p+m+1);
	calculate();
	//	滑动窗口
	sort(q,q+n+1,cmp);
	int cnt=0;
	int head=1;
	int nail=1;
	int tot=1;
	for(int i=1;i<=m;i++){
		int k=0;
		while(q[tot].l<=p[i]&&tot<=n){
			qu[head]=q[tot];
			if(q[tot].r>=p[i]&&!flag[tot]){
				flag[tot]=1;
				cnt++;
				beg[tot]=i;
			}
			head++;tot++;
		}
		bool pl=0;
		while(qu[nail].r<p[i]&&nail<=head){
			if(qu[nail].r>=p[i-1])nev[nail]=i-1;
			nail++;
		}
	}
	for(int i=1;i<=n;i++){
		if(q[i].r==l)nev[i]=m;
	}
	cout<<cnt<<" ";
	
	int cnt2=0;
	int last=-1;
	for(int i=1;i<=n;i++){
		if(beg[i]==0&&nev[i]==0)continue;
//		if(beg[i]<=last&&nev[i]<last)last=nev[i];
		if(beg[i]>last){
			last=nev[i];
			cnt2++;
		}
	}
	cout<<m-cnt2<<endl;
	}
	return 0;
} 
//1
//5 5 15 3
//0 3 0
//12 4 0
//1 1 4
//5 5 -2
//6 4 -4
//2 5 8 9 15
