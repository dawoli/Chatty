#include<bits/stdc++.h>
using namespace std;
const long long MOD=998244353;
int n,a[5005],ans,cnt,maxa,num;
void duo(int x){
	if(x==n){
		if(num>=3 && cnt>maxa*2){
			ans++;
		}
		return;
	}
	if(num>=3 && cnt>maxa*2){
		ans++;
	}
	for(int i=x+1;i<=n;i++){
		cnt+=a[i];
		num++;
		int f=maxa;
		maxa=max(f,a[i]);
		duo(i);
		maxa=f;
		cnt-=a[i];
		num--;
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >>n;
	for(int i=1;i<=n;i++){
		cin >>a[i];
	}
	for(int i=1;i<=n;i++){
		num=1;
		cnt=a[i];
		maxa=a[i];
		duo(i);
	}
	cout << ans;
	return 0;
}
