#include<bits/stdc++.h>
using namespace std;
int t,n,m,ans1[25],ans2[25];
int l,upv,v[100005],a[100005],d[100005],p[100005];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n>>m>>l>>upv;
		for(int j=0;j<n;j++) cin>>d[j]>>v[j]>>a[j];
		for(int j=0;j<m;j++) cin>>p[j];
		int pm=p[m-1];
		for(int j=0;j<n;j++){
			if((2*a[j]*pm+v[j]*v[j])>(upv*upv)&&d[j]<=pm) ans1[i]++;
		}
		printf("%d ",ans1[i]);
		ans2[i]=m-1;
		if(ans1[i]==0) ans2[i]++;
		printf("%d\n",ans2[i]);
	}
	return 0;
}
