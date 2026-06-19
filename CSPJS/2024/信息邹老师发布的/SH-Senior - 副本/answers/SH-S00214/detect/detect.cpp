#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ansp,t,n,m,L,V,p[100005],mp[100005];
vector<ll> cscnam,csc[100005];
bool f[100005];
//ll f[100005],fp[100005];
struct car{
	ll d,v,a;
}c[100005];
void shuru(){
	cin>>n>>m>>L>>V;
	for(ll i=0;i<n;i++) cin>>c[i].d>>c[i].v>>c[i].a;
	for(ll i=0;i<m;i++) cin>>p[i];
}
bool sudu(ll x,ll s){
	return (c[x].v*c[x].v+2*c[x].a*s)<=(V*V);
}
void chulicar(){
	sort(p,p+m);
	ll ans=0;
	for(ll i=0;i<n;i++){
		bool ff=0;
		for(ll j=0;j<m;j++){
			if(p[j]>L)
			    break;
			if(c[i].d>p[j]||sudu(i,p[j]-c[i].d))
				continue;
			mp[j]++;
			csc[i].push_back(j);
			ff=1;
		}
		if(ff){
			ans++;
			cscnam.push_back(i);
		}
		
	}
	cout<<ans<<' ';  //ÕýÈ·
	ansp=m;
	for(int i=0;i<=n;i++)
	    f[i]=0;
	for(ll i=0;i<cscnam.size();i++){
		ll x=cscnam[i],maxx=0,maxj;
		bool ff=0;
		for(ll j=0;j<csc[x].size();j++){
			if(f[csc[x][j]]){
				ff=1;
				break;
			}
			if(maxx<mp[csc[x][j]]){
				maxx=mp[csc[x][j]];
				maxj=csc[x][j];
			}
		}
		if(ff==0){
			ansp--;
			//cout<<maxj<<' ';
		    f[maxj]=1;
		}
		
		
	}
	cout<<ansp;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	for(ll i=0;i<t;i++){
		shuru();
		if(i!=0)
		    cout<<endl;
		chulicar();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;  
}
