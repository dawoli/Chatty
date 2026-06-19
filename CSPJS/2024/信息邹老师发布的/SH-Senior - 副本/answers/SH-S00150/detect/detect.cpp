#include<bits/stdc++.h>
using namespace std;
int a[1000006],b[1000006];
struct car{
	int x,y,z;
};
car c[1000006];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.in","w",stdout);
	int top,n,m,v,cnt,ans,vis;
	long long l;
	cin>>top;
	while(top--){
		cnt=0;
		ans=1;
		cin>>n>>m>>l>>v;
		for(int i=1;i<=n;i++){
			cin>>c[i].x>>c[i].y>>c[i].z;
		}
		for(int i=1;i<=m;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			ans=0;
			vis=0;
			if((c[i].y<=v||c[i].x>a[m])&&c[i].z<=0){
				continue;
			}
			while(c[i].x>a[ans]){
				ans++;
			}
			for(int j=ans;j<=m;j++){
				if(c[i].z==0){
					b[a[j]]=1;
					vis=1;
				}
				else{
					double s=(a[j]-c[i].x)*1.0;
					double V=sqrt(pow(c[i].y,2)*1.0+2*c[i].z*s*1.0)*1.0;
					if(V<=0) continue;
					if(V>v){
						b[a[j]]=1;
						vis=1;
					}
				}
			}
			if(vis==1){
				cnt++;
			}
		}
		ans=0;
		for(int i=1;i<=m;i++){
			if(b[a[i]]==0){
				ans++;
			}
		}
		cout<<cnt<<" "<<ans<<endl;
	}
	return 0;
}





