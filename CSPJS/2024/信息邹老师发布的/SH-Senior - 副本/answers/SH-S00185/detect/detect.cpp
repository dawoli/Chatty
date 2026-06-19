#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
const ll N=1e5+9;
ll t,n,m,l,lv,p[N],ans;
struct car{ll d,v,a,cl,cr;}c[N];
double swhcs(ll v0,ll ac){
	return (lv*lv-v0*v0)/2.0/ac;
}
bool cmp(const car&u,const car&v){
	if(u.cl!=v.cl)return u.cl<v.cl;
	return u.cr<v.cr;
}
vector<pii> qj;
vector<ll> chs;
bool chn[N];
void dfs(ll u,ll v){
	if(v>=ans)return;
	if(u==chs.size()){
		int j=0;
		for(ll i=0;i<m;i++){
			if(!chn[i])continue;
//			if(v==2)cout<<i<<" ";
			while(j<m&&qj[j].first<=i&&i<=qj[j].second)j++;
			if(j==m)break;
		}
//		if(v==2)cout<<j<<endl;
		if(j==qj.size())ans=v;return;
	}
	dfs(u+1,v);
	chn[chs[u]]=1;dfs(u+1,v+1);chn[chs[u]]=0;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n>>m>>l>>lv;
		qj.clear();
		bool b1=1,b2=1,b3=1;
		for(ll i=0;i<n;i++){
			cin>>c[i].d>>c[i].v>>c[i].a;
			if(c[i].a>0)b1=b3=0;
			if(c[i].a==0)b2=b3=0;
			if(c[i].a<0)b1=b2=0;
			c[i].cl=c[i].cr=l+1;
			if(c[i].v>lv)c[i].cl=c[i].d;
			if(c[i].a>0&&c[i].v<=lv)
				c[i].cl=min(l+1,c[i].d+(ll)(ceil(swhcs(c[i].v,c[i].a)+1e-3)));
			else if(c[i].a<0&&c[i].v>lv)
				c[i].cr=min(l+1,c[i].d+(ll)(floor(swhcs(c[i].v,c[i].a)-1e-3)));
		}
		sort(c,c+n,cmp);
		for(ll i=0;i<m;i++)cin>>p[i];
		for(ll i=0,j=0;i<n;i++){
			while(j<m&&p[j]<c[i].cl)j++;
			if(j>=m)break;
			if(p[j]<=c[i].cr){
				int k=j;
				if(c[i].a<0)while(k+1<m&&p[k+1]<c[i].cr)k++;
				else k=m-1;
				qj.push_back((pii){j,k});
			}
		}
		cout<<qj.size()<<" ";
		if(!qj.size())cout<<m<<endl;
		else if(b2||b1)cout<<m-1<<endl;
		else{
			chs.clear();ans=m;
			for(ll i=0;i<m;i++){
				chn[i]=0;
				for(ll j=0;j<qj.size();j++)
					if(qj[j].first<=i&&qj[j].second>=i)
						{chs.push_back(i);break;}
			}
//			for(int i=0;i<qj.size();i++)cout<<qj[i].first<<" "<<qj[i].second<<endl;
			if(n<=20&&m<=20)dfs(0,0);
			else ans=chs.size();
			cout<<m-ans<<endl;
		}
	}
	return 0;
} 
