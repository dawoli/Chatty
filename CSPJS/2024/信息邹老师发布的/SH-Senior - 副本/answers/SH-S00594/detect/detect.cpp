#include<bits/stdc++.h>
using namespace std;
int T,n,m,l,v,cnt,p[100005];
struct car{int s,e;}c[100005];
struct node{
	int t,tp,id;
}a[200005];
bool cmp(node x,node y){return x.t==y.t?x.tp<y.tp:x.t<y.t;}
set <int> st;
int main(){
	cin.tie(0);
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	while(T--){
		bool flag=true;
		cnt=0;
		st.clear();
		cin>>n>>m>>l>>v;
		int ans1=0,ans2=n;
		v*=v;
		for(int i=1;i<=n;i++){
			int s,v0,a;
			cin>>s>>v0>>a;
			if(a<0) flag=false;
			v0*=v0;
			if(v0>v&&a>=0) c[i]=(car){s,l};
			else if(v0<=v&&a<=0) c[i]=(car){0,0};
			else if(v0<=v) c[i]=(s+(v-v0)/(a<<1)+1<l?(car){((v-v0)/(a<<1))+1+s,l}:(car){0,0});
			else c[i]=(car){s,min(l,s+(v0-v)/(-a*2))};
		}
		for(int i=1;i<=m;i++) cin>>p[i];
		for(int i=1;i<=n;i++){
			if(!c[i].s) continue;
			int x=lower_bound(p+1,p+m+1,c[i].s)-p;
			if(x<=n&&p[x]<=c[i].e){
				ans1++;
				a[++cnt]={c[i].s,1,i};
				a[++cnt]={c[i].e,2,i};
			}
		}
		if(flag) ans2=n-1;
		else{
			sort(a+1,a+cnt+1,cmp);
			int lastp=0;
			for(int i=1;i<=cnt;i++){
				if(a[i].tp==1) st.insert(a[i].id);
				else
					if(st.find(a[i].id)!=st.end()){
						ans2--;
						st.clear();
					}
			}
		}
		cout<<ans1<<' '<<ans2<<endl;
	}
}
