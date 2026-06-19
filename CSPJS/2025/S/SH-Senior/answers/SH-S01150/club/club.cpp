#include<bits/stdc++.h>
using namespace std;
int ct=0,cnt=0,rr[5],pp[100005];
struct s{
	int p,r,nu;
}a[100005];
bool cmp(s a,s b){
	return a.nu>b.nu;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		long long sum=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[++ct].nu;
			a[ct].p=i;
			a[ct].r=1;
			cin>>a[++ct].nu;
			a[ct].p=i;
			a[ct].r=2;
			cin>>a[++ct].nu;
			a[ct].p=i;
			a[ct].r=3;
		}
		sort(a+1,a+ct+1,cmp);
		for(int i=1;i<=ct;i++){
			if(rr[a[i].r]<=n/2 && pp[a[i].p]==0){
				rr[a[i].r]++,pp[a[i].p]++;
				sum+=a[i].nu;
				cnt++;
			}
			if(cnt==n){
				break;
			}
		}
		cout<<sum<<endl;
		for(int i=1;i<=n;i++){
			pp[i]=0,rr[i]=0;
		}
		for(int i=1;i<=ct;i++){
			a[i].p=0,a[i].r=0,a[i].nu=0;
		}
		sum=0,cnt=0,ct=0;
	}
	return 0;
}
