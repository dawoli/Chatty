#include<bits/stdc++.h>
using namespace std;
struct ES{
	long long u;
	long long v;
	long long t;
};
ES es[1000009];
long long p[10009];
long long x[12];
long long x_vl[12][10009];
long long find(long long s){
	if(p[s]==s){
		return s;
	}
	if(p[s]==0){
		p[s]=s;
		return s;
	}
	long long o = find(p[s]);
	p[s]=o;
	return o;
}
void uni(long long s1,long long s2){
	p[s1]=find(s1);
	p[s2]=find(s2);
	p[find(s1)]=s2;
	p[s1]=find(s1);
	p[s2]=find(s2);
}
bool cmp(const ES &s1,const ES &s2){
	return s1.v<s2.v;
}
bool ok(long long s_n){
	p[1]=find(1);
	long long o = p[1];
	for(long long f = 2;f<=s_n;f++){
		p[f]=find(f);
		if(p[f]!=o){
			return 0;
		}
	}
	return 1;
}
long long solve(long long n,long long m){
	long long a = 0;
	sort(es+1,es+1+m,cmp);
	for(long long f = 1;f<=n;f++){
		p[f]=f;
	}
//	for(long long f = 1;f<=m;f++){
//		cout<<es[f].t<<" "<<es[f].u<<" "<<es[f].v<<endl;
//	}
	for(long long f = 1;f<=m;f++){
//		for(long long f2 = 1;f2<=n;f2++){
//			p[f2]=find(f2);
//			cout<<f2<<":"<<p[f2]<<endl;
//		}
//		cout<<endl;
		if(ok(n)){
			break;
		}
		p[es[f].u]=find(es[f].u);
		p[es[f].t]=find(es[f].t);
		if(p[es[f].u]==p[es[f].t]){
			continue;
		}else{
//			cout<<p[es[f].u]<<" "<<p[es[f].t]<<endl;
			a+=es[f].v;
			uni(es[f].u,es[f].t);
//			cout<<es[f].t<<" "<<es[f].u<<" "<<es[f].v<<endl;
		}
	}
	return a;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long n = 0;
	long long m = 0;
	long long l = 0;
	long long a = 0;
	cin>>n>>m>>l;
	for(long long f = 1;f<=m;f++){
		long long o1 = 0;
		long long o2 = 0;
		long long o3 = 0;
		cin>>o1>>o2>>o3;
		es[f].t=o1;
		es[f].u=o2;
		es[f].v=o3;
//		if(o3==0){
//			cout<<"YES";
//		}
	}
	for(long long f1 = 1;f1<=l;f1++){
		cin>>x[f1];
		for(long long f2 = 1;f2<=n;f2++){
			cin>>x_vl[f1][f2];
		}
	}
	if(l==0){
		a=solve(n,m);
		cout<<a;
		return 0;
	}
	for(long long f1 = 1;f1<=l;f1++){
		long long o = 0;
		for(long long f2 = 1;f2<=n;f2++){
			if(x_vl[f1][f2]==0){
				o=f2;
//				o=x_vl[f2][f1];
				break;
			}
		}
		for(long long f2 = 1;f2<=n;f2++){
			if(f2==o){
				continue;
			}
			m++;
			es[m].t=o;
			es[m].u=f2;
			es[m].v=x_vl[f1][f2];
//			if(x_vl[f1][f2]==0){
//				cout<<"YES";
//			}
		}
	}
	a=solve(n,m);
	cout<<a;
	return 0;
}
