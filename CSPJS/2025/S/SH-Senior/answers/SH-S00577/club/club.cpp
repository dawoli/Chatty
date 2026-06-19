#include<bits/stdc++.h>
using namespace std;
const int N=100009;
int ans,t,n,a[N][3];
int bm1[N],bm2[N],bm3[N];
int ch1[N],ch2[N],ch3[N];
bool cmp1(const int a,const int b){
	return ch1[a]<ch1[b];
}
bool cmp2(const int a,const int b){
	return ch2[a]<ch2[b];
}
bool cmp3(const int a,const int b){
	return ch3[a]<ch3[b];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		ans=0;
		int rs1=0,rs2=0,rs3=0;
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a[j][0]>>a[j][1]>>a[j][2];
			if(a[j][0]>=a[j][1]&&a[j][0]>=a[j][2]){
				bm1[rs1++]=j;
				ch1[j]=a[j][0]-max(a[j][1],a[j][2]);
				ans+=a[j][0];
			}
			else if(a[j][1]>=a[j][0]&&a[j][1]>=a[j][2]){
				bm2[rs2++]=j;
				ch2[j]=a[j][1]-max(a[j][0],a[j][2]);
				ans+=a[j][1];
			}
			else{
				bm3[rs3++]=j;
				ch3[j]=a[j][2]-max(a[j][0],a[j][1]);
				ans+=a[j][2];
			}
		}
		if(rs1>(n/2)){
			sort(bm1,bm1+rs1,cmp1);
			for(int j=0;j<(rs1-n/2);j++)
				ans-=ch1[bm1[j]];
		}
		else if(rs2>(n/2)){
			sort(bm2,bm2+rs2,cmp2);
			for(int j=0;j<(rs2-n/2);j++)
				ans-=ch2[bm2[j]];
		}
		else if(rs3>(n/2)){
			sort(bm3,bm3+rs3,cmp3);
			for(int j=0;j<(rs3-n/2);j++)
				ans-=ch3[bm3[j]];
		}
		cout<<ans<<endl;
	}
	return 0;
} 
