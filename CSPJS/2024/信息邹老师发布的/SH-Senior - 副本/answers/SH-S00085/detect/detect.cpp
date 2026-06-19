#include<bits/stdc++.h>
using namespace std;
int d[1000009],v[1000009],a[1000009],p[1000009],cnt;
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t;
	cin>>t;
	while(t>0){
		t--;
		cnt=0;
		int n,m,l,vm;
		cin>>n>>m>>l>>vm;
		for(int i=1;i<=n;i++){
			d[i]=0;
			a[i]=0;
			v[i]=0;
			cin>>d[i]>>v[i]>>a[i];
		}
		for(int i=1;i<=m;i++){
			cin>>p[i];
		}
		
		for(int i=1;i<=n;i++){
			if(a[i]<0){
				if(v[i]>vm){
					double dis=-(v[i]-vm)/a[i]*v[i]+0.5*(v[i]-vm)*(v[i]-vm)/a[i]+d[i];
					
		//			if(v[i]>=4)cout<<dis<<endl;
					
					for(int j=1;j<=m;j++){
						
						if(p[j]<=dis&&p[j]>=d[i]){
							cnt++;
							break;
						}
					}
				}
			}
			else if(a[i]==0){
				if(v[i]>vm){
					for(int j=1;j<=m;j++){
						if(p[j]>=d[i]){
							cnt++;
							break;
						}
					}
				}
			}
			else {
				//yikaishichaosu
				if(v[i]>vm){
					for(int j=1;j<=m;j++){
						if(p[j]>=d[i]){
							cnt++;
							break;
						}
					}
				}
				else{
					
					double dis=(vm-v[i])/a[i]*v[i]+0.5*(vm-v[i])*(v[i]-vm)/a[i]+d[i];
					for(int j=1;j<=m;j++){
						if(p[j]>=dis&&p[j]>=d[i]){
							cnt++;
							break;
						}
					}
				}
			}
		}
		cout<<cnt<<" "<<cnt<<endl;
		
	}
	
	
	return 0;
}
