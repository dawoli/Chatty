#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[5005];
int que[5005];
bool cmp(int a1,int a2){
	return a1<a2;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		que[i]=que[i-1]+a[i];
	}
	sort(a+1,a+n+1,cmp);
	int cnt=0;
	for(int q=3;q<=n;q++){
		for(int i=1;i<=n-q+1;i++){
			int maxn=2*a[i+q-1];
			int ant=que[i+q-1]-que[i-1];
			if(ant>maxn){
				cnt++;
				cnt=cnt%998244353;
			}
		}
		
	}
	cout<<cnt+4;
}
