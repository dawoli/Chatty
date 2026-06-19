#include<bits/stdc++.h>
#define int long long
#include<fstream>
using namespace std;

ifstream fin("detect.in");
ofstream fout("detect.out");
#define cin fin
#define cout fout

int T,n,m,L,V,cnt,d,v,a;
struct car{
	int l,r,mxt;
	bool flag;
	bool operator<(const car ttt)const{
		return r<ttt.r||r==ttt.r&&l<ttt.l;
	}
}c[100005];
int p[100005],cc[1000005];
car vec[100005];
bool add(int id,int x){
	for(int i=id;i<=L;i+=(i&(-i))){
		cc[i]+=x;
	}
}
int query(int id){
	if(id==-1){
		return 0;
	}
	int res=0;
	for(int i=id;i;i-=(i&(-i))){
		res+=cc[i];
	}
	return res;
}
bool check(int x,int y){
	if(x<=cnt){
		if(vec[x].l<=y&&y<=vec[x].r){
			return true;
		}
	}
	return false;
}
signed main(){
	cin>>T;
while(T--){
	cin>>n>>m>>L>>V;
	for(int i=1;i<=n;i++){
		c[i]={0,0,0,0};
		cin>>d>>v>>a;
		if(a==0){
			if(v>V){
				c[i].l=d;
				c[i].r=L;
				c[i].flag=1;
			}
			else{
				c[i].flag=0;
			}
		}
		if(a<0){
			if(v<=V){
				c[i].flag=0;
			}
			else{
				double s1=d+(V*V-v*v)/(2.0*a);
				c[i].l=d;
				c[i].r=floor(min(L*1.0,s1-(1e-8)));
				c[i].flag=1;
			}
		}
		if(a>0){
			if(v>V){
				c[i].l=d;
				c[i].r=L;
				c[i].flag=1;
			}
			else{
				double s1=(V*V-v*v)/(2.0*a);
				if(d+s1>=L){
					c[i].flag=0;
				}
				else{
					c[i].l=ceil(d+s1);
					c[i].r=L;
					c[i].flag=1;
				}
			}
		}
	}
	for(int i=0;i<=L;i++){
		cc[i]=0;
	}
	for(int i=1;i<=m;i++){
		cin>>p[i];
		add(p[i],1);
	}
	cnt=0;
	for(int i=1;i<=n;i++){
		if(c[i].flag==1){
			int temp=query(c[i].r);
			if(temp-query(c[i].l-1)==0){
				c[i].flag=0;
			}
			else{
				int ll=c[i].l,rr=c[i].r+1;
				while(ll<rr-1){
					int mid=(ll+rr)/2;
					if(temp-query(mid-1)==0){
						rr=mid;
					}
					else{
						ll=mid;
					}
				}
				c[i].mxt=ll;
				vec[++cnt]=c[i];
			}
		}
	}
	cout<<cnt<<' ';
	sort(vec+1,vec+cnt+1);
	int iter=1;
	int ans=0;
	while(iter<=cnt){
		int temp=vec[iter].mxt;
		ans++;
		while(check(iter,temp)){
			iter++;
		}
	}
	cout<<m-ans<<'\n';
}
	return 0;
}
