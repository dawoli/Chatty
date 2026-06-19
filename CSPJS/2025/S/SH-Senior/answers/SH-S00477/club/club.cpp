#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define min(a,b) (a>b?b:a)
#define max(a,b) (a>b?a:b)
#define fr1(i,a,b,k) for(int i=a;i<=b;i+=k)
#define fr2(i,a,b,k) for(int i=a;i>=b;i-=k)
using namespace std;
int t,n,x,y,z,ans,a[100005],b[100005],c[100005],ca,cb,cc;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		x=0,y=0,z=0;
		fr1(i,1,n,1){
			cin>>a[i]>>b[i]>>c[i];
			if(a[i])x=1;
			if(b[i])y=1;
			if(c[i])z=1;
		}
		if(y==0 and z==0){
			sort(a+1,a+n+1);
			ans=0;
			fr2(i,n,n/2+1,1){
				ans+=a[i];
			}
			cout<<ans<<endl;
			continue;
		}
		if(x==0 and z==0){
			sort(b+1,b+n+1);
			ans=0;
			fr2(i,n,n/2+1,1){
				ans+=b[i];
			}
			cout<<ans<<endl;
			continue;
		}
		if(y==0 and x==0){
			sort(c+1,c+n+1);
			ans=0;
			fr2(i,n,n/2+1,1){
				ans+=c[i];
			}
			cout<<ans<<endl;
			continue;
		}
		ans=0;
		ca=cb=cc=0;
		fr1(i,1,n,1){
			int mx=max(a[i],max(b[i],c[i]));
			if(mx==a[i] and ca<n/2){
				++ca,ans+=mx;
			}else if(mx==b[i] and cb<n/2){
				++cb,ans+=mx;
			}else if(mx==c[i] and cc<n/2){
				++cc,ans+=mx;
			}else if(mx==a[i]){
				mx=max(b[i],c[i]);
				if(mx==b[i]){
					if(cb<n/2)++cb,ans+=mx;
					else ++cc,ans+=c[i];
				}else{
					if(cc<n/2)++cc,ans+=mx;
					else ++cb,ans+=b[i];
				}
			}else if(mx==b[i]){
				mx=max(a[i],c[i]);
				if(mx==a[i]){
					if(ca<n/2)++ca,ans+=mx;
					else ++cc,ans+=c[i];
				}else{
					if(cc<n/2)++cc,ans+=mx;
					else ++ca,ans+=a[i];
				}
			}else if(mx==c[i]){
				mx=max(b[i],a[i]);
				if(mx==a[i]){
					if(ca<n/2)++ca,ans+=mx;
					else ++cb,ans+=b[i];
				}else{
					if(cb<n/2)++cb,ans+=mx;
					else ++ca,ans+=a[i];
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
