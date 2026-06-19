#include<bits/stdc++.h>
using namespace std;
int n,m,l,r,lq,rq,ans=0;
string a,b,aq,bq,neda,nedb,nedx,nedy;
struct rp{
	string x="",y1="",y2="",z=""; 
}p[200010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		l=0;
		r=a.length()-1;
		while(a[l]==b[l]){
			p[i].x+=a[l];
			l++;
		}
		while(a[r]==b[r]){
			r--;
		}
		for(int j=r+1;j<a.length();j++){
			p[i].z+=a[j];
		}
		for(int j=l;j<=r;j++){
			p[i].y1+=a[j];
			p[i].y2+=b[j];
		}
	}
	while(m--){
		ans=0;
		neda="",nedb="",nedx="",nedy="";
		cin>>aq>>bq;
		lq=0;
		rq=aq.length()-1;
		while(aq[lq]==bq[lq]){
			nedx+=aq[lq];
			lq++;
		}
		while(aq[rq]==bq[rq])rq--;
		for(int i=rq+1;i<aq.length();i++)nedy+=aq[i];
		for(int i=lq;i<=rq;i++){
			neda+=aq[i];
			nedb+=bq[i];
		}
		
		for(int i=1;i<=n;i++){
			if(neda==p[i].y1&&nedb==p[i].y2&&nedx.find(p[i].x)!=-1&&nedy.find(p[i].z)!=-1)ans++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}

