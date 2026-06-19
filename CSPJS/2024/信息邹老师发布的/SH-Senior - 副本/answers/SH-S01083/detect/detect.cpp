#include<bits/stdc++.h>
using namespace std;
long long n,m,l,v1,d[100005],v[100005],a[100005],q[100005],t,ans;
bool check(double a,double b){
	for(int i=0;i<n;i++) if(q[i]<a and q[i]>=b) return true;
	return false;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
    for(int j=0;j<t;j++){
	    cin>>n>>m>>l>>v1;
        for(int i=0;i<n;i++) cin>>d[i]>>v[i]>>a[i];
        for(int i=0;i<m;i++) cin>>q[i];
        for(int i=0;i<n;i++){
        	double be,en;
        	if(a[i]<=0 and v[i]<=v1) continue;
        	if(a[i]>=0 and v[i]>v1) ans++;
        	else{
        		en=abs(v1*v1-v[i]*v[i])/abs(2*a[i]);
        	    be=d[i];
        	    if(check(be,en)) ans++;
			}
		}
        cout<<ans<<" "<<m-1;
    }
	return 0;
}
