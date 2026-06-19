#include <bits/stdc++.h>
using namespace std;
int a[100005],s[100005];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n; cin>>n;
	int maxn=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(maxn<=2){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1) cnt++;
		}
		cout<<n-cnt+max(0,2*cnt-n);
	}else{
		sort(a+1,a+1+n);
	//	for(int i=1;i<=n;i++){
		//	cout<<a[i];
	//  }
		int net=a[1];
		int num=1;
		s[num]=1;
		for(int i=2;i<=n;i++){
			if(a[i]>net){
				net=a[i];
				s[++num]++;
			}else{
				s[num]++;
			}
		}
		int ans=n;
		int t=s[1];
		for(int i=2;i<=num;i++){
			if(t>=s[i]){
				ans-=s[i];
			}else{
				ans-=t;
				t=s[i];
			}
		}
		cout<<ans;
	}
	return 0;
}
