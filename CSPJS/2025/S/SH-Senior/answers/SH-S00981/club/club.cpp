#include<iostream>
#include<algorithm>
using namespace std;
int t;
struct node{
	int a1,a2,a3;
};
bool cmp(node x,node y){
	int count1=max(x.a1,max(x.a2,x.a3))-x.a1-x.a2-x.a3+max(x.a1,max(x.a2,x.a3))+min(x.a1,min(x.a2,x.a3));
	int count2=max(y.a1,max(y.a2,y.a3))-y.a1-y.a2-y.a3+max(y.a1,max(y.a2,y.a3))+min(y.a1,min(y.a2,y.a3));
	return count1>count2;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int n,cnt1=0,cnt2=0,cnt3=0;
		cin>>n;
		node a[100005];
		for(int i=1;i<=n;i++)
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
		sort(a+1,a+n+1,cmp);
		long long ans=0;
		for(int i=1;i<=n;i++){
			if(a[i].a1>=max(a[i].a2,a[i].a3)){
				if(cnt1<n/2){
					ans+=a[i].a1;
					cnt1++;
				}
				else if(a[i].a2>a[i].a3){
					ans+=a[i].a2;
					cnt2++;
				}
				else{
					ans+=a[i].a3;
					cnt3++;
				}
			}
			else if(a[i].a2>=max(a[i].a1,a[i].a3)){
				if(cnt2<n/2){
					ans+=a[i].a2;
					cnt2++;
				}
				else if(a[i].a1>a[i].a3){
					ans+=a[i].a1;
					cnt1++;
				}
				else{
					ans+=a[i].a3;
					cnt3++;
				}
			}
			else if(a[i].a3>=max(a[i].a1,a[i].a2)){
				if(cnt3<n/2){
					ans+=a[i].a3;
					cnt3++;
				}
				else if(a[i].a1>a[i].a2){
					ans+=a[i].a1;
					cnt1++;
				}
				else{
					ans+=a[i].a2;
					cnt2++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
