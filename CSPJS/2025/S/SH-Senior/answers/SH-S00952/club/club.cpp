#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b,c,num;
};
int t,n;
node a[100009];
bool cmp(node x,node y){
	return x.num>y.num;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		int cnt1=0,cnt2=0,cnt3=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			int x=a[i].a,y=a[i].b,z=a[i].c;
			if(x>=y&&x>=z){
				a[i].num=x-max(y,z);
				cnt1++;
			}
			else if(y>=x&&y>=z){
				a[i].num=y-max(x,z);
				cnt2++;
			}
			else if(z>=x&&z>=y){
				a[i].num=z-max(x,y);
				cnt3++;
			}
		}
		int ans=0;
		if(cnt1<=n/2&&cnt2<=n/2&&cnt3<=n/2){
			for(int i=1;i<=n;i++){
				ans+=max(a[i].a,max(a[i].b,a[i].c));
			}
			cout<<ans<<"\n";
			continue;
		}
		sort(a+1,a+n+1,cmp);
		if(cnt1>n/2){
			cnt1=0;
			for(int i=1;i<=n;i++){
				if(a[i].a>=a[i].b&&a[i].a>=a[i].c&&cnt1<n/2){
					ans+=a[i].a;
					cnt1++;
				}
				else{
					ans+=max(a[i].b,a[i].c);
				}
			}
		}
		else if(cnt2>n/2){
			cnt2=0;
			for(int i=1;i<=n;i++){
				if(a[i].b>=a[i].a&&a[i].b>=a[i].c&&cnt2<n/2){
					ans+=a[i].b;
					cnt2++;
				}
				else{
					ans+=max(a[i].a,a[i].c);
				}
			}
		}
		
		else if(cnt3>n/2){
			cnt3=0;
			for(int i=1;i<=n;i++){
				if(a[i].c>=a[i].b&&a[i].c>=a[i].a&&cnt3<n/2){
					ans+=a[i].c;
					cnt3++;
				}
				else{
					ans+=max(a[i].a,a[i].b);
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
