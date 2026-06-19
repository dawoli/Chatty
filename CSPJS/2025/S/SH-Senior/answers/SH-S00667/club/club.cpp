#include <bits/stdc++.h>
using namespace std;
int t,n,cnt[10];
long long ans;
struct S{
	int a,b,c,k,l;
} a[100010];
bool cmp(S &a,S &b){
	return a.l<b.l;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int aa=1;aa<=t;++aa){
		cin>>n;
		cnt[1]=cnt[2]=cnt[3]=ans=0;
		for(int i=1;i<=n;++i){
			cin>>a[i].a>>a[i].b>>a[i].c;
			if(a[i].a>=a[i].b&&a[i].a>=a[i].c){
				a[i].k=1;
				++cnt[1];
				ans+=a[i].a;
				if(a[i].b>=a[i].c)
					a[i].l=a[i].a-a[i].b;
				else
					a[i].l=a[i].a-a[i].c;
				continue;
			}
			if(a[i].b>=a[i].a&&a[i].b>=a[i].c){
				a[i].k=2;
				++cnt[2];
				ans+=a[i].b;
				if(a[i].a>=a[i].c)
					a[i].l=a[i].b-a[i].a;
				else
					a[i].l=a[i].b-a[i].c;
				continue;
			}
			if(a[i].c>=a[i].b&&a[i].c>=a[i].a){
				a[i].k=3;
				++cnt[3];
				ans+=a[i].c;
				if(a[i].a>=a[i].b)
					a[i].l=a[i].c-a[i].a;
				else
					a[i].l=a[i].c-a[i].b;
			}
		}
		for(int i=1;i<=3;++i){
			if(cnt[i]>n/2){
				sort(a+1,a+n+1,cmp);
				int x=0;
				for(int j=1;j<=n;++j){
					if(i==a[j].k){
						ans-=a[j].l;
						++x;
					}
					if(cnt[i]-x==n/2)
						break;
				}
				break;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
