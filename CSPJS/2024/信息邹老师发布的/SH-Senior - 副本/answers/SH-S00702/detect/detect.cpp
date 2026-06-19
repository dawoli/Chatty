#include<bits/stdc++.h>
using namespace std;
const int Maxn=1e6+10;
struct node{double x,y;}f[Maxn];
double d,v,a,l,s,mi=0.0000001;
int t,n,m,i,p[Maxn],in[Maxn];
bool cmp(node xx,node yy){
	return xx.x<yy.x;
}
int main(){
	freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
	cin>>t;
	while(t--){
		memset(in,0,sizeof(in));
		memset(p,0,sizeof(p));
		bool aa=true;
		cin>>n>>m>>l>>s;
		for(i=1;i<=n;i++){
			cin>>d>>v>>a;
			if(a<0) aa=false;
			f[i].x=f[i].y=-1;
			if(a==0){
				if(v>s){
					f[i].x=d;
					f[i].y=l;
				}
			}
			else if(a>0){
				if(v>s){
					f[i].x=d;
					f[i].y=l;
				}
				else{
					if(d+(s*s-v*v)/((double)2*a)<=l){
						f[i].x=d+(s*s-v*v)/((double)2*a)+mi;
						f[i].y=l;
					}
				}
			}
			else{
				if(v>s){
					f[i].x=d;
					if(d+(s*s-v*v)/((double)2*a)<=l)
					f[i].y=d+(s*s-v*v)/((double)2*a)-mi;
					else f[i].y=l;
				}
			}
		}
		if(aa){
			int sum=0,ans=0;
			for(i=1;i<=m;i++) cin>>a;
			for(i=1;i<=n;i++)
			if(a>=f[i].x&&a<=f[i].y) sum++;
			if(sum==0) ans=m;
			else ans=m-1;
			cout<<sum<<" "<<ans<<endl;
		}
		else{
			int sum=0,ans=0,j=1,k=1,last=0,cnt=0; in[0]=1;
			priority_queue<pair<double,int> >q,qq;
			sort(f+1,f+n+1,cmp);
			for(i=1;i<=m;i++) cin>>a,p[(int)a]=1;
			while(j<=n&&(int)f[j].x==-1) j++;
			for(i=0;i<=(int)l;i++){
				while(j<=n&&f[j].x<=(double)i){
			    	q.push({-f[j].y,j}); in[j]=k; 
					cnt++; j++;
				}
				while(!q.empty()&&-q.top().first<(double)i){
					if(in[q.top().second]==k) cnt--;
					in[q.top().second]=0; 
					q.pop(); 
				}
				if(!p[i]) continue;
				if(cnt==0) ans++;
				else if(in[last]&&last!=0) ans++; 
				else while(!q.empty()&&in[q.top().second]!=k) q.pop();
				if(!q.empty()&&cnt!=0) last=q.top().second;
		    	sum+=cnt; cnt=0; k++;
			}
			cout<<sum<<" "<<ans<<endl;
	    }
	}
	return 0;
}
