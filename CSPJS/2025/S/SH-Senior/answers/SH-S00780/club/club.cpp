#include<bits/stdc++.h>
using namespace std;

#define int long long

const int Maxn=1e5;
int t,n,cnt[10],ans;
int a1[Maxn+5],a2[Maxn+5],a3[Maxn+5],p1,p2,p3;

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		p1=p2=p3=ans=0;
		cnt[1]=cnt[2]=cnt[3]=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			int a[10],b[10];
			cin>>a[1]>>a[2]>>a[3];
			b[1]=a[1],b[2]=a[2],b[3]=a[3];
			sort(b+1,b+4);
			int t1;
			for(int i=1;i<=3;i++){
				if(a[i]==b[3]){
					cnt[i]++,t1=i;
					break;
				}
			}
			ans+=b[3];
			int t=b[3]-b[2];
			if(t1==1) a1[++p1]=t;
			else if(t1==2) a2[++p2]=t;
			else if(t1==3) a3[++p3]=t;
		}
		for(int i=1;i<=3;i++){
			if(cnt[i]>n/2){
				if(i==1){
					sort(a1+1,a1+p1+1);
					for(int j=1;j<=cnt[i]-n/2;j++) ans-=a1[j];
				}
				else if(i==2){
					sort(a2+1,a2+p2+1);
					for(int j=1;j<=cnt[i]-n/2;j++) ans-=a2[j];
				}
				else if(i==3){
					sort(a3+1,a3+p3+1);
					for(int j=1;j<=cnt[i]-n/2;j++){
						ans-=a3[j];
					}
				}
				break;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
