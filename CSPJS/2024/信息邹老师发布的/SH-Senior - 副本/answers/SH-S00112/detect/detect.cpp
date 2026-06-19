#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;
typedef long double ld;
const int N=100005;
const ld eps=1e-10;
int T,n,m,L,V;
ld p[N];
struct car{
	ld d;int v,a;
}c[N];
vector<pair<int,int> > rgs;
int h[N];
bool mk[N];
struct node{
	int l,r,mx,tag,mxp;
};
struct tre{
	node t[N<<2];
	void clear(){
		for(int i=0;i<=(m<<2)+1;i++)
			t[i]=(node){0,0,0,0};
	}
	void pushup(int x){
		if(t[x<<1].mx>t[x<<1|1].mx)
			t[x].mx=t[x<<1].mx,t[x].mxp=t[x<<1].mxp;
		else t[x].mx=t[x<<1|1].mx,t[x].mxp=t[x<<1|1].mxp;
	}
	void build(int x,int l,int r){
		t[x]=(node){l,r,0,0,0};
		if(l==r){
			t[x].mx=h[l];
			t[x].mxp=l;
			return;
		}
		int mid=(l+r)>>1;
		build(x<<1,l,mid);
		build(x<<1|1,mid+1,r);
		pushup(x);
	}
	void pushdown(int x){
		if(t[x].tag){
			t[x<<1].mx+=t[x].tag;
			t[x<<1|1].mx+=t[x].tag;
			t[x<<1].tag+=t[x].tag;
			t[x<<1|1].tag+=t[x].tag;
			t[x].tag=0;
		}
	}
	void add(int x,int l,int r,int k){
		if(l>t[x].r||r<t[x].l)return;
		if(l<=t[x].l&&t[x].r<=r){
			t[x].mx+=k;
			t[x].tag+=k;
			return;
		}
		pushdown(x);
		add(x<<1,l,r,k);
		add(x<<1|1,l,r,k);
		pushup(x);
	}
	node query(int x,int l,int r){
		if(l>t[x].r||r<t[x].l)return (node){-1,-1,-1,-1,-1};
		if(l<=t[x].l&&t[x].r<=r)return t[x];
		node ls=query(x<<1,l,r);
		node rs=query(x<<1|1,l,r);
		if(ls.l==-1)return rs;
		if(rs.l==-1)return ls;
		node res;
		if(ls.mx>rs.mx){
			res=ls;
			res.r=rs.r;
		}else{
			res=rs;
			res.l=ls.l;
		}
		return res;
	}
}tr;
//void print(){
//	for(int i=1;i<=(m<<2);i++)
//}
int solve(){
	tr.clear();
//	for(int i=0;i<rgs.size();i++){
//		cout<<rgs[i].fi<<","<<rgs[i].se<<'\n';
//	}
	sort(rgs.begin(),rgs.end());
	queue<pair<int,int> > q[2];
	int now=0;
	while(!q[0].empty())q[0].pop();
	while(!q[1].empty())q[1].pop();
	for(int i=0;i<rgs.size();i++){
		q[now].push(rgs[i]);
	}
	tr.build(1,1,m);
	for(int i=0;i<rgs.size();i++){
		tr.add(1,rgs[i].fi,rgs[i].se,1);
	}
//	for(int i=1;i<=m;i++)cout<<tr.query(1,i,i).mx<<' ';puts("");
	int res=0;
	while(1){
		node cur=tr.query(1,1,m);
//		cout<<cur.mxp<<'\n';
		if(cur.mx<1)break;
		int pos=cur.mxp;
		while(!q[now].empty()){
			pair<int,int> yy=q[now].front();q[now].pop();
			if(yy.se<pos||yy.fi>pos){
				q[now^1].push(yy);
			}else{
				tr.add(1,yy.fi,yy.se,-1);
			}
		}
//		for(int i=1;i<=m;i++)cout<<tr.query(1,i,i).mx<<' ';puts("");
		++res;
		now^=1;
	}
	return res;
}
void man(){
	rgs.clear();
	for(int i=1;i<=n;++i)mk[i]=0;
	cin>>n>>m>>L>>V;
	for(int i=1;i<=n;++i)
		cin>>c[i].d>>c[i].v>>c[i].a;
	for(int i=1;i<=m;++i)
		cin>>p[i];
	sort(p+1,p+m+1);
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(c[i].a==0){
			if(c[i].v<=V)continue;
			else{
				int posi=lower_bound(p+1,p+m+1,c[i].d)-p-1;
				if(posi<m){
					cnt++;
					rgs.emplace_back(mp(posi+1,m));
					mk[posi+1]=1;
//					printf("car %intd VLE, t1, chkpoint %intd usable.\n",i,posi+1);
				}
			}
		}else if(c[i].a>0){
			ld pos=(1.*V*V-1.*c[i].v*c[i].v)/(2.*c[i].a)+c[i].d;
			if(pos>=L)continue;
			int posi=upper_bound(p+1,p+m+1,pos)-p-1;
			if(posi>=m)continue;
			else {
				cnt++;
				rgs.emplace_back(mp(posi+1,m));
				mk[posi+1]=1;
			}
		}else if(c[i].a<0){
			if(c[i].v<=V)continue;
			ld pos=(1.*V*V-1.*c[i].v*c[i].v)/(2.*c[i].a)+c[i].d;
			if(pos>=L)continue;
			int posl=upper_bound(p+1,p+m+1,c[i].d)-p-1;
			int posr=upper_bound(p+1,p+m+1,pos)-p-1;
			if(posl==posr)continue;
			else{
				cnt++;
				if(abs(p[posl]-c[i].d)<=eps){
					mk[posl]=1;
					if(p[posr]==pos)--posr;
					rgs.emplace_back(posl,posr);
//					printf("car %intd VLE, t3, chkpoint %intd usable.\n",i,posl);
				}
				else {
					mk[posl+1]=1;
					if(p[posr]==pos)--posr;
					rgs.emplace_back(posl+1,posr);
//					printf("car %intd VLE, t4, chkpoint %intd usable.\n",i,posl+1);
				}
			}
		}
	}
	cout<<cnt<<' ';
	int ans=solve();
//	ans=0;
//	for(int i=1;i<=m;i++)
//		ans+=(mk[i]==0);
	cout<<m-ans<<'\n';
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>T;
	while(T--)man();
	return 0;
}

