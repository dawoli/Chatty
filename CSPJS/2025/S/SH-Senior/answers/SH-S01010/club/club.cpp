#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100009;
int n,t,cnt,ans,f[N][4];
struct stu{
	int x,y,z;
}a[N];
bool cmp(const stu&a,const stu&b){
	return a.x>b.x;
} 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int x=1;x<=t;x++){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].z==0&&a[i].z==0) cnt++;
		}
		if(n==2){
			cout<<max(max(max(a[1].x+a[2].y,a[1].x+a[2].z),max(a[1].y+a[2].x,a[1].y+a[2].z)),max(a[1].z+a[2].x,a[1].z+a[2].x))<<endl;
			continue;
		}
		if(cnt==n){
			sort(a+1,a+1+n,cmp);
			for(int i=1;i<=n/2;i++) ans+=a[i].x;
			cout<<ans<<endl;
			continue;
		}
		f[1][1]=a[1].x,f[1][2]=a[1].y,f[1][3]=a[1].z;
		for(int i=2;i<=n;i++){
			f[i][1]=max(f[i-1][1],max(f[i-1][2],f[i-1][3]))+a[i].x;	
			f[i][2]=max(f[i-1][1],max(f[i-1][2],f[i-1][3]))+a[i].y;
			f[i][3]=max(f[i-1][1],max(f[i-1][2],f[i-1][3]))+a[i].z;
		}
		cout<<max(max(f[n][1],f[n][2]),f[n][3])<<endl;
	}
	return 0;
}
