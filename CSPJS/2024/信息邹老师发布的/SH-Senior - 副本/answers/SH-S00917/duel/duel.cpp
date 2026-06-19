#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <deque>
#include <iomanip>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;
struct mst{
	long long r,cnt;
}a[100005];
long long n,arr[100005],xb,ans;
bool cmp(mst a,mst b){
	return a.r<b.r;
}
signed main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>arr[i];
	}
	sort(arr+1,arr+1+n);
	ans=n;
	for(long long i=1;i<=n;i++){
		if(arr[i]!=arr[i-1]){
			a[++xb].r=arr[i];
		}
		a[xb].cnt++;
	}
	sort(a+1,a+1+xb,cmp);
	for(long long i=1;i<xb;i++){
		if(a[i].cnt<=a[i+1].cnt){
			ans-=a[i].cnt;
		}else{
			ans-=a[i+1].cnt; 
			a[i+1].cnt+=(a[i].cnt-a[i+1].cnt);
		}
	}
	cout<<ans;
	return 0;
}

