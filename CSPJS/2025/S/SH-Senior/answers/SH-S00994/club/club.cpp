#include<bits/stdc++.h>
using namespace std;
int n,t;
struct node{
	int f[10];
}a[100009];
bool cmp(node x,node y){
	int b[]={0,x.f[1],x.f[2],x.f[3]};sort(b+1,b+3+1);
	int c[]={0,y.f[1],y.f[2],y.f[3]};sort(c+1,c+3+1);
	if(b[3]-b[2]!=c[3]-c[2]) return b[3]-b[2]>c[3]-c[2];
	if(b[2]-b[1]!=c[2]-c[1]) return b[2]-b[1]>c[2]-c[1];
	if(b[3]!=c[3]) return b[3]>c[3];
	if(b[2]!=c[2]) return b[2]>c[2];
	if(b[1]!=c[1]) return b[1]>c[1];
	return false;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		int ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].f[1]>>a[i].f[2]>>a[i].f[3];
		}
		sort(a+1,a+n+1,cmp);
		int x,y,z;x=y=z=0;
		for(int i=1;i<=n;i++){
			if(a[i].f[1]>a[i].f[2] and a[i].f[1]>a[i].f[3]){
				if(x<n/2){
					x++;
					ans+=a[i].f[1];
				}else{
					if(a[i].f[2]>a[i].f[3]){
						y++;
						ans+=a[i].f[2];
					}else{
						z++;
						ans+=a[i].f[3];
					}
				}
			}else if(a[i].f[2]>a[i].f[1] and a[i].f[2]>a[i].f[3]){
				if(y<n/2){
					y++;
					ans+=a[i].f[2];
				}else{
					if(a[i].f[1]>a[i].f[3]){
						x++;
						ans+=a[i].f[1];
					}else{
						z++;
						ans+=a[i].f[3];
					}
				}
			}else{
				if(z<n/2){
					z++;
					ans+=a[i].f[3];
				}else{
					if(a[i].f[1]>=a[i].f[2]){
						x++;
						ans+=a[i].f[1];
					}else{
						y++;
						ans+=a[i].f[2];
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
