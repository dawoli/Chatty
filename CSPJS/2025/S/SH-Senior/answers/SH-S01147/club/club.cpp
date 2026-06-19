#include<bits/stdc++.h>
using namespace std;
long long t,n,a[100010][5],s,x,y,xx,f1[100010],f2[100010],f3[100010],s1,s2,s3;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		s=0,s1=0,s2=0,s3=0;
		for(int i=1;i<=n;++i){
			scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
			x=0,y=0,xx=0;
			if(a[i][1]>=x){
				xx=x;
				y=1;
				x=a[i][1];
			}
			else if(a[i][1]>=xx)
				xx=a[i][1];
			if(a[i][2]>=x){
				xx=x;
				y=2;
				x=a[i][2];
			}
			else if(a[i][2]>=xx)
				xx=a[i][2];
			if(a[i][3]>=x){
				xx=x;
				y=3;
				x=a[i][3];
			}
			else if(a[i][3]>=xx)
				xx=a[i][3];
			s+=x;
			if(y==1)
				f1[++s1]=x-xx;
			else if(y==2)
				f2[++s2]=x-xx;
			else
				f3[++s3]=x-xx;
		}
		if(s1>(n/2)){
			sort(f1+1,f1+s1+1);
			for(int i=1;i<=s1-(n/2);++i)
				s-=f1[i];
		}
		else if(s2>(n/2)){
			sort(f2+1,f2+s2+1);
			for(int i=1;i<=s2-(n/2);++i)
				s-=f2[i];
		}
		else if(s3>(n/2)){
			sort(f3+1,f3+s3+1);
			for(int i=1;i<=s3-(n/2);++i)
				s-=f3[i];
		}
		printf("%lld\n",s);
	}
	return 0;
}
