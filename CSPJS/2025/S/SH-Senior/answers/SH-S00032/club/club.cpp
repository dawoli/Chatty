#include<bits/stdc++.h>
using namespace std;
const int N=100009;
int n;
struct mem{
	int d[4];
	int bst,bst1,del;
}a[N];
bool cmp(const mem&A,const mem&B){
	return A.del<B.del;
}
int cnt[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cnt[0]=cnt[1]=cnt[2]=0;
		int ans=0;
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i].d[0]>>a[i].d[1]>>a[i].d[2];
		for(int i=1;i<=n;i++){
			int k=0,j=3;
			if(a[i].d[1]>a[i].d[0]) k=1;
			if(a[i].d[2]>a[i].d[k]) k=2;
			for(int l=0;l<=2;l++){
				if(l==k) continue;
				if(a[i].d[l]>=a[i].d[j]) j=l;
			}
			a[i].bst=k,a[i].bst1=j;
			a[i].del=a[i].d[k]-a[i].d[j];
			cnt[k]++; ans+=a[i].d[k];
		}
		int wh=-1;
		for(int i=0;i<=2;i++)
			if(cnt[i]>n/2) wh=i;
		if(wh==-1){
			cout<<ans<<endl;
			continue;
		}
		//cout<<"ok"<<ans<<endl;
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n&&cnt[wh]>n/2;i++){
			if(a[i].bst!=wh) continue;
			cnt[wh]--;
			ans-=a[i].del;
		}
		cout<<ans<<endl;
	}
	return 0;
} 
