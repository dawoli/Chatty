#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int tt=0;tt<t;tt++){
		int n;
		cin>>n;
		int p[n][2],cst[n],cnt[3]={0,0,0},sum=0;
		for(int i=0;i<n;i++){
			int a[3];
			cin>>a[0]>>a[1]>>a[2];
			int f[3];
			f[0]=max(a[1],max(a[0],a[2]));
			f[2]=min(a[0],min(a[1],a[2]));
			f[1]=a[0]+a[1]+a[2]-f[0]-f[2];
			//for(int j=0;j<3;j++) a[i][j]-=d;
			sum+=f[0];
			p[i][0]=(f[0]==a[0] ? 0 :(f[0]==a[1] ? 1 :2));
			p[i][1]=(f[1]==a[0] ? 0 :(f[1]==a[1] ? 1 :2));
			cnt[p[i][0]]++;
			cst[i]=f[0]-f[1];
		} 
		//for(int i=0;i<n;i++) cout<<p[i][0]<<" "<<p[i][1]<<endl;
		if(cnt[0]>n/2 || cnt[1]>n/2 || cnt[2]>n/2){
			int err=(cnt[0]>n/2 ? 0 : (cnt[1]>n/2 ? 1 : 2));
			int more=cnt[err]-n/2;
			int head=0;
			int grp[cnt[err]];
			for(int i=0;i<n;i++){
				if(p[i][0]==err){
					grp[head]=cst[i];
					head++;
				}
			}
			sort(grp,grp+cnt[err]);
			for(int i=0;i<more;i++) sum-=grp[i];
		}
		cout<<sum<<endl;	
	}
	return 0;
} 
