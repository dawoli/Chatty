#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=1e5+5;
struct car{
	int d,v,a,l,r;
}s[MAXN];
struct node{
	int pos,id;
	bool st;
};
node j;
bool operator<(node a,node b){
	if(a.pos==b.pos&&a.st&&!b.st) return false;
	if(a.pos==b.pos&&b.st&&!a.st) return true;
	if(a.pos==b.pos) return a.id<=b.id;
	return a.pos>b.pos;
}
priority_queue<node> q;
queue<int> num;
int n,m,l,vmax,p[MAXN],ans,t;
bool ab=true,flag[MAXN];
signed main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	for(int qwq=1;qwq<=t;qwq++){
		cin>>n>>m>>l>>vmax;
		for(int i=1;i<=n;i++){
			int d,v,a;
			cin>>d>>v>>a;
			s[i]={d,v,a,0,0};
			if(a<0) ab=false;
		}
		for(int i=1;i<=m;i++) cin>>p[i];
		for(int i=1;i<=n;i++){
			int a=s[i].a,d=s[i].d,v=s[i].v;
			if(a>=0){
				if(d>p[m]) continue;
				if(a>0){
				//	cout<<d+(vmax*vmax-v*v)/2/a<<endl;
					s[i].l=upper_bound(p+1,p+m+1,d+(vmax*vmax-v*v)/2/a)-p;
					int sipos=upper_bound(p+1,p+m+1,d)-p;
					if(s[i].l<sipos) s[i].l=sipos;
				//	while((p[s[i].l]-d)*2*a<=vmax*vmax-v*v) s[i].l++;
				}
				else{
					if(v<=vmax) continue;
					s[i].l=upper_bound(p+1,p+m+1,d)-p;
				}
			//	cout<<i<<" "<<s[i].l<<" "<<s[i].r<<endl;
				if(s[i].l>m){
					if(v*v+2*a*(p[m]-d)>vmax*vmax) s[i].l=m;
					else continue;
				}
				s[i].r=m;
				ans++;
				flag[i]=true;
				j={s[i].l,i,true};
				q.push(j);
				j={s[i].r,i,false};
				q.push(j);
				
			}
			else{
				if(d>p[m]) continue;
				if(v<=vmax) continue;
			//	cout<<d<<" "<<d+(vmax*vmax-v*v)/2/a<<endl;
				s[i].r=lower_bound(p+1,p+m+1,d+(vmax*vmax-v*v)/2/a)-p;
				s[i].r--;
			//	while((p[s[i].r]-d)*2*a>=vmax*vmax-v*v) s[i].r++;
				s[i].l=upper_bound(p+1,p+m+1,d)-p;
				if(p[s[i].l]-1>=d) s[i].l--;
				if(-v*v<=2*a*(s[i].l-d)){
					continue;
				}	
				if(v*v+2*a*(s[i].l-d)<=vmax*vmax) continue;
				if(s[i].r<s[i].l){
					continue;
				}
				//	cout<<i<<" "<<s[i].l<<" "<<s[i].r<<endl;
				ans++;
				flag[i]=true;
				j={s[i].l,i,true};
				q.push(j);
				j={s[i].r,i,false};
				q.push(j);
			}
		}
		cout<<ans<<" ";
		ans=0;
		while(!q.empty()){
			int pos=q.top().pos,id=q.top().id,tf=q.top().st;
		//	cout<<pos<<" "<<id<<" "<<signed(tf)<<endl;
			
			q.pop();
			if(tf) num.push(id);
			if(!tf&&flag[id]){
				ans++;
				while(!num.empty()){
					flag[num.front()]=false;
					num.pop();
				}
			}
		}
		cout<<m-ans<<endl;
		for(int i=1;i<=MAXN;i++) flag[i]=false;
		ab=true;ans=0;
	}
	
	return 0;
	
}
