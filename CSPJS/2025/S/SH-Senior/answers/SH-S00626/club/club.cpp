#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n;
struct node{
	int x,y,z;
}a[N];
bool cmp(node a,node b){
	if(a.x!=b.x) return a.x>b.x;
	if(a.y!=b.y) return a.y>b.y;
}
int flag2,flag3,cnt;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].y!=0) flag2=1;
			if(a[i].z!=0) flag3=1;
		}
		if(flag2==0&&flag3==0){
			sort(a+1,a+1+n,cmp);
			for(int i=1;i<=n/2;i++){
				cnt+=a[i].x;
			}
			cout<<cnt<<"\n";
			break;
		}
		if(flag3==0){
			sort(a+1,a+1+n,cmp);
			for(int i=1;i<=n;i++){
				cnt+=a[i].x;
				cnt+=a[n-i+1].y;
			}
			cout<<cnt<<"\n";
			break;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					cnt+=max(a[i].x,max(a[i].y,a[i].z));
				}
			}
		}
		cout<<cnt<<"\n";
	}
	return 0;
}
