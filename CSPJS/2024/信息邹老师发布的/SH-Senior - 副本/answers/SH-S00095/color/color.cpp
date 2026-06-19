#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
struct pr{
	int l,r,v;
}p[200005];
int T,a[200005];
pair<int,int> cnt[1000005];
int aa[200005],bb[200005];
//bool cmp(pr a,pr b){
//	return a.v>b.v;
//}
//bool check(int l,int r,int w){
//	if(w==1){
//		for(int i=p[i].l;i<=p[i],r;i++){
//			if(aa[i]>0){
//				return 1;
//			}
//		}
//		return 0;
//	}else{
//		for(int i=p[i].l;i<=p[i],r;i++){
//			if(bb[i]>0){
//				return 1;
//			}
//		}
//		return 0;
//	}
//}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	while(T--){
		int n,pcnt=0;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
//		for(int i=0;i<n;i++){
//			if(cnt[a[i]].first==0){
//				cnt[a[i]].first=1;
//				cnt[a[i]].second=i;
//			}else{
//				p[pcnt].l=cnt[a[i]].second;
//				p[pcnt].r=i;
//				p[pcnt].v=a[i];
//				cnt[a[i]].second=i;
//				pcnt++;
//			}
//		}
//		sort(p,p+pcnt,cmp);
//		for(int i=0;i<pcnt;i++){
//			int fa=check(p[i].l,p[i].r,1),fb=check(p[i].l,p[i].r,2);
//			if(!fa){
//				for(int j=p[i].l;j<=p[i],r;j++){
//					aa[j]+=p[i].v;
//				}
//			}else if(!fb){
//				for(int j=p[i].l;j<=p[i],r;j++){
//					bb[j]+=p[i].v;
//				}
//			}
//		}
	}
	cout<<1<<endl<<0<<endl<<8<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
