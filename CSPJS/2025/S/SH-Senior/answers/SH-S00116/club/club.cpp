#include<bits/stdc++.h>
using namespace std;
const int N=100009;
struct stu{
	int a1,a2,a3;
	int mx;
	bool operator<(const stu&c)const{
		if(mx<c.mx) return 1;
		else return 0;
	}
};
bool cmp(stu x,stu y){
	return y<x;
}
stu r[N];
int num[5];
bool ok[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.in","w",stdout);
	int t;
	cin>>t;
	for(int p=1;p<=t;p++){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>r[i].a1>>r[i].a2>>r[i].a3;
			r[i].mx=max(r[i].a1,max(r[i].a2,r[i].a3));
		}
		sort(r+1,r+1+n,cmp);
		int ans=0;
		for(int i=1;i<=n;i++){
			if(r[i].mx==r[i].a1&&num[1]<=n/2-1){
				ans+=r[i].a1;
				num[1]++;
				ok[i]=true;
			}else if(r[i].mx==r[i].a2&&num[2]<=n/2-1){
				ans+=r[i].a2;
				num[2]++;
				ok[i]=true;
			}else if(r[i].mx==r[i].a3&&num[3]<=n/2-1){
				ans+=r[i].a3;
				num[3]++;
				ok[i]=true;
			}
			if(ok[i]==0){
				if(r[i].mx==r[i].a1) ans+=max(r[i].a2,r[i].a3);
				if(r[i].mx==r[i].a2) ans+=max(r[i].a1,r[i].a3);
				if(r[i].mx==r[i].a3) ans+=max(r[i].a1,r[i].a2);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
