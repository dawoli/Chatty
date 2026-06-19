#include<bits/stdc++.h>
using namespace std;
int T,n;
struct Node{
	int a,b,c,mx,mn,cha;
}x[100005];
bool cmp(Node p,Node q){
	return (p.mx-p.cha)>(q.mx-q.cha);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		int cnt1=0,cnt2=0,cnt3=0,ans=0;
		bool ok1=0,ok2=0,ok3=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d %d %d",&x[i].a,&x[i].b,&x[i].c);
			x[i].mx=0,x[i].mn=0,x[i].cha=0;
			x[i].mx=max({x[i].a,x[i].b,x[i].c});
			x[i].mn=min({x[i].a,x[i].b,x[i].c});
			x[i].cha=x[i].a+x[i].b+x[i].c-x[i].mx-x[i].mn;
		}
		sort(x+1,x+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(cnt1>=n/2)ok1=1;
			if(cnt2>=n/2)ok2=1;
			if(cnt3>=n/2)ok3=1;
			if(ok1==0&&ok2==0&&ok3==0){
				ans+=x[i].mx;
				if(x[i].a==x[i].mx)cnt1++;
				else if(x[i].b==x[i].mx)cnt2++;
				else if(x[i].c==x[i].mx)cnt3++;
			}
			if(ok1==1&&ok2==1&&ok3==0){
				ans+=x[i].c;
				cnt3++;
			}
			if(ok1==0&&ok2==1&&ok3==1){
				ans+=x[i].a;
				cnt1++;
			}
			if(ok1==1&&ok2==0&&ok3==1){
				ans+=x[i].b;
				cnt2++;
			}
			if(ok1==1&&ok2==0&&ok3==0){
				if(x[i].mx==x[i].a){
					int kkk=max(x[i].b,x[i].c);
					ans+=kkk;
					if(x[i].b==kkk)cnt2++;
					else if(x[i].c==kkk)cnt3++;
				}
				else {
					ans+=x[i].mx;
					if(x[i].b==x[i].mx)cnt2++;
					else if(x[i].c==x[i].mx)cnt3++;
				}
			} 
			if(ok1==0&&ok2==1&&ok3==0){ 
				if(x[i].mx==x[i].b){
					int kkk=max(x[i].a,x[i].c);
					ans+=kkk;
					if(x[i].a==kkk)cnt1++;
					else if(x[i].c==kkk)cnt3++;
				}
				else {
					ans+=x[i].mx;
					if(x[i].a==x[i].mx)cnt1++;
					else if(x[i].c==x[i].mx)cnt3++;
				}
			} 
			if(ok1==0&&ok2==0&&ok3==1){ 
				if(x[i].mx==x[i].c){
					int kkk=max(x[i].b,x[i].a);
					ans+=kkk;
					if(x[i].b==kkk)cnt2++;
					else if(x[i].a==kkk)cnt1++;
				}
				else {
					ans+=x[i].mx;
					if(x[i].b==x[i].mx)cnt2++;
					else if(x[i].a==x[i].mx)cnt1++;
				}
			} 
		}
		printf("%d\n",ans);
	}
	return 0;
}
