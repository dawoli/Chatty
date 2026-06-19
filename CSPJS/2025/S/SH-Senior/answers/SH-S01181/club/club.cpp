#include <bits/stdc++.h>
using namespace std;
struct st{
	long long x,y,z,w;
}c[100005];
struct ll{
	long long w,id;
};
ll ch[100005];
int h1[100005],h2[100005],h3[100005];
bool cmp(ll q,ll p){
	return q.w<p.w;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		long long ans=0,l1=0,l2=0,l3=0;
		int a,b,ck;
		for(int i=1;i<=n;i++){
			cin>>a>>b>>ck;
			c[i].x=a;
			c[i].y=b;
			c[i].z=ck;
			c[i].w=max(a,max(b,ck))-(a+b+ck-max(a,max(b,ck))-min(a,min(b,ck)));
		}
		for(int i=1;i<=n;i++){
			a=c[i].x,b=c[i].y,ck=c[i].z;
			if(max(a,max(b,ck))==a) h1[l1++]=i;
			else if(max(a,max(b,ck))==b) h2[l2++]=i;
			else h3[l3++]=i;
		}
		if(l1>n/2){
			int l=l1,cnt=1;
			for(int i=0;i<l;i++) {
				ch[cnt].id=h1[i];
				ch[cnt++].w=c[h1[i]].w;
			}
			sort(ch+1,ch+cnt,cmp);
			for(int i=1;i<=l-n/2;i++) {
				ans+=max(c[ch[i].id].y,c[ch[i].id].z);
				c[ch[i].id].x=0;
			}
		}
		else if(l2>n/2){
			int l=l2,cnt=1;
			for(int i=0;i<l;i++) {
				ch[cnt].id=h2[i];
				ch[cnt++].w=c[h2[i]].w;
			}
			sort(ch+1,ch+cnt,cmp);
			for(int i=1;i<=l-n/2;i++) {
				ans+=max(c[ch[i].id].x,c[ch[i].id].z);
				c[ch[i].id].y=0;
			}
		}
		else{
			int l=l3,cnt=1;
			for(int i=0;i<l;i++) {
				ch[cnt].id=h3[i];
				ch[cnt++].w=c[h3[i]].w;
			}
			sort(ch+1,ch+cnt,cmp);
			for(int i=1;i<=l-n/2;i++) {
				ans+=max(c[ch[i].id].y,c[ch[i].id].x);
				c[ch[i].id].z=0;
			}
		}
		for(int i=0;i<l1;i++) ans+=c[h1[i]].x;
		for(int i=0;i<l2;i++) ans+=c[h2[i]].y;
		for(int i=0;i<l3;i++) ans+=c[h3[i]].z;
		cout<<ans<<endl;
	}
	return 0;
}
