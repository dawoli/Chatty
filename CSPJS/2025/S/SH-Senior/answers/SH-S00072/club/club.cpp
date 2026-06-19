#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct node{
	int p1,p2,p3;
}a[N];
bool cmp1(node x,node y){
	return x.p1>y.p1;
}
bool cmp2(node x,node y){
	return x.p2>y.p2;
}
bool cmp3(node x,node y){
	return x.p3>y.p3;
}
void solve(){
	int n,ans1=0,ans2=0,ans3=0,p[5],cnt02=0,cnt03=0;
	memset(p,0,sizeof(p));
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].p1>>a[i].p2>>a[i].p3;
		if(a[i].p2==0)cnt02++;
		if(a[i].p3==0)cnt03++; 
	}
	sort(a+1,a+n+1,cmp1);
	if(cnt02==n&&cnt03==n){
		for(int i=1;i<=n/2;i++){
			ans1+=a[i].p1;
		}
		cout<<ans1<<endl;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(i<=n/2)ans1+=a[i].p1;
		else ans1+=max(a[i].p2,a[i].p3);
	}
	sort(a+1,a+n+1,cmp2);
	for(int i=1;i<=n;i++){
		if(i<=n/2)ans2+=a[i].p2;
		else ans2+=max(a[i].p3,a[i].p1);
	}
	sort(a+1,a+n+1,cmp3);
	for(int i=1;i<=n;i++){
		if(i<=n/2)ans3+=a[i].p3;
		else ans3+=max(a[i].p2,a[i].p1);
	}
	cout<<max(ans1,max(ans2,ans3))<<endl;
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
