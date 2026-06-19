#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N],cnt[N]={1};
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	for(int i=1;i<=N;i++){
		cnt[i]=1;
	}
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int t=1;
	for(int i=1;i<n;i++){
		if(a[i]==a[i+1]) cnt[t]++;
		if(a[i]!=a[i+1]) t++;
	}
	if(t<=2){
		cout<<cnt[2]+max(cnt[1]-cnt[2],0);
		return 0;
	}
	if(n<=10){
		int sum=0;
		while(t>1){
			for(int i=1;i<=t;i++){
				if(cnt[i+1]-cnt[i]>=0){
					sum+=cnt[i];
					for(int j=i;j<t;j++){
						a[j]=a[j+1];
					}
				}
				if(cnt[i+1]-cnt[i]<0){
					sum+=cnt[i+1];
					cnt[i]+=cnt[i+1];
					for(int j=i+1;i<t;j++){
						a[j]=a[j+1];
					}
				}
				t--;
			}
		}
		cout<<n-sum;
		return 0;
	}
	cout<<1;
	return 0;
}
