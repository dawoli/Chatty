#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int ans=0;
struct student{
	int a;
	int b;
	int c;
};
int max3(int a,int b,int c){
	return max(max(a,b),c);
} 
bool cmp(student a,student b){
	if(a.a>b.a)
		return 1;
	if(a.a==b.a){
		if(a.b>b.b)
			return 1;
		if(a.b==b.b)
			if(a.c>b.c)
				return 1;
	}
	return 0;
}
int findx(int a,int b,int c){
	if(a==max3(a,b,c))
		return 1;
	if(b==max3(a,b,c))
		return 2;
	if(c==max3(a,b,c))
		return 3;
}
student st[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	int n;
	for(int i=1;i<=T;i++){
		ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&st[i].a,&st[i].b,&st[i].c);
		}
	
		int cnt1=0,cnt2=0,cnt3=0;
		int cntmax=n/2;
		sort(st+1,st+n+1,cmp);
		ans+=max3(st[1].a,st[1].b,st[1].c);
		if(findx(st[1].a,st[1].b,st[1].c)==1)
			cnt1++;
		if(findx(st[1].a,st[1].b,st[1].c)==2)
			cnt2++;
		if(findx(st[1].a,st[1].b,st[1].c)==3)
			cnt3++;
	
		for(int i=2;i<=n;i++){
			if((findx(st[i].a,st[i].b,st[i].c)==1)&&(cnt1<cntmax)){
				ans+=st[i].a;
				cnt1++;
			}
			if((findx(st[i].a,st[i].b,st[i].c)==2)&&(cnt2<cntmax)){
				ans+=st[i].b;
				cnt2++;
			}
			if((findx(st[i].a,st[i].b,st[i].c)==3)&&(cnt3<cntmax)){
				ans+=st[i].c;
				cnt3++;
			}
		}
			cout<<ans;
			cout<<endl;
	}
	return 0;
}
