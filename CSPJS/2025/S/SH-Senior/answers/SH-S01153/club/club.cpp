#include<bits/stdc++.h>
using namespace std;
struct N{
	int x,y,z;
	bool xv=false,yv=false,zv=false;
}a[100005];
bool cmpx(N a,N b){
	return a.x>b.x;
}
bool cmpy(N a,N b){
	return a.y>b.y;
}
bool cmpz(N a,N b){
	return a.z>b.z;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int t;
	cin>>t;
	while(t--){
		int s_1=0,s_2=0,s_3=0,ans=0;
		int n,c[100005];
        bool b[3][100005]; 
		cin>>n;
		for(int i=0;i<n;i++)
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
		for(int i=0;i<n;i++){
			if(a[i].x>=a[i].y && a[i].x>=a[i].z){
				a[i].xv=1;
				ans+=a[i].x;
				s_1++;
			}
			else if(a[i].y>=a[i].x && a[i].y>=a[i].z){
				a[i].yv=1;
				ans+=a[i].y;
				s_2++;	
			}
			else{
				a[i].zv=1;
				ans+=a[i].z;
				s_3++;
			}
		}
		if(s_1*2>n){
			sort(a,a+n,cmpx);
			for(int i=n-1;i>=0;i--){
				if(a[i].xv==1){
					c[i]=a[i].x-max(a[i].y,a[i].z);
				}
			}
			sort(c,c+n);
			for(int i=0;i<s_1-n/2;i++){
				ans-=c[i];
			}
		}
		if(s_2*2>n){
		    sort(a,a+n,cmpy);
			for(int i=n-1;i>=0;i--){
				if(a[i].yv==1){
					c[i]=a[i].y-max(a[i].x,a[i].z);
				}
			}
			sort(c,c+n);
			for(int i=0;i<s_2-n/2;i++){
				ans-=c[i];
			}
		}
		if(s_3*2>n){
			sort(a,a+n,cmpz);
			for(int i=n-1;i>=0;i--){
				if(a[i].zv==1){
					c[i]=a[i].z-max(a[i].x,a[i].y);
				}
			}
			sort(c,c+n);
			for(int i=0;i<s_3-n/2;i++){
				ans-=c[i];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
