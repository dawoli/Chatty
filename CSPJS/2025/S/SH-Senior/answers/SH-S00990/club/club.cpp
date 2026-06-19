#include<bits/stdc++.h>
using namespace std;
int n;
int a[4][100009];
int a1,a2,a3;
struct node{
	int id,club,happy;
};
node p[300009];
node d;
bool vst[100009];
bool cmp(node a,node b){
	return a.happy>b.happy;
}
int countt[4];
void solve(){
	cin>>n;
	int akk=0;
	for(int i=1;i<=n;i++){
		cin>>a[1][i]>>a[2][i]>>a[3][i];
		vst[i]=0;
	}
	for(int i=1;i<=3;i++){
		for(int j=1;j<=n;j++){
			d.id=j;
			d.club=i;
			if(i==1){
				d.happy=a[1][j]-max(a[2][j],a[3][j]);
			}
			else if(i==2){
				d.happy=a[2][j]-max(a[1][j],a[3][j]);
			}
			else{
				d.happy=a[3][j]-max(a[1][j],a[2][j]);
			}
			p[++akk]=d;
		}
	}
	int cnt=0;
	sort(p+1,p+1+3*n,cmp);
	countt[1]=0;
	countt[2]=0;
	countt[3]=0;
	int ans=0;
	for(int i=1;i<=(3*n);i++){
		if(ans==n){
			break;
		}
		d=p[i];
		if((!vst[d.id])&&countt[d.club]<(n/2)){
			cnt+=a[d.club][d.id];
			vst[d.id]=1;
			countt[d.club]++;
			ans++;
		}
	}
	cout<<cnt<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
