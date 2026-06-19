#include<bits/stdc++.h>
using namespace std;
const int N=100005;
struct num{
	long long low,num;
}stu[N];
bool cmp(num x,num y){
	return x.low<y.low;
}
void solve(){
	int n;
	int one=0,two=0,three=0;
	cin>>n;
	long long ans=0;
	for(int i=1;i<=n;i++){
		int a[3];
		cin>>a[0]>>a[1]>>a[2];
		int max=0,next=0;
		if(a[0]>=a[1]){
			if(a[0]<=a[2]) max=a[2],next=a[0],three++,stu[i].num=3;
			else if(a[2]>=a[1])one++,max=a[0],next=a[2],stu[i].num=1;
			else one++,max=a[0],next=a[1],stu[i].num=1;
		}
		else{
			if(a[1]<=a[2])three++,max=a[2],next=a[1],stu[i].num=3;
			else if(a[0]>=a[2])two++,max=a[1],next=a[0],stu[i].num=2;	
			else two++,max=a[1],next=a[2],stu[i].num=2;
		}
		stu[i].low=max-next;//jianqu	
		ans+=max;
	}
	sort(stu+1,stu+n+1,cmp);
	int aa=0,los=0;
	if(three>n/2) aa=3,los=three-n/2;
	else if(two>n/2) aa=2,los=two-n/2;
	else if(one>n/2) aa=1,los=one-n/2;
	for(int i=1;i<=n;i++){
		if(los==0)break;
		if(stu[i].num!=aa)continue;
		ans-=stu[i].low;
		los--;
	}
	cout<<ans<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
	//	clear();
		solve();
	}	
	return 0;
}
