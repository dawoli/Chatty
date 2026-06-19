#include<bits/stdc++.h>
using namespace std;
int t,n,a,b,c,l[100005],x,y,z,ch[100005],ma,k,p[100005],m;
long long ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		x=0;
		y=0;
		z=0;
		m=0;
		ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a,&b,&c);
			if(a>b&&a>c)ch[i]=1,x++;
			if(b>a&&b>c)ch[i]=2,y++;
			if(c>b&&c>a)ch[i]=3,z++;
			if(a<b)swap(a,b);
			if(b<c)swap(b,c);
			if(a<b)swap(a,b);
			l[i]=a-b;
			ans+=a;
		}
		if(x>y&&x>y)ma=1,k=x-n/2;
		if(y>x&&y>z)ma=2,k=y-n/2;
		if(z>y&&z>x)ma=3,k=z-n/2;
		for(int i=1;i<=n;i++){
			if(ch[i]==ma){
				m++;
				p[m]=l[i];
			}
		}
		sort(p+1,p+m+1);
		for(int i=1;i<=k;i++){
			ans-=p[i];
		}
		printf("%lld\n",ans);
	}
	return 0;
}
