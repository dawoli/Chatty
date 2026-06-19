#include<bits/stdc++.h>
using namespace std;
int t;
int n, m, len, vmax;
int l[100005], r[100005], p[100005], rp[200005];
int cntl[200005], cntr[200005];
int ans1=0, ans2=0;
bool noyushu(double x){
	if(int(x)==x){
		return true;
	}
	return false;
}
void getLR(int x, int d, int v, int a){
	if(v<=vmax&&a<=0){
		l[x]=len+1;
		r[x]=len+1;
		l[x]*=2;
		r[x]*=2;
		return;
	}
	if(v>vmax&&a>=0){
		l[x]=d;
		r[x]=len+1;
		l[x]*=2;
		r[x]*=2;
		return;
	}
	if(v>vmax){
		l[x]=d;
		l[x]*=2;
		double tmp1=(vmax-v);
		tmp1/=a;
		tmp1=tmp1*v+tmp1*tmp1*0.5*a;
		if(tmp1>len-d){
			r[x]=len+1;
			r[x]*=2;
			return;
		}
		r[x]=tmp1+d;
		if(noyushu(tmp1)){
			r[x]*=2;
		}
		else{
			r[x]=r[x]*2+1;
		}
		return;
	}
	r[x]=len+1;
	r[x]*=2;
	double tmp1=(vmax-v);
	tmp1/=a;
	tmp1=tmp1*v+tmp1*tmp1*0.5*a;
	if(tmp1>len-d){
		l[x]=len+1;
		l[x]*=2;
		return;
	}
	l[x]=tmp1+d;
	l[x]=l[x]*2+1;
	return;
}
/*
void cntcar(){
	int cnttmp=0;
	for(int i=1; i<=len; i++){
		cnttmp+=cnt[i];
		cnt[i]=cnttmp;
		cout<<cnt[i]<<" ";
	}
	return;
}
*/
int jkqian[200005], jkhou[200005];
void solve1(){
	for(int i=1; i<=len+3; i++){
		if(jkqian[i]==0){
			jkqian[i]=jkqian[i-1];
		}
	}
	for(int i=len+3; i>=1; i--){
		if(!jkhou[i]){
			jkhou[i]=99999999;
		}
	}
	for(int i=len+3; i>=1; i--){
		if(jkhou[i]==0){
			jkhou[i]=jkhou[i+1];
		}
	}
	for(int i=1; i<=n; i++){
		if(jkhou[l[i]]>=r[i]&&jkqian[r[i]]<l[i]){
			continue;
		}
		ans1++;
	}
}
vector<int> car2jk[200005], jk2car[100005];
bool ok(int kp){
	return false;
}
struct qj{
	int l, r;
};
qj car[100005];
bool cmp(const qj a, const qj b){
	if(a.l==b.l){
		return a.r<b.r;
	}
	return a.l<b.l;
}
void solve2(){
	sort(car+1,car+n+1,cmp);
	multiset<int> tmp;
	int carcnt=1;
	qj carnxt=car[1];
	int ret=0;
	int lm=0, rm=m;
	while(lm<=rm){
		int mid=(lm+rm)>>1;
		if(ok(mid)){
			ret=mid;
			rm=mid-1;
		}
		else{
			lm=mid+1;
		}
	}
}
bool opt=true;
int opthelp=0;
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	int d, v, a;
	
	for(int tt=1; tt<=t; tt++){
		cin>>n>>m>>len>>vmax;
		for(int i=1; i<=n; i++){
			cin>>d>>v>>a;
			if(i==1){
				opthelp=a;
			}
			else if(opthelp!=a){
				opt=false;
			}
			getLR(i, d, v, a);
			cntl[l[i]]++;
			//cntr[r[i]]++;
			car[i].l=l[i], car[i].r=r[i];
			//cout<<l[i]<<" "<<r[i]<<"\n";
		}
		len*=2;
		for(int i=1; i<=m; i++){
			cin>>p[i];
			p[i]*=2;
			//cout<<p[i]<<" ";
			rp[p[i]]=i;
			jkqian[p[i]]=p[i];
			jkhou[p[i]]=p[i];
		}
		//cout<<"\n";
		//cntcar();
		solve1();
		if(opt){
			for(int i=1; i<=len; i++){
				if(cntl[i]){
					break;
				}
				if(rp[i]){
					ans2++;
				}
			}
		}
		//cout<<"\n";
		cout<<ans1<<" "<<ans2<<"\n";
	}
	return 0;
}
