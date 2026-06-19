#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[100005][4];
int b[100005];//1and2
int c[100005];//1and3

int c12[100005];
int c13[100005];
int c21[100005];
int c23[100005];
int c31[100005];
int c32[100005];

int z[100005];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		memset(c12,-1,sizeof(c12));
		memset(c13,-1,sizeof(c13));
		memset(c21,-1,sizeof(c21));
		memset(c23,-1,sizeof(c23));
		memset(c32,-1,sizeof(c32));
		memset(c31,-1,sizeof(c31));
		memset(z,0,sizeof(z));
		int n;
		cin>>n;
		int f=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][2]!=0||a[i][3]!=0){
				f=1;
			}
		}
		if(f==0){
			for(int i=1;i<=n;i++){
				b[i]=a[i][1];
			}
			sort(b+1,b+n+1);
			int cnt=0;
			for(int i=n;i>=n/2+1;i--){
				cnt+=b[i];
			}
			cout<<cnt<<'\n';
		}
		else{
			int cnt=0;
			int i1=0;
			int i2=0;
			int i3=0;
			for(int i=1;i<=n;i++){
				if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
					i1++;
					cnt+=a[i][1];
					c12[i]=a[i][1]-a[i][2];
					c13[i]=a[i][1]-a[i][3];
				}
				else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
					i2++;
					cnt+=a[i][2];
					c21[i]=a[i][2]-a[i][1];
					c23[i]=a[i][2]-a[i][3];
				}
				else if(a[i][3]>=a[i][1]&&a[i][3]>=a[i][2]){
					i3++;
					cnt+=a[i][3];
					c31[i]=a[i][3]-a[i][1];
					c32[i]=a[i][3]-a[i][2];
				}
			}
//			for(int i=1;i<=n;i++){
//				cout<<c12[i]<<" "<<c13[i]<<" "<<c21[i]<<" "<<c23[i]<<" "<<c31[i]<<" "<<c32[i]<<'\n';
//			}
//			cout<<i1<<" "<<i2<<" "<<i3<<'\n';
			int zi=0;
			if(i1>n/2){
				for(int i=1;i<=n;i++){
					if(c12[i]!=-1&&c13[i]!=-1){
						z[zi++]=min(c12[i],c13[i]);
					}
				}
				sort(z,z+zi);
				for(int i=0;i<i1-n/2;i++){
					cnt-=z[i];
				}
			}
			else if(i2>n/2){
				for(int i=1;i<=n;i++){
					if(c23[i]!=-1&&c21[i]!=-1){
						z[zi++]=min(c23[i],c21[i]);
					}
				}
				sort(z,z+zi);
				for(int i=0;i<i2-n/2;i++){
					cnt-=z[i];
				}
			}
			else if(i3>n/2){
				for(int i=1;i<=n;i++){
					if(c32[i]!=-1&&c31[i]!=-1){
						z[zi++]=min(c32[i],c31[i]);
					}
				}
//				for(int i=0;i<zi;i++){
//					cout<<z[i]<<" ";
//				}
//				cout<<endl;
				sort(z,z+zi);
				for(int i=0;i<i3-n/2;i++){
					cnt-=z[i];
				}
			}
			cout<<cnt<<'\n';
		}
	}
	return 0;
}
//我要S组一等奖!!!!!!!!! 
