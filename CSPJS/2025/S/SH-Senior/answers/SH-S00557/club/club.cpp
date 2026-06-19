#include<bits/stdc++.h>
using namespace std;
const int N=100009;
long long a[N],b[N],c[N];
int n;
long long ans=0;
bool bol=1;
void solvebf(int j,long long ans1,int ai,int bi,int ci){
	if(ai>n/2||bi>n/2||ci>n/2) return;
	if(j==n){
		ans=max(ans,ans1);
		return;
	}
	solvebf(j+1,ans1+a[j],ai+1,bi,ci);
	solvebf(j+1,ans1+b[j],ai,bi+1,ci);
	if(bol) solvebf(j+1,ans1+c[j],ai,bi,ci+1);
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		long long q=0,w=0,e=0;
		for(int k=0;k<n;k++){
			cin>>a[k]>>b[k]>>c[k];
			q=max(q,a[k]);
			w=max(w,b[k]);
			e=max(e,c[k]);
		}
		if(w==0&&e==0){
			sort(a,a+n);
			for(int k=n-1;k>=n/2;k--)
				ans+=a[k];
			cout<<ans<<endl;
			continue;
		}
		else if(e==0){
			bol=0;
		}
		solvebf(0,0,0,0,0);
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}
