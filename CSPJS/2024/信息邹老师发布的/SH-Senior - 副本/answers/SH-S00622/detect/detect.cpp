#include<bits/stdc++.h>
using namespace std;
long long T,n,m,l,V,d[100010],v[100010],a[100010],p[100010],t,cnt,a0,a2;
bool used[1000010];
int binsearch(long long x[],int i){
	int l=1,r=m;
	while(l<r){
		int mid=l+r>>1; 
		if(p[mid]<x[i])l=mid+1;
		else r=mid;
	}
	return l;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ios::sync_with_stdio(0); 
	cin>>T;
	while(T--){
		cin>>n>>m>>l>>V;cnt=0;a0=0,a2=0;
	//	memset(used,0,sizeof used);
		for(int i=1;i<=n;i++)cin>>d[i]>>v[i]>>a[i];
		for(int i=1;i<=m;i++)cin>>p[i];
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				a0++;
				if(d[i]<=p[m] and v[i]>V){
					cnt++;
				}
			}
			if(a[i]<0){
				t=binsearch(d,i);
				int s=p[t]-d[i];
				if(v[i]*v[i]+2*a[i]*s>V*V){
					cnt++;
				}
			}
			if(a[i]>0){
				a2++;
				int s=p[m]-d[i];
				if(s<0)continue;
				if(v[i]*v[i]+2*a[i]*s>V*V){
					cnt++;
				}
			}
		}
		if(n<=20){
			int minn=2e9;
			for(int i=1;i<(1<<n);i++){
				int t=i,l=0,sum=0,maxx,cnttt=0;
				while(t){
					used[++l]=t%2;
					if(used[l])maxx=l,cnttt++;
					t/=2;
				}
				bool flag=true;
				for(int j=1;j<=n;j++){
					if(a[j]==0){
						if(d[j]<=p[m] and v[i]>V){
							if(d[j]>p[maxx]){
								flag=false;
								break;
							}
						}
					}
					if(a[j]<0){
						t=binsearch(d,i);
						int s=p[t]-d[i];
						if(v[i]*v[i]+2*a[i]*s>V*V){
							for(int k=t;k<=n;k++){
								if(!used[k])continue;
								int s1=p[k]-d[i];
								if(sqrt(v[i]*v[i]+2*a[i]*s1)<=V){
									flag=false;
									break;
								}
							}
						}
					}
					if(a[j]>0){
						int s=p[m]-d[i];
						if(v[i]*v[i]+2*a[i]*s>V*V){
							int s1=p[maxx]-d[i];
							if(sqrt(v[i]*v[i]+2*a[i]*s1)<=V){
								flag=false;
								break;
							}
						}
					}
				}
				if(flag)minn=min(minn,cnttt);
			}
			cout<<cnt<<' '<<minn<<'\n';
		}
		else if(a0==n or a2==n){
			if(cnt==0)cout<<cnt<<' '<<m<<'\n';
			else cout<<cnt<<' '<<m-1<<'\n';
		}
		else{
			if(cnt==0)cout<<cnt<<' '<<m<<'\n';
			else cout<<cnt<<' '<<m-1<<'\n';
		}
	}

	return 0;
}

