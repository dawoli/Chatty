#include<iostream>
#include<algorithm>
using namespace std;
struct node{
	long long a,b,c;
}a[100050];
long long n,t,ans,c1,c2,c3,c0,c00;
void dfs(int dep,long long sum){
	if (dep==n+1){
		ans=max(sum,ans);
		return;
	}
	if (c1<n/2){
		c1++;
		dfs(dep+1,sum+a[dep].a);
		c1--;
	}
	if (c2<n/2){
		c2++;
		dfs(dep+1,sum+a[dep].b);
		c2--;
	}
	if (c3<n/2){
		c3++;
		dfs(dep+1,sum+a[dep].c);
		c3--;
	}
	return;
}
bool cmp(node a,node b){
	return (a.a>b.a);
}
bool cmp1(node a,node b){
	return (a.b>b.b);
}
int main(){
	freopen("club4.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while (t--){
		cin>>n;
		c1=c2=c3=0;
		c0=c00=0;
		ans=0;
		for (int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			if (a[i].b==0&&a[i].b==a[i].c){
				c0++;
			}
			if (a[i].c==0){
				c00++;
			}
		}
		if (c0==n){
			sort(a+1,a+n+1,cmp);
			for (int i=1;i<=n/2;i++){
				ans+=a[i].a;
			}
			cout<<ans<<endl;
			continue;
		}
		if (c00==n){
			long long ans1=0,ans2=0;
			sort(a+1,a+n+1,cmp);
			for (int i=1;i<=n/2;i++){
				ans1+=a[i].a;
			}
			for (int i=n/2+1;i<=n;i++){
				ans1+=a[i].b;
			}
			sort(a+1,a+n+1,cmp1);
			for (int i=1;i<=n/2;i++){
				ans2+=a[i].b;
			}
			for (int i=n/2+1;i<=n;i++){
				ans2+=a[i].a;
			}
			cout<<max(ans1,ans2)<<endl;
			continue;
		}
		dfs(1,0);
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}//25
