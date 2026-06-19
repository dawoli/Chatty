#include<iostream>
#include<algorithm>
using namespace std;
int T,n;
const int N=1e5+5;
struct Node{int a,b,c;}pps[4*N];
int a[N],b[N],c[N];
int cnta,cntb,cntc;
int cnt1[100005][5],cnt2[100005],ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		ans=0;
		for(int i=1;i<=100005;i++){
			a[i]=0,b[i]=0,c[i]=0;
			pps[i].a=0,pps[i].b=0,pps[i].c=0;
			cnta=0,cntb=0,cntc=0;
		}
		for(int i=1;i<=n;i++){
			int ia,ib,ic;
			cin>>ia>>ib>>ic;
			pps[i].a=ia,pps[i].b=ib,pps[i].c=ic;
			if(ia>=ib and ia>=ic) a[++cnta]=i;
			if(ib>ia and ib>=ic) b[++cntb]=i;
			if(ic>ia and ic>ib) c[++cntc]=i;
		}if(cnta>n/2){
			for(int i=1;i<=cnta;i++){
				cnt1[i][1]=pps[a[i]].a-pps[a[i]].b;
				cnt1[i][2]=pps[a[i]].a-pps[a[i]].c;
				if(cntb>=n/2) cnt1[i][1]=2147483647;
				if(cntc>=n/2) cnt1[i][2]=2147483647;
				cnt2[i]=min(cnt1[i][1],cnt1[i][2]);
			}
			sort(cnt2+1,cnt2+1+cnta);
			for(int i=1;i<=cnta-n/2;i++)
				ans-=cnt2[i];
		}else if(cntb>n/2){
			for(int i=1;i<=cntb;i++){
				cnt1[i][1]=pps[b[i]].b-pps[b[i]].a;
				cnt1[i][2]=pps[b[i]].b-pps[b[i]].c;
				if(cnta>=n/2) cnt1[i][1]=2147483647;
				if(cntc>=n/2) cnt1[i][2]=2147483647;
				cnt2[i]=min(cnt1[i][1],cnt1[i][2]);
			}
			sort(cnt2+1,cnt2+1+cntb);
			for(int i=1;i<=cntb-n/2;i++)
				ans-=cnt2[i];
		}else if(cntc>n/2){
			for(int i=1;i<=cntc;i++){
				cnt1[i][1]=pps[c[i]].c-pps[c[i]].a;
				cnt1[i][2]=pps[c[i]].c-pps[c[i]].b;
				if(cntb>=n/2) cnt1[i][2]=2147483647;
				if(cnta>=n/2) cnt1[i][1]=2147483647;
				cnt2[i]=min(cnt1[i][1],cnt1[i][2]);
			}
			sort(cnt2+1,cnt2+1+cntc);
			for(int i=1;i<=cntc-n/2;i++)
				ans-=cnt2[i];
		}
		for(int i=1;i<=n;i++) ans+=(pps[a[i]].a+pps[b[i]].b+pps[c[i]].c);
		cout<<ans<<endl;
	}
	return 0;
} 
