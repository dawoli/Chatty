#include<bits/stdc++.h>//5pts
using namespace std;
const int N=1e5+5;
int t,n,cnt1,cnt2,cnt3;
struct node{
	int a1,a2,a3,maxn;
}a[N];
bool cmp1(node a,node b){
	return a.a1<b.a1;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i].a1>>a[i].a2>>a[i].a3;
		sort(a+1,a+n+1,cmp1);
		for(int i=n;i>n/2;i--) cnt1=a[i].a1+a[i+1].a1;
		cout<<cnt1<<"\n";
	}
	return 0;
}
