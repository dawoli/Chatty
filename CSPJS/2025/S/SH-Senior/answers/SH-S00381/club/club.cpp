#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;

struct k{
	long long a1,a2,a3;
	int b1,b2,b3;
};

long long n,m,t,xz,ans;
k a[N];
long long cnt[5];

bool cmp(k x,k y){
	return (x.a1-x.a2)>(y.a1-y.a2);
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	for(int z=1;z<=t;z++){
		cin>>n;
		cnt[1]=0;
		cnt[2]=0;
		cnt[3]=0;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			a[i].b1=1;
			a[i].b2=2;
			a[i].b3=3;
			if(a[i].a1<a[i].a2){
				swap(a[i].a1,a[i].a2);
				swap(a[i].b1,a[i].b2);
			}
			if(a[i].a2<a[i].a3){
				swap(a[i].a2,a[i].a3);
				swap(a[i].b2,a[i].b3);
				if(a[i].a1<a[i].a2){
					swap(a[i].a1,a[i].a2);
					swap(a[i].b1,a[i].b2);
				}
			}
		}
		sort(a+1,a+1+n,cmp);
		xz=n/2;
		for(int i=1;i<=n;i++){
			if(cnt[a[i].b1]<xz){
				cnt[a[i].b1]++;
				ans+=a[i].a1;
			}else{
				ans+=a[i].a2;
			}
		}
		cout<<ans<<"\n";
	}
	
	
	
	
	
	
	
	return 0;
}
