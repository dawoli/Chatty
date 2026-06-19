#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e5+5;
int t,n,a[N][3],b[N][3],c[N][3],d[N],e[N],rr[3];
vector<int> r[3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int A=1;A<=t;A++) {
		cin>>n; long long sum=0,rrr=0;
		for(int i=0;i<3;i++) r[i].clear();
		for(int i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			b[i][0]=max(a[i][0],max(a[i][1],a[i][2]));
			b[i][2]=min(a[i][0],min(a[i][1],a[i][2]));
			b[i][1]=a[i][0]+a[i][1]+a[i][2]-b[i][0]-b[i][2];
			if(b[i][0]==a[i][0]) c[i][0]=0;
			if(b[i][0]==a[i][1]) c[i][0]=1;
			if(b[i][0]==a[i][2]) c[i][0]=2;
			if(b[i][2]==a[i][0]&&c[i][0]!=0) c[i][2]=0;
			if(b[i][2]==a[i][1]&&c[i][0]!=1) c[i][2]=1;
			if(b[i][2]==a[i][2]&&c[i][0]!=2) c[i][2]=2;
			c[i][1]=3-c[i][0]-c[i][2];
			r[c[i][0]].push_back(i); sum+=b[i][0]; 
			d[i]=b[i][0]-b[i][1];
		}
		int cnt=0;
		rr[0]=r[0].size();
		rr[1]=r[1].size();
		rr[2]=r[2].size();
		if(rr[0]>=rr[1]&&rr[0]>=rr[2]) rrr=0;
		if(rr[1]>=rr[0]&&rr[1]>=rr[2]) rrr=1;
		if(rr[2]>=rr[0]&&rr[2]>=rr[1]) rrr=2;
		for(int i=0;i<rr[rrr];i++) e[++cnt]=d[r[rrr][i]];
		sort(e+1,e+cnt+1);
		for(int i=n/2+1,j=1;i<=rr[rrr];i++,j++)
			sum-=e[j];
		cout<<sum<<endl;
	}
	return 0; 
} 
