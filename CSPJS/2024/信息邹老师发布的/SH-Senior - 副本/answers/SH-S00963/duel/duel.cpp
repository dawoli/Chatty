#include <bits/stdc++.h>
using namespace std;

int n,ans;
int a[100005],b[100005],idx;

int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int num;
		cin>>num;
		if(a[num]==0) b[++idx]=num;
		a[num]++;
	}
	sort(b+1,b+1+idx);
	int num=0;
	for(int i=2;i<=idx;i++){
		int cnt=a[b[i]];
		if(cnt>a[b[i-1]]){
			ans+=a[b[i-1]];
			cnt-=a[b[i-1]];
			if(cnt>num){
				ans+=num;
			}else{
				ans+=cnt;
				num-=cnt;
			}
		}else{
			ans+=cnt;
			num+=a[b[i-1]]-cnt;
		}
	}
	cout<<n-ans;
	return 0;
}
