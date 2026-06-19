#include<bits/stdc++.h>
using namespace std;
#define N 100005
int T;
int n;
int a[N][5];
int av[N];
void solve(){
	cin>>n;
	int cntf=0,cnts=0,cntt=0;
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		if(a[i][1]==max(a[i][1],max(a[i][2],a[i][3]))){
			av[i]=1;
			cntf++;
		}else if(a[i][2]==max(a[i][2],max(a[i][1],a[i][3]))){
			av[i]=2;
			cnts++;
		}else if(a[i][3]==max(a[i][3],max(a[i][1],a[i][2]))){
			av[i]=3;
			cntt++;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		ans+=a[i][av[i]];
	}
	while(cntf>n/2){
		int mn=20005,mc;
		for(int i=1;i<=n;i++){
			if(av[i]==1&&(a[i][1]-max(a[i][2],a[i][3]))<mn){
				mn=a[i][1]-max(a[i][2],a[i][3]);
				mc=i;
			}
		}
		ans=ans-a[mc][1]+max(a[mc][2],a[mc][3]);
		if(a[mc][2]>a[mc][3]) av[mc]=2;
		else av[mc]=3;
		cntf--;
	}
	while(cnts>n/2){
		int mn=20005,mc;
		for(int i=1;i<=n;i++){
			if(av[i]==2&&(a[i][2]-max(a[i][1],a[i][3]))<mn){
				mn=a[i][2]-max(a[i][1],a[i][3]);
				mc=i;
			}
		}
		ans=ans-a[mc][2]+max(a[mc][1],a[mc][3]);
		if(a[mc][1]>a[mc][3]) av[mc]=1;
		else av[mc]=3;
		cnts--;
	}
	while(cntt>n/2){
		int mn=20005,mc;
		for(int i=1;i<=n;i++){
			if(av[i]==3&&(a[i][3]-max(a[i][2],a[i][1]))<mn){
				mn=a[i][3]-max(a[i][2],a[i][1]);
				mc=i;
			}
		}
		ans=ans-a[mc][3]+max(a[mc][2],a[mc][1]);
		if(a[mc][1]>a[mc][2]) av[mc]=1;
		else av[mc]=2;
		cntt--;
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}

