#include<iostream>
#include<cstring>
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n,m,L,V;
int d[N],a[N],v[N],p[N];
int f(int x,int y){
	return (V*V-x*x)/(2*y);
}
int main(){
	freeopen("detect.in","r",stdin);
	freeopen("detect.out","w",stdout);
	cin>>T;
	while(T--){
		int cnt1=0,cnt2=0;
		cin>>n>>m>>L>>V;
		memset(d,0,sizeof(d));
		memset(a,0,sizeof(a));
		memset(v,0,sizeof(v));
		memset(p,0,sizeof(p));
		for(int i=1;i<=n;i++){
			cin>>d[i]>>v[i]>>a[i];
			if(a[i]==0){
				cnt1++;
			}else if(a[i]>0){
				cnt2++;
			}
		}
		
		for(int i=1;i<=m;i++){
			cin>>p[i];
		}
		if(cnt1==n){
			cnt1=0;
			for(int i=1;i<=n;i++){
				if(v[i]>V){
					cnt1++;	
				}
			}
			cout<<cnt1<<" "<<(m-1)<<endl;	
		}else if(cnt2==n){
			cnt2=0;
			for(int i=1;i<=n;i++){
				int l=d[i]+f(v[i],a[i]);
				if(l<=L){
					for(int j=1;j<=m;j++){
						if(p[j]>=l){
							cnt2++;
							break;
						}
					}
				}
			}
			cout<<cnt2<<" "<<(m-1)<<endl;
		}else{
			cout<<"QAQ"<<endl;
		}
			
	}
	
	return 0;
}
