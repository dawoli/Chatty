#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e5;
int t,n,a[N][3],per[3][N],cnt1[3],ans,cnt2;
struct chg{
	int diff,i;
}c[N<<1];
bool cmp(chg a,chg b){
	return a.diff>b.diff;
}
bool flag[N];
int main(){
	ios::sync_with_stdio(false),cin.tie(nullptr);
	freopen("club.in","r",stdin),freopen("club.out","w",stdout);
	cin>>t;
	for(int ti=0;ti<t;ti++){
		cin>>n;
		for(int j=0;j<3;j++)cnt1[j]=0;
		ans=0;
		for(int i=0;i<n;i++){
			int k=-1;
			for(int j=0;j<3;j++){
				cin>>a[i][j];
				if(k==-1||a[i][j]>a[i][k])k=j;
			}
			per[k][cnt1[k]++]=i,ans+=a[i][k],flag[i]=false;
		}
		cnt2=0;
		for(int j=0;j<3;j++)
			if(cnt1[j]>n>>1){
				for(int k=0;k<cnt1[j];k++)
					for(int l=0;l<3;l++)
						if(l!=j)c[cnt2++]={a[per[j][k]][l]-a[per[j][k]][j],per[j][k]};
				sort(c,c+cnt2,cmp);
				for(int k=0;cnt1[j]>n>>1;k++)
					if(!flag[c[k].i])
						ans+=c[k].diff,cnt1[j]--,flag[c[k].i]=true;
			}
		cout<<ans<<"\n";
	}
	return 0;
}
