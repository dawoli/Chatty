#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
struct node{
	int d,v,a,l,r;
	bool flag;
}a[MAXN];
int T,n,m,L,V,p[MAXN],ans1,ans2;
bool cmp(node x,node y){
	return (x.flag&&!y.flag)||(x.flag&&y.flag&&(x.l<y.l||x.l==y.l&&x.r<y.r));
}
priority_queue <int,vector<int>,greater<int> > q;
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	while(T-->0){
		cin>>n>>m>>L>>V;
		ans1=0;	ans2=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].d>>a[i].v>>a[i].a;
			if(a[i].a==0){
				if(a[i].v>V){
					a[i].l=a[i].d;	a[i].r=L;
					a[i].flag=true;
				}
				else	a[i].flag=false;
			}
			else if(a[i].a>0){
				if(a[i].v>V){
					a[i].l=a[i].d;	a[i].r=L;
					a[i].flag=true;
				}
				else{
					int tmp=V*V-a[i].v*a[i].v,ll;
					ll=a[i].d+tmp/2/a[i].a+1;
					if(ll<=L){
						a[i].l=ll;	a[i].r=L;
						a[i].flag=true;
					}
					else	a[i].flag=false;
				}
			}
			else{
				if(a[i].v<=V)	a[i].flag=false;
				else{
					a[i].flag=true;
					a[i].l=a[i].d;
					int tmp=a[i].v*a[i].v-V*V,rr;
					rr=a[i].d+tmp/2/(-a[i].a);
					if(tmp%2==0&&tmp/2%(-a[i].a)==0)	rr--;
					a[i].r=min(L,rr);	
				}
			}
		}
		for(int i=1;i<=m;i++)	cin>>p[i];
		sort(a+1,a+n+1,cmp);
		while(n>0&&!a[n].flag)	n--;
		int pos=1;
		while(pos<=n&&a[pos].l<=p[1]){
			if(a[pos].r>=p[1]){
				q.push(a[pos].r);	ans1++;
			}
			pos++;
		}
		for(int i=2;i<=m;i++){
			if(!q.empty()&&q.top()<p[i]){
				while(!q.empty())	q.pop();
			}
			else	ans2++;
			while(pos<=n&&a[pos].l<=p[i]){
				if(a[pos].r>=p[i]){
					q.push(a[pos].r);	ans1++;
				}
				pos++;
			}
		}
		if(q.empty())	ans2++;
		else{
			while(!q.empty())	q.pop();
		}
		cout<<ans1<<" "<<ans2<<endl;
	}
	return 0;
}
