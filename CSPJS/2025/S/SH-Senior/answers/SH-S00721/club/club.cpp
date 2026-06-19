#include<bits/stdc++.h>
using namespace std;
int n;
int a[100009][4];
int cnt[4];
int sum=0;
struct node{
	int fid,fval,sid,sval;
};
node b[100009];
node f[100009];
bool cmp(node x,node y){
	return x.fval-x.sval<y.fval-y.sval;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		sum=0;
		cin>>n;
		for(int i=1;i<=3;i++)
		cnt[i]=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
				cnt[1]++;
				b[i].fid=1;
				b[i].fval=a[i][1];
				if(a[i][2]>=a[i][3]){
					b[i].sid=2;
					b[i].sval=a[i][2];
				}
				else{
					b[i].sid=3;
					b[i].sval=a[i][3];
				}
				sum+=a[i][1];
			}
			else if(a[i][2]>=a[i][3]&&a[i][2]>=a[i][1]){
				cnt[2]++;
				sum+=a[i][2];
				b[i].fid=2;
				b[i].fval=a[i][2];
				if(a[i][1]>=a[i][3]){
					b[i].sid=1;
					b[i].sval=a[i][1];
				}
				else{
					b[i].sid=3;
					b[i].sval=a[i][3];
				}
			}
			else{
				b[i].fid=3;
				b[i].fval=a[i][3];
				if(a[i][1]>=a[i][2]){
					b[i].sid=1;
					b[i].sval=a[i][1];
				}
				else{
					b[i].sid=2;
					b[i].sval=a[i][2];
				}
				cnt[3]++;
				sum+=a[i][3];
			}
		}
		if(max(max(cnt[1],cnt[2]),cnt[3])<=n/2){
			cout<<sum<<endl;;
			continue;
		}
		int k;
		if(cnt[1]>n/2)
		k=1;
		else if(cnt[2]>n/2)
		k=2;
		else
		k=3;
		int m=0;
		for(int i=1;i<=n;i++){
			if(b[i].fid==k){
			f[++m].fid=b[i].fid;
			f[m].fval=b[i].fval;
			f[m].sid=b[i].sid;
			f[m].sval=b[i].sval;}
		}
		sort(f+1,f+1+m,cmp);
		for(int i=1;i<=m-n/2;i++){
		sum=sum-f[i].fval+f[i].sval; }
		cout<<sum<<endl;
	}
}
