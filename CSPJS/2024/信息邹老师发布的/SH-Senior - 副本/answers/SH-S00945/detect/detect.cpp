#include<bits/stdc++.h>
using namespace std;
const int N = 100003;
int T,n,m,L,V,p[N],cnt;
bool flaga0,flaga1;
struct car{
	int d,v,a;
	int stp,edp;
}c[N];
void solve0(){
	for(int i = 1;i<=n;i++){
		if(c[i].v<=V) continue;
		int pid = lower_bound(p+1,p+1+m,c[i].d)-p;
		if(pid!=m+1){
			++cnt;
			c[i].stp = pid;
			c[i].edp = m;
		}
	}
	cout<<cnt<<" "<<(cnt==0?m:m-1)<<endl;
}
void solveD1(){
	for(int i = 1;i<=n;i++){
		if(c[i].a==0){
			if(c[i].v>V){
				int pid = lower_bound(p+1,p+1+m,c[i].d)-p;
				if(pid!=m+1){
					++cnt;
					c[i].stp = pid;
					c[i].edp = m;
				}
			}
		}
		else if(c[i].a>0){
			if(c[i].v>V){
				int pid = lower_bound(p+1,p+1+m,c[i].d)-p;
				if(pid!=m+1){
					++cnt;
					c[i].stp = pid;
					c[i].edp = m;
				}
				continue;
			}
			double t = (V-c[i].v)*1.0/c[i].a;
			double s0 = c[i].d+c[i].v*t+c[i].a*t*t/2;
			int pid = upper_bound(p+1,p+1+m,s0)-p;
			if(pid!=m+1){
				++cnt;
				c[i].stp = pid;
				c[i].edp = m;
			}
		}
		else{
			if(c[i].v>V){
				double t = (V-c[i].v)/c[i].a;
				double s0 = c[i].d+c[i].v*t+c[i].a*t*t/2;
				int pid0 = lower_bound(p+1,p+1+m,c[i].d)-p;
				int pid = lower_bound(p+1,p+1+m,floor(s0))-p-1;
				if(pid0<=pid){
					++cnt;
					c[i].stp = pid0;
					c[i].edp = pid;
				}
			}
		}
	}
	cout<<cnt<<" ";
//	for(int i = 1;i<=n;i++){
//		cout<<"Car "<<i<<": "<<c[i].stp<<" "<<c[i].edp<<endl;
//	}
}
void solve12(){
	cout<<(cnt==0?m:m-1)<<endl;
}
int pans[N];
void solveD2(){
	int cnt_ok = n-cnt,cntp = 0;
	memset(pans,0,sizeof(pans));
	for(int i = 1;i<=n;i++){
		if(c[i].stp!=0&&c[i].edp!=0){
			pans[c[i].stp]+=1;
			pans[c[i].edp+1]-=1;
		}
	}
	while(cnt_ok<n){
		++cntp;
		int maxval = 0,maxid = 0,psq = pans[0];
		for(int i = 1;i<=m;i++){
			psq+=pans[i];
			if(psq>maxval){
				maxval = psq;
				maxid = i;
			}
		}
		for(int i = 1;i<=n;i++){
			if(c[i].stp<=maxid&&c[i].edp>=maxid){
				pans[c[i].stp]-=1;
				pans[c[i].edp+1]+=1;
				c[i].stp = c[i].edp = 0;
				++cnt_ok;
			}
		}
//		cout<<"Choosed: "<<maxid<<", now_ok = "<<cnt_ok<<endl;
	}
	cout<<n-cntp<<endl;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	while(T--){
		flaga0 = flaga1 = 1,cnt = 0;
		cin>>n>>m>>L>>V;
		for(int i = 1;i<=n;i++){
			cin>>c[i].d>>c[i].v>>c[i].a;
			c[i].stp = c[i].edp = 0;
			if(c[i].a!=0) flaga0 = 0;
			if(c[i].a<=0) flaga1 = 0;
		}
		for(int i = 1;i<=m;i++) cin>>p[i];
		if(flaga0){
			solve0();
			continue;
		}
		solveD1();
		if(flaga1){
			solve12();
			continue;
		}
		else if(n<=3000){
			solveD2();
			continue;
		}
	}
	return 0;
}
