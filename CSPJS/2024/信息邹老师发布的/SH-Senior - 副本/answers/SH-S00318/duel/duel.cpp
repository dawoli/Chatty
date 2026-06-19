#include<bits/stdc++.h>
using namespace std;
int n,r[100009],cnt,ans,a[100009],cnt1=0;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>r[i];
		if(r[i]>ans)
			ans=r[i];
		a[r[i]-1]++;
	}
	if(ans==2){
		cout<<max(a[0],a[1]);
		return 0;
	}
	if(n==1){
		cout<<"1";
		return 0;
	}
	sort(r,r+n);
	for(int i=1;i<n;++i){
		cnt1=0;
		for(int j=i-1;j>=0;--j){
			if(cnt1==1)
				continue;
			if(r[j]!=0&&(r[j]<r[i])){
				r[j]=0;
				cnt++;
				cnt1=1;
				continue;
			}
		}
	}
	cout<<n-cnt;
	return 0;
}
