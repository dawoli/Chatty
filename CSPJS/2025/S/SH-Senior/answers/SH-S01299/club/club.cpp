#include <bits/stdc++.h>
using namespace std;
const int N = 100009;
int t,n,d[N][4];
int bf[N],tnt[N],ans,used[N];
int A[N];
struct yg {
	int x,sec,id;
	bool operator < (const yg&a) const {
		return x<a.x;
	}
};
yg B[N*3];
void init() {
	memset(bf,0,sizeof(bf));
	memset(tnt,0,sizeof(tnt));
	ans=0;
}
void BF(int k) {
	if(k==n+1) {
		int tmp=0;
		for(int i=1;i<=n;i++) {
			tnt[bf[i]]++;
			if(tnt[bf[i]]>n/2) {
//				cout<<"³¬³ö£º"<<bf[i]<<" "<<tnt[bf[i]]<<" "<<n<<endl;
				for(int j=1;j<=n;j++) {
					tnt[j]=0;
				}
				return ;
			}
			tmp+=d[i][bf[i]];
		}
		for(int i=1;i<=n;i++) {
			tnt[i]=0;
		}
		ans=max(ans,tmp);
		return ;
	}
	for(int i=1;i<=3;i++) {
		bf[k]=i;
		BF(k+1);
	}
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--) {
		init();
		cin>>n;
		bool flagA=1,flagB=1;
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=3;j++) {
				cin>>d[i][j];
			}
			if(d[i][2]!=0) {
				flagA=0;
			}if(d[i][3]!=0) {
				flagA=0;
				flagB=0;
			}
		}
		if(n<=10) {
			BF(1);
			cout<<ans<<endl;
		}
		else if(flagA) {
			for(int i=1;i<=n;i++) {
				A[i]=d[i][1];
			}
			sort(A+1,A+n+1);
			int LL=0;
			for(int i=n;LL<=n/2;i--) {
				ans+=A[i];
			}cout<<ans<<endl;
		}
		else {
			for(int i=1;i<=n;i++) {
				B[i].x=d[i][1];
				B[i+n].x=d[i][2];
				B[i+n*2].x=d[i][3];
				B[i].sec=1;
				B[i+n].sec=2;
				B[i+n*2].sec=3;
				B[i].id=i;
				B[i+n].id=i;
				B[i+n*2].id=i;
			}
			sort(B,B+3*n+1);
			int s[4]={0,0,0,0};
			memset(used,0,sizeof(used));
			for(int i=3*n;i>=1;i--) {
				if(used[B[i].id]) continue;
				if(s[B[i].sec]>n/2) {
					continue;
				}
				s[B[i].sec]++;
				ans+=B[i].x;
				used[B[i].id]=1;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
