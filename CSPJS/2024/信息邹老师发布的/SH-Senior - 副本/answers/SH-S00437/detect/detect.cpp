#include<bits/stdc++.h>
using namespace std;
int ders[100005];
int mark[400005],lazy[400005];
bool vis[100005];
vector<int> mark2[400005],ans[2];
int n,m,L,V;
struct car{
	int d,v,a;
	bool s1,s2;
	int lc,rc;
}cars[100005];
void add(int n,int L,int R,int l,int r,int d){
	if(l>R || r<L)return;
	if(r>=R && l<=L){
		mark2[n].push_back(d);mark[n]++;return;
	}
	int mid=(L+R)/2;
	add(n*2,L,mid,l,r,d);
	add(n*2+1,mid+1,R,l,r,d);
	return;
}
void add2(int n,int L,int R,int l,int r){
	if(l>R || r<L)return;
	if(r>=R && l<=L){
		lazy[n]--;
		mark[n]-=1;
		return;
	}
	lazy[n*2]+=lazy[n];
	lazy[n*2+1]+=lazy[n];
	mark[n*2]+=lazy[n];
	mark[n*2+1]+=lazy[n];
	lazy[n]=0;
	int mid=(L+R)/2;
	add2(n*2,L,mid,l,r);
	add2(n*2+1,mid+1,R,l,r);
	mark[n]=max(mark[n*2],mark[n*2+1]);
	return;
}
void clear_mark(int n,int L,int R){
	if(L==R)return;
	else{
		int mid=(L+R)/2;
		mark[n*2]+=mark[n];
		mark[n*2+1]+=mark[n];
		mark[n]=0;
		clear_mark(n*2,L,mid);
		clear_mark(n*2+1,mid+1,R);
		mark[n]=max(mark[n*2],mark[n*2+1]);
		return;
	}
}
void askx(int n,int L,int R,int x){
	if(L==R && L==x){
		for(int v:mark2[n])ans[0].push_back(v);
		return;
	}else if(R<x || L>x)return;
	int mid=(L+R)/2;
	for(int v:mark2[n])ans[0].push_back(v);
	askx(n*2,L,mid,x);
	askx(n*2+1,mid+1,R,x);
	return;
}
void build(int n,int L,int R){
	if(L==R)return;
	int mid=(L+R)/2;
	build(n,L,mid);
	build(n,mid+1,R);
	mark[n]=max(mark[n*2],mark[n*2+1]);
}
int ask(int n,int L,int R){
	if(L==R)return L;
	int mid=(L+R)/2;
	lazy[n*2]+=lazy[n];
	lazy[n*2+1]+=lazy[n];
	mark[n*2]+=lazy[n];
	mark[n*2+1]+=lazy[n];
	lazy[n]=0;
	if(mark[n*2]>=mark[n*2+1])return ask(n*2,L,mid);
	else return ask(n*2+1,mid+1,R);
}
int findr(int pos){
	int l=1,r=m+1;
	while(l+1<r){
		int mid=(l+r)/2;
		if(pos<ders[mid])r=mid;
		else l=mid;
	}return r;
}
int findrr(int pos){
	int l=1,r=m+1;
	while(l+1<r){
		int mid=(l+r)/2;
		if(pos<=ders[mid])r=mid;
		else l=mid;
	}return r;
}
int findl(int pos){
	int l=1,r=m+1;
	while(l+1<r){
		int mid=(l+r)/2;
		if(pos<=ders[mid])r=mid;
		else l=mid;
	}return l;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	short T;
	cin>>T;
	while(T--){
		memset(mark2,0,sizeof(mark2));
		memset(mark,0,sizeof(mark));
		memset(lazy,0,sizeof(lazy));
		memset(vis,0,sizeof(vis));
		int ans1=0;
		cin>>n>>m>>L>>V;
		int VV=V*V;
		for(int i=1;i<=n;i++)cin>>cars[i].d>>cars[i].v>>cars[i].a;
		for(int i=1;i<=m;i++)cin>>ders[i];
		ders[m+1]=INT_MAX;
		for(int i=1;i<=n;i++){
			if(cars[i].a==0){
				if(cars[i].v>V){
					int r=findrr(cars[i].d);
					if(r==m+1)continue;
					else{ 
						cars[i].s1=1;
						cars[i].lc=r;
						cars[i].rc=m;
						ans1++;
						add(1,1,m,r,m,i);
					}
				}
			}else{
				double point=(VV-cars[i].v*cars[i].v)/(2*cars[i].a);
				//cout<<i<<' '<<point<<endl;
				if(cars[i].v>V && cars[i].a>0){
					int r=findrr(cars[i].d);
					if(r==m+1)continue;
					else{ 
						cars[i].s1=1;
						ans1++;
						cars[i].lc=r;
						cars[i].rc=m;
						add(1,1,m,r,m,i);
					}
				}else if(cars[i].v>V && cars[i].a<0){
					int l=findrr(cars[i].d);
					int r=findl(cars[i].d+(int)point);
					if(l==m+1 || l>r)continue;
					else if(r==m+1){
						cars[i].s1=1;
						ans1++;
						cars[i].lc=l;
						cars[i].rc=m;
						add(1,1,m,l,m,i);
					}else{
						cars[i].s1=1;
						ans1++;
						cars[i].lc=l;
						cars[i].rc=r;
						add(1,1,m,l,r,i);
					}
				}else if(cars[i].v<=V && cars[i].a>0){
					int r=findr(cars[i].d+(int)point);
					if(r>m)continue;
					else{
						cars[i].s1=1;
						ans1++;
						cars[i].lc=r;
						cars[i].rc=m;
						add(1,1,m,r,m,i);
					}
				}
			}
		}
		cout<<ans1<<' ';
		clear_mark(1,1,n);
		int ans2=m;
		while(ans1){
			ans2--;
			memset(ans,0,sizeof(ans));
			int p=ask(1,1,n);
			//cout<<p<<endl;
			askx(1,1,n,p);
			for(int v:ans[0])if(vis[v]==0){
				ans1--;
				vis[v]=1;
				add2(1,1,n,cars[v].lc,cars[v].rc);
			}
		}cout<<ans2<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
