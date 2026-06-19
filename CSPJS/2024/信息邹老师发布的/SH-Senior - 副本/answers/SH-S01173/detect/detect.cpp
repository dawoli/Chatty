#include <bits/stdc++.h>
#define N 100050
using namespace std;
long long n,m,L,k;
long long cnt=0;//³¬ËÙ³µÊý 
long long d[N],v[N],a[N],p[N];
struct QuJian{
	long long l;
	long long r;
} qj[N];
bool cmp(QuJian qja,QuJian qjm){
	return qja.l<qjm.l;
}
priority_queue<long long,vector<long long>,greater<long long> > qu;
long long ql,qr;
void cal(long long q){
	long long pa=k*k-v[q]*v[q];
	long long pb=2*a[q];
	if(pb==0){
		if(v[q]>k){
			ql=d[q]; qr=L;
		}
		else{
			ql=-1; qr=-1;
		}
	}
	else if(pa*pb<0){
		if(a[q]<0){
			ql=-1; qr=-1;
		}
		else{
			ql=d[q]; qr=L;
		}
	}
	else if(a[q]<0){
		pa=-pa; pb=-pb;
		if(pa%pb==0) qr=d[q]+pa/pb-1;
		else qr=d[q]+pa/pb;
		ql=d[q];
	}
	else{
		ql=d[q]+pa/pb+1;
		qr=L;
	}
	return;
}
signed main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
	scanf("%lld %lld %lld %lld",&n,&m,&L,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld %lld %lld",&d[i],&v[i],&a[i]);
	}
	for(int i=1;i<=m;i++) scanf("%lld",&p[i]);
	cnt=0;
	for(int i=1;i<=n;i++){
		cal(i);
//		cout<<i<<"->"<<ql<<"-"<<qr<<endl;
		if(ql==-1) continue;
		ql=int(lower_bound(p+1,p+m+1,ql)-p);
		qr=int(upper_bound(p+1,p+m+1,qr)-p-1);
		if(ql>qr) continue;
		cnt++;
		qj[cnt].l=ql; qj[cnt].r=qr;
	}
	printf("%lld ",cnt);
	sort(qj+1,qj+cnt+1,cmp);
//	for(int i=1;i<=cnt;i++) cout<<qj[i].l<<"-"<<qj[i].r<<endl;
	int s=1;
	int ans=0;
	while(!qu.empty()) qu.pop();
	for(int i=1;i<=m;i++){
//		cout<<i<<endl;
		while(qj[s].l<=i&&s<=cnt){
//			cout<<"push"<<s<<": "<<qj[s].r<<endl; 
			qu.push(qj[s].r);
			s++;
		}
		if(!qu.empty()&&qu.top()==i){
			ans++;
			while(!qu.empty()){
//				cout<<"pop"<<qu.top()<<endl;
				qu.pop();
			}
		}
	}
	printf("%lld\n",m-ans);
}
	return 0;
}
