#include<bits/stdc++.h>
using namespace std;
struct car{
	int d,v,a;
}c[100010];
pair<int,int>q[100010];
int num[100010];
int p[100010];
long double ex=1e-18,one=1.0;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,m,l,v,di,vi,ai,cnt=0;
		long double left_i,right_i;
		cin>>n>>m>>l>>v;//车数 测数 干道长 限速
		for(int i=0;i<n;i++){
			cin>>di>>vi>>ai;
			c[i].d=di;
			c[i].v=vi;
			c[i].a=ai;
		}
		for(int i=0;i<m;i++) cin>>p[i];
		sort(p,p+m-1);
		for(int i=0;i<n;i++){
			left_i=0,right_i=0;
			if(c[i].v>v&&c[i].a>=0){
				left_i=c[i].d,right_i=l+ex;
			}else if(c[i].v<=v&&c[i].a<=0){
				continue;
			}else if(c[i].v<=v&&c[i].a>0){
				left_i=min(one*l-ex,c[i].d+one*(v*v-c[i].v*c[i].v)/(2*c[i].a)),right_i=l+ex;
			}else if((c[i].v>v&&c[i].a<0)){
				left_i=c[i].d-ex,right_i=min(one*l+ex,c[i].d+one*(v*v-c[i].v*c[i].v)/(2*c[i].a));
			}
			int l_i=0,r_i=m-1;
			while(l_i<r_i){
				int mid=(r_i+l_i)>>1;
				if(p[mid]>left_i) r_i=mid;
				else l_i=mid+1;
			}
			int min_=l_i;
			l_i=0,r_i=m-1;
			while(l_i<r_i){
				int mid=((r_i+l_i)>>1)+1;
				if(p[mid]<right_i) l_i=mid;
				else r_i=mid-1;
			}
			int max_=r_i;
			if(min_<=max_){
				if(min_==0&&max_==0&&right_i<p[0]){
				}else if(min_==m-1&&max_==m-1&&left_i>p[m-1]){
				}else{
//					cout<<i<<' '<<min_<<" "<<max_<<" ";
					q[cnt].second=min_;
					q[cnt++].first=max_;
				}
			}
		}
//		cout<<"\n";
		sort(q,q+cnt);
//		for(int i=0;i<cnt;i++) cout<<q[i].first<<" "<<q[i].second<<"\n";
		int cnt2=1;
		num[0]=q[0].first;
		for(int i=1;i<cnt;i++){
			if(num[cnt2-1]<q[i].second){
				num[cnt2++]=q[i].first;
			}
		}
//		for(int i=0;i<cnt2;i++) cout<<num[i]<<' ';
//		cout<<'\n';
		cout<<cnt<<' '<<m-cnt2<<"\n";
	}
} 
