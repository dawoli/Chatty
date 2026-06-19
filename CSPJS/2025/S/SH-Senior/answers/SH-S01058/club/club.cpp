#include <bits/stdc++.h>
using namespace std;
struct stu{
	int x,y,z;
	int maxx,td,zy;
}a[100086];
bool cmp1(stu a,stu b){
	return a.maxx>b.maxx;
}
bool cmp2(stu a,stu b){
	return a.td<b.td;
}
int answ[100086];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int w;
	cin>>w;
	int n;
	for(int j=0;j<w;j++){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			a[i].maxx=max(max(a[i].x,a[i].y),a[i].z);
			if(a[i].x>=a[i].y){
				if(a[i].x>=a[i].z){
					if(a[i].y>=a[i].z){
						a[i].td=a[i].x-a[i].y;
					}else{
						a[i].td=a[i].x-a[i].z;
					}
				}else{
					a[i].td=a[i].z-a[i].x;
				}
			}else{
				if(a[i].y>=a[i].z){
					if(a[i].x>=a[i].z){
						a[i].td=a[i].y-a[i].x;
					}else{
						a[i].td=a[i].y-a[i].z;	
					}
				}else{
					a[i].td=a[i].z-a[i].y;
				}
			}
		}
		sort(a+1,a+1+n,cmp1);
		int dx=0,dy=0,dz=0;
		int ans=0;
		for(int i=1;i<=n;i++){
			if(a[i].x>=a[i].y&&a[i].x>=a[i].z){
				dx++;
				a[i].zy=1;
				ans+=a[i].x;
				continue;
			}
			if(a[i].y>=a[i].x&&a[i].y>=a[i].z){
				dy++;
				a[i].zy=2;
				ans+=a[i].y;
				continue;
			}
			if(a[i].z>=a[i].y&&a[i].z>=a[i].x){
				dz++;
				a[i].zy=3;
				ans+=a[i].z;
				continue;
			}
		}
		if(dx>n/2){
			sort(a+1,a+1+n,cmp2);
			for(int i=1;i<=n;i++){
				if(a[i].zy==1){
					ans-=a[i].td;
					dx--;
					if(dx==n/2){
						break;
					}
				}
			}
		}
		if(dy>n/2){
			sort(a+1,a+1+n,cmp2);
			for(int i=1;i<=n;i++){
				if(a[i].zy==2){
					ans-=a[i].td;
					dy--;
					if(dy==n/2){
						break;
					}
				}
			}
		}
		if(dz>n/2){
			sort(a+1,a+1+n,cmp2);
			for(int i=1;i<=n;i++){
				if(a[i].zy==3){
					ans-=a[i].td;
					dz--;
					if(dz==n/2){
						break;
					}
				}
			}
		}
		answ[j]=ans;
	}
	for(int j=0;j<w;j++){
		cout<<answ[j]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
