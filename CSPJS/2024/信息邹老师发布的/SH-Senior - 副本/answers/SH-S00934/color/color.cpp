#include<bits/stdc++.h>
using namespace std;
int a[200005];
int c[200005];
int b[15];
int qr,qb;
int cnt1;
int cnt2;
int n,t;
long long ans;
int le[200005];
int re[200005];
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(le,0,sizeof(le));
		memset(re,0,sizeof(re));
		for(int i=1;i<=n;i++){
			cin>>a[i];
			b[a[i]]++;
		}
		ans=0;
		cnt1=0;
		cnt2=0;
		qr=0;
		qb=0;
		for(int i=1;i<=n;i++){
			if(qr==0){
				cnt1++;
				le[cnt1]=a[i];
				b[a[i]]--;
				qr=a[i];
			}else if(qb==0){
				cnt2++;
				re[cnt2]=a[i];
				b[a[i]]--;
				qb=a[i];
			}else {
				if(a[i]==qr){
					cnt1++;
					le[cnt1]=a[i];
					b[a[i]]--;
					qr=a[i];
					ans+=a[i];
				}else if(a[i]==qb){
					cnt2++;
					re[cnt2]=a[i];
					b[a[i]]--;
					qb=a[i];
					ans+=a[i];
				}if(b[qr]==0){
					cnt1++;
					le[cnt1]=a[i];
					b[a[i]]--;
					qr=a[i];
				}else if(b[qb]==0){
					cnt2++;
					re[cnt2]=a[i];
					b[a[i]]--;
					qb=a[i];
				}else if(qr>qb){
					cnt2++;
					re[cnt2]=a[i];
					b[a[i]]--;
					qb=a[i];
				}else{
					cnt1++;
					le[cnt1]=a[i];
					b[a[i]]--;
					qr=a[i];	
				}
			}
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}
