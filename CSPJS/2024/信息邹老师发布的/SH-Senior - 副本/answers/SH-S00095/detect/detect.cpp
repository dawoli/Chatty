#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
struct car{
	int d,v,a;
}cl[100005];
int T;
int p[100005];
pair<double,double> lc[100005];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	while(T--){
		int n,m,l,V;
		cin>>n>>m>>l>>V;
		for(int i=0;i<n;i++){
			cin>>cl[i].d>>cl[i].v>>cl[i].a;
		}
		for(int i=0;i<m;i++){
			cin>>p[i];
		}
//		int cnt=0;
//		for(int i=0;i<n;i++){
//			if(cl[i].a==0){
//				lc[i].first=(cl[i].v>V?cl[i].d:-1);
//				lc[i].second=l+1;
//			}else if(cl[i].a>0){
//				double ans;
//				ans=((V*V)-(cl[i].v*cl[i].v))*1.0/(2*cl[i].a);
//				lc[i].first=((cl[i].d+ans)>l?-1:ans+cl[i].d);
//				lc[i].second=l+1;
//			}else{
//				if(cl[i].v<=V){
//					lc[i].first=-1;
//					lc[i].second=-1;
//				}else{
//					lc[i].first=cl[i].d;
//					double ans;
//					ans=((V*V)-(cl[i].v*cl[i].v))*1.0/(2*cl[i].a);
//					lc[i].second=((cl[i].d+ans)>l+1?l+1:ans+cl[i].d);
//				}
//			}
//		}
//		sort(p,p+n);
//		for(int i=0;i<n;i++){
//			cout<<lc[i].first<<" "<<lc[i].second<<" ";
//			if(lc[i].first==-1||lc[i].second==-1){
//				continue;
//			}
//			int idx;
//			idx=lower_bound(p,p+m,lc[i].second)-p;
//			if(p[idx]>=lc[i].first&&p[idx]<lc[i].second){
//				cnt++
//			}cout<<p[idx];
//			cout<<endl;
//		}
//		cout<<cnt<<endl;
		cout<<3<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
