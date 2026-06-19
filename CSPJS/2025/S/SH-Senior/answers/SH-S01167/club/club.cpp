#include<bits/stdc++.h>
using namespace std;
int t,n;
long long ans,x,y,z,cnt1,cnt2,l[1000010];
int a[100010],b[100010],c[100010];
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--) {
		cin>>n;
		ans=0,cnt1=0,cnt2=0;
		if(n==2) {
			int a1,a2,a3,b1,b2,b3;
			cin>>a1>>a2>>a3>>b1>>b2>>b3;
			int xx=max(a1+b2,a1+b3),yy=max(a2+b1,a2+b3),zz=max(a3+b1,a3+b2);
			cout<<max(xx,max(yy,zz))<<endl;
			continue;
		}
		else if(n==4) {
			int a1,a2,a3,b1,b2,b3,c1,c2,c3,d1,d2,d3;
			long long l[50],ans=0;
			cin>>a1>>a2>>a3>>b1>>b2>>b3>>c1>>c2>>c3>>d1>>d2>>d3;
			l[1]=a1+d1+b2+c3;
			l[2]=a1+c1+b2+d3;
			l[3]=a1+b1+c2+d3;
			l[4]=a1+d1+c2+b3;
			l[5]=a1+c1+d2+b3;
			l[6]=a1+b1+d2+c3;
			l[7]=b1+c1+a2+d3;
			l[8]=b1+c1+d2+a3;
			l[9]=b1+d1+a2+c3;
			l[10]=b1+d1+c2+a3;
			l[11]=c1+d1+a2+b3;
			l[12]=c1+d1+b2+a3;
			l[13]=a1+b2+d2+c3;
			l[14]=c1+b2+d2+a3;
			l[15]=a1+b2+c2+d3;
			l[16]=d1+b2+c2+a3;
			l[17]=c1+b2+a2+d3;
			l[18]=d1+b2+a2+c3;
			l[19]=b1+a2+c2+d3;
			l[20]=d1+a2+c2+b3;
			l[21]=b1+a2+d2+c3;
			l[22]=c1+a2+d2+b3;
			l[23]=a1+c2+d2+b3;
			l[24]=b1+c2+d2+a3;
			l[25]=c1+d2+a3+b3;
			l[26]=d1+c2+a3+b3;
			l[27]=b1+d2+a3+c3;
			l[28]=d1+b2+a3+c3;
			l[29]=b1+c2+a3+d3;
			l[30]=c1+b2+a3+d3;
			l[31]=a1+d2+b3+c3;
			l[32]=d1+a2+b3+c3;
			l[33]=a1+c2+b3+d3;
			l[34]=c1+a2+b3+d3;
			l[35]=a1+b2+c3+d3;
			l[36]=b1+a2+c3+d3;
			for(int i=1;i<=36;++i) {
				ans=max(ans,l[i]);
			}
			cout<<ans<<endl;
			continue;
		}
		else if(n<10) {
			int l=
		}
		for(int i=1;i<=n;++i) {
			cin>>a[i]>>b[i]>>c[i];
			x+=a[i],y+=b[i];
		}
		if(b[1]==c[1]&&c[1]==0) {
			sort(a+1,a+n+1);
			for(int i=n;i>n/2;i--) ans+=a[i];
		}
		else if(c[1]==0) {
			for(int i=1;i<=n;++i) {
				double xx=1.0*a[i]/x,yy=1.0*b[i]/y;
				if(xx>yy) {
					if(cnt1<n/2) {
						cnt1++;
						ans+=a[i];
					}else {
						cnt2++;
						ans+=b[i];
					}
				}
				else if(yy>xx) {
					if(cnt2<n/2){
						cnt2++;
						ans+=b[i];
					}
					else {
						cnt1++;
						ans+=a[i];
					}
				}
			}
		}
		else {
			for(int i=1;i<=n;++i) {
				ans+=max(a[i],b[i],c[i]);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
