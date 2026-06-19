#include<bits/stdc++.h>
using namespace std;
int t,n,su,sv,sw,s;
struct stu{
	int u,v,w;
	int sum;
	char x;
}a[1000005];
bool cmp1(stu a,stu b){
	int asum = a.u-max(a.v,a.w),bsum = b.u-max(b.v,b.w);
	return asum < bsum;
}
bool cmp2(stu a,stu b){
	int asum = a.v-max(a.u,a.w),bsum = b.v-max(b.u,b.w);
	return asum < bsum;
}
bool cmp3(stu a,stu b){
	int asum = a.w-max(a.u,a.v),bsum = b.w-max(b.u,b.v);
	return asum < bsum;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		su = 0;
		sv = 0;
		sw = 0;
		s = 0;
		cin>>n;
		for(int i = 1;i <= n;i++){
			scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
			a[i].sum = a[i].u+a[i].v+a[i].w;
			if(max(a[i].u,max(a[i].v,a[i].w)) == a[i].u){
				su++;
				s += a[i].u;
				a[i].x = 'U';
			}
			else if(max(a[i].u,max(a[i].v,a[i].w)) == a[i].v){
				sv++;
				s += a[i].v;
				a[i].x = 'V';
			}
			else{
				sw++;
				s += a[i].w;
				a[i].x = 'W';
			}
		}
		if(su > n/2){
			sort(a+1,a+n+1,cmp1);
			for(int i = 1;i <= n && su > n/2;i++){
				if(a[i].x == 'U'){
					s -= a[i].u-max(a[i].v,a[i].w);
					su--;
				}
			}
		}
		else if(sv > n/2){
			sort(a+1,a+n+1,cmp2);
			for(int i = 1;i <= n && sv > n/2;i++){
				if(a[i].x == 'V'){
					s -= a[i].v-max(a[i].u,a[i].w);
					sv--;
				}
			}
		}
		else{
			sort(a+1,a+n+1,cmp3);
			for(int i = 1;i <= n && sw > n/2;i++){
				if(a[i].x == 'W'){
					s -= a[i].w-max(a[i].u,a[i].v);
					sw--;
				}
			}
		}
		printf("%d\n",s);
	}
	return 0;
}

