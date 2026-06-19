#include<bits/stdc++.h>
using namespace std;
#define N 200010
map<string,int> a;
int be=0,ans=0;
vector<int> d[N];
string c[N],b[N];
int l[N],r[N],si[N];
char z[N],zd[N*25];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	//ios::sync_with_stdio(0);
	int n,q; cin>>n>>q;
	for(int k=1;k<=n;k++){
		cin>>b[k]>>c[k];
		si[k]=b[k].size();
		if(b[k]==c[k]) continue;
		for(int i=0;i<si[k];i++){
			if(b[k][i]!=c[k][i]){
				l[k]=i;
				break;
			}
		}for(int i=si[k]-1;i>=0;i--){
			if(b[k][i]!=c[k][i]){
				r[k]=i;
				 break;
			}
		}  int num=0;
		if(r[k]-l[k]<=1e5){
			memset(z,0,sizeof(z));
			for(int i=l[k];i<=r[k];i++){
				z[num++]=b[k][i];
				z[num++]=c[k][i];
			} 
			if(a[z]==0) a[z]=++be;
			d[a[z]].push_back(k);
		}else{
			memset(zd,0,sizeof(zd));
			for(int i=l[k];i<=r[k];i++){
				zd[num++]=b[k][i];
				zd[num++]=c[k][i];
			} 
			if(a[zd]==0) a[zd]=++be;
			d[a[zd]].push_back(k);
		}
	}
	for(int k=1;k<=q;k++){
		ans=0;
		string x,y; cin>>x>>y;
		int lq=0,rq=0;
		for(int i=0;i<x.size();i++){
			if(x[i]!=y[i]){
				lq=i;
				break;
			}
		}for(int i=x.size()-1;i>=0;i--){
			if(x[i]!=y[i]){
				rq=i;
				break;
			} 
		}  int num=0;
		if(rq-lq<=1e5){
			memset(z,0,sizeof(z));
		for(int i=lq;i<=rq;i++){
			z[num++]=x[i];
			z[num++]=y[i];
		} 
		if(a[z]==0){
			cout<<0<<endl;
			continue;
		} 
		for(int i=0;i<d[a[z]].size();i++){
			int nea=d[a[z]][i];
			if(l[nea]>lq||(si[nea]-r[nea]>x.size()-rq)) continue;
			for(int j=1;j<=l[nea];j++){
				if(b[nea][l[nea]-j]!=x[lq-j]) continue;
			} for(int j=1;j+r[nea]<si[nea];j++){
				if(b[nea][r[nea]+j]!=x[rq+j]) continue;
			} ans++;
		}
		}else{
			memset(zd,0,sizeof(zd));
		for(int i=lq;i<=rq;i++){
			zd[num++]=x[i];
			zd[num++]=y[i];
		} 
		if(a[zd]==0){
			cout<<0<<endl;
			continue;
		} 
		for(int i=0;i<d[a[zd]].size();i++){
			int nea=d[a[zd]][i];
			if(l[nea]>lq||si[nea]-r[nea]>x.size()-rq) continue;
			bool t=1;
			for(int j=1;j<=l[nea];j++){
				if(b[nea][l[nea]-j]!=x[lq-j]){
					t=0;
					break;
				}
			} for(int j=1;j+r[nea]<si[nea];j++){
				if(b[nea][r[nea]+j]!=x[rq+j]){
					t=0;
					break;
				}
			} if(t) ans++;
		}
		} cout<<ans<<endl;
	}
}

