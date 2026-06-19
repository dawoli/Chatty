#include<bits/stdc++.h>
using namespace std;
int n,r[100005],nus[100001],k,cnt,zxz=100005,zdz=-1;
bool de[100005];
int atk;
int main() {
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	k=n;
	cnt=n;
	for(int i=1;i<=n;i++) {
		cin>>r[i];
		nus[r[i]]++;
		zxz=min(zxz,r[i]);
		zdz=max(zdz,r[i]);
	}
	if(zdz==2&&zxz==1) {
		cout<<max(nus[1]-nus[2],0)+nus[2];
		return 0;
	}
	sort(r+1,r+1+n);
//	for(int i=1;i<=n;i++) {
//		cout<<r[i]<<' ';
//	}
	for(int i=zxz;i<=zdz;i++) {
		if(nus[i]>1) {
			break;
		}
		if(i==zdz){
			cout<<1;
			return 0;
		}
	}	
	for(int i=zxz;i<zdz;i++) {
		if(nus[i]==0) {
			continue;
		}
		for(int j=i+1;j<=zdz;j++) {
			if(nus[j]==0) {
				continue;
			}
			atk=min(nus[i],nus[j]);
			nus[i]-=atk;
			k-=atk;
			cnt-=atk;
			if(nus[i]==0) {
				break;
			}
		}
	}
//	for(int i=1;i<=n;i++) {
//		if(de[i]==0) {
//			cnt++;
//		}
//	}
	cout<<cnt;
	return 0;
}
