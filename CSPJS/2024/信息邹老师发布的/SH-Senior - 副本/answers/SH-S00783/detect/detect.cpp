#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<stack>
#define lowbit(x) (x&(-x))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef __int128 lll;
const ld xl=1e-9;
ld jl;
int n,m,l,v,k,t,ans,d,vi,ai;
class ijk{
	public:
		int i,j,k;
		ijk(int ii=0,int jj=0,int kk=0){
			i=ii;
			j=jj;
			k=kk;
		}
};
ijk b[300005];
bool yc(const ijk& x,const ijk& y){
	if(x.i==y.i)
		return y.j==0;
	return x.i<y.i;
}
void solve(){
	scanf("%d%d%d%d",&n,&m,&l,&v);
	k=0,t=n,ans=0;
	int gl[n];
	for(int i=0;i<n;++i){
		scanf("%d%d%d",&d,&vi,&ai);
		if(vi>v){
			b[k]=ijk(d,1,i);
			++k;
			if(ai>=0)
				continue;
			jl=ld((v-vi)*(v+vi))/ld(ai*2)-xl;
			int x=ceil(jl);
			x+=d;
			if(x>l)
				continue;
			else{
				b[k]=ijk(x,-1,i);
				++k;
			}
		}
		else{
			if(ai<=0){
				--t;
				continue;
			}
			ld jl=ld((v-vi)*(v+vi))/ld(ai*2)+xl;
			int x=ceil(jl);
			x+=d;
			if(x>l){
				--t;
				continue;
			}
			else{
				b[k]=ijk(x,1,i);
				++k;
			}
		}
	}
	for(int i=0;i<m;++i){
		int x;
		cin>>x;
		b[k]=ijk(x,0,i);
		++k;
	}
	for(int i=0;i<=t;++i)
		gl[i]=-1;
	sort(b,b+k,yc);
	stack<int> r;
	int ri=0,jgx=0,xgx=0,op,atc;
	for(int i=0;i<=l;++i){
		while(b[ri].i==i){
			op=b[ri].k;
			if(b[ri].j==0){
				ans+=xgx;
				if(xgx<=0){
					//cout<<ri<<'i'<<endl;
					++ri;
					break;
				}
				if(jgx==0&&!r.empty()){
					r.pop();
					//cout<<ri<<'u'<<endl;
				}
				//cout<<ri<<' '<<xgx<<endl;
				jgx=xgx=0;
				r.push(i);
			}
			if(b[ri].j==-1){
				if(r.empty()){
					--xgx;
				}
				else{
					atc=r.top();
					r.pop();
					if(r.empty()||gl[op]>r.top()){
						if(gl[op]<=atc) ++jgx;
						else{
							--xgx;
						}
					}
					r.push(atc);
				}
				gl[op]=-1;
			}
			if(b[ri].j==1){
				gl[op]=i;
				//cout<<112923<<endl;
				++xgx;
			}
			++ri;
			if(ri==k)
				break;
		}
		if(ri==k)
			break;
	}
	int res=m-r.size();
	cout<<ans<<' '<<res;
}
int main(){
	cin.tie(0);
	cout.tie(0);
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t;
	cin>>t;
	//cout<<1<<endl;
	while(t--){
		solve();
		cout<<endl;
	}
	return 0;
}
