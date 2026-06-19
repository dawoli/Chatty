#include<bits/stdc++.h>
using namespace std;
int t;
bool flag0=true,flag00=true;
const int MAXN=100009;
struct like{
	int a[4];
	int enter;
}x[MAXN];
long long enter1,enter2,enter3;
//bool cmp1(like a,like b){
//	if(a.a1!=b.a1)return a.a1>b.a1;
//	else if(a.a2!=b.a2)return a.a2>b.a2;
//	return a.a3>=b.a3;
//}
//bool cmp2(like a,like b){
//	if(a.a1!=b.a1)return a.a1>b.a1;
//	else if(a.a3!=b.a3)return a.a3>b.a3;
//	return a.a2>=b.a2;
//}
//bool cmp3(like a,like b){
//	if(a.a2!=b.a2)return a.a2>b.a2;
//	else if(a.a1!=b.a1)return a.a1>b.a1;
//	return a.a3>=b.a3;
//}
//bool cmp4(like a,like b){
//	if(a.a2!=b.a2)return a.a2>b.a2;
//	else if(a.a3!=b.a3)return a.a3>b.a3;
//	return a.a1>=b.a1;
//}
//bool cmp5(like a,like b){
//	if(a.a3!=b.a3)return a.a3>b.a3;
//	else if(a.a1!=b.a1)return a.a1>b.a1;
//	return a.a1>=b.a1;
//}
//bool cmp6(like a,like b){
//	if(a.a3!=b.a3)return a.a3>b.a3;
//	else if(a.a2!=b.a2)return a.a2>b.a2;
//	return a.a1>=b.a1;
//}
bool partcmp1(like a,like b){
	if(a.a[1]!=b.a[1])return a.a[1]>b.a[1];
	else if(a.a[2]!=b.a[2])return a.a[2]>b.a[2];
	return true;
}
bool partcmp2(like a,like b){
	if(a.a[2]!=b.a[2])return a.a[2]>b.a[2];
	else if(a.a[1]!=b.a[1])return a.a[1]>b.a[1];
	return true;
}
bool entercmp1(like a,like b){
	if(a.enter!=b.enter)return a.enter<b.enter;
	return (a.a[1]-a.a[2])<(b.a[1]-b.a[2]);
}
bool entercmp2(like a,like b){
	if(a.enter!=b.enter)return a.enter>b.enter;
	return (a.a[2]-a.a[1])<(b.a[2]-b.a[1]);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>t;
	for(int z=1;z<=t;z++){
		long long ans=0;
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>x[i].a[1]>>x[i].a[2]>>x[i].a[3];
			int tmp=max(max(x[i].a[1],x[i].a[2]),x[i].a[3]);
			if(tmp==x[i].a[1]){x[i].enter=1;enter1++;}
			else if(tmp==x[i].a[2]){x[i].enter=2;enter2++;}
			else if(tmp==x[i].a[3]){x[i].enter=3;enter3++;}
			if(x[i].a[2]!=0||x[i].a[3]!=0)flag00=false;
			if(x[i].a[3]!=0)flag0=false;
		}
		if(flag00){
			sort(x+1,x+n+1,partcmp1);
			for(int i=1;i<=n/2;i++)ans+=x[i].a[1];
			cout<<ans<<endl;
			continue;
		}
		else if(flag0){
			for(int i=1;i<=n;i++)ans+=x[i].a[x[i].enter];
			if(enter1>enter2){
				sort(x+1,x+n+1,entercmp1);
				for(int i=1;i<=(enter1-enter2)/2;i++)ans=ans-x[i].a[1]+x[i].a[2];
			}
			else if(enter2>enter1){
				sort(x+1,x+n+1,entercmp2);
				for(int i=1;i<=(enter2-enter1)/2;i++)ans=ans-x[i].a[2]+x[i].a[1];
			}
			cout<<ans<<endl;
			continue;
		}
	}
	return 0;
} 
