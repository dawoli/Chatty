#include <bits/stdc++.h>
using namespace std;
int n;
long long a[3][100005],b[100005];
int d[3][100005],cnt_d[3];
int max_i;
int p=-1;
long long ans=0;
bool cmp(int i,int j){
	return b[i]<b[j];
}
int T=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>T;
	while(T--){
	cnt_d[0]=0; cnt_d[1]=0; cnt_d[2]=0;
	ans=0;
	p=-1;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[0][i]>>a[1][i]>>a[2][i];
		max_i=0; b[i]=a[max_i][i]-max(a[1][i],a[2][i]);
		if(a[1][i]>a[max_i][i]){
			max_i=1;
			b[i]=a[max_i][i]-max(a[0][i],a[2][i]);
		}
		if(a[2][i]>a[max_i][i]){
			max_i=2;
			b[i]=a[max_i][i]-max(a[1][i],a[0][i]);
		}
		d[max_i][cnt_d[max_i]++]=i;
		ans+=a[max_i][i];
//		cout<<i<<"->"<<max_i<<", b="<<b[i]<<"\n";
	}
	for(int i=0;i<3;i++){
//		for(int j=0;j<cnt_d[i];j++) cout<<d[i][j]<<" ";
//		cout<<"\n";
		if(cnt_d[i]>n/2) p=i;
	}
	if(p==-1){
		cout<<ans<<endl;
		continue;
	}
	sort(d[p],d[p]+cnt_d[p],cmp);
	for(int i=0;i<cnt_d[p]-n/2;i++){
		ans-=b[d[p][i]];
	}
	cout<<ans<<endl;
	}
	return 0;
} 
