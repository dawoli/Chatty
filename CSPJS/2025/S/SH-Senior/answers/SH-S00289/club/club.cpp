#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y,z;
}a[200010],b[200010];
bool cmp1(node k,node j){
	if(k.x>j.x)return k.x<j.x;
}
bool cmp2(node k,node j){
	if(k.y>j.y)return k.y<j.y;
}
bool cmp3(node k,node j){
	if(k.z>j.z)return k.z<j.z;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long t,n,c[10],g=0;
	cin>>t;
	while(t--){
		long long sum=0,ans=0,cnt=0,sx=0,sy=0,sz=0,maxn=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
		}
		if(n==2){
			for(int i=1;i<=2;i++){
				if(max(a[i].x,max(a[i].y,a[i].z))==a[i].x){
					maxn+=a[i].x;
					sum++;
					if(sum==2){	
							if(a[i].x+max(a[i-1].y,a[i-1].z)>max(a[i].y,a[i].z)+a[i-1].x){
								maxn-=a[i-1].x;
								maxn+=max(a[i-1].y,a[i-1].z);
							}
							else if(a[i].x+max(a[i-1].y,a[i-1].z)<max(a[i].y,a[i].z)+a[i-1].x){
								maxn-=a[i].x;
								maxn+=max(a[i].y,a[i].z);
							}
					}
				}	
				else if(max(a[i].x,max(a[i].y,a[i].z))==a[i].y){
					maxn+=a[i].y;
					ans++;
					if(ans==2){	
							if(a[i].y+max(a[i-1].x,a[i-1].z)>max(a[i].x,a[i].z)+a[i-1].y){
								maxn-=a[i-1].y;
								maxn+=max(a[i-1].x,a[i-1].z);
							}
							else if(a[i].y+max(a[i-1].x,a[i-1].z)<max(a[i].x,a[i].z)+a[i-1].y){
								maxn-=a[i].y;
								maxn+=max(a[i].x,a[i].z);
							}
					}
				}
				else if(max(a[i].x,max(a[i].y,a[i].z))==a[i].z){
					maxn+=a[i].z;
					cnt++;
					if(cnt==2){	
							if(a[i].z+max(a[i-1].y,a[i-1].x)>max(a[i].y,a[i].x)+a[i-1].z){
								maxn-=a[i-1].z;
								maxn+=max(a[i-1].y,a[i-1].z);
							}
							else if(a[i].z+max(a[i-1].y,a[i-1].x)<max(a[i].y,a[i].x)+a[i-1].z){
								maxn-=a[i].z;
								maxn+=max(a[i].y,a[i].x);
							}
					}
				}		
			}
		}
		else{
			for(int i=1;i<=n;i++){		
				if(max(a[i].x,max(a[i].y,a[i].z))==a[i].x){
					sort(b+1,b+n+1,cmp1);
					sx+=a[i].x;
					sum++;
					b[sum].x=a[i].x;
					if(ans>n/2){
						if(min(b[sum].x,min(b[2].x,b[1].x))==b[1].x){
							sx-=b[1].x;
							b[1].x=b[sum].x;
							b[sum].x=0;
							sum--;
						}	    
						else if(min(b[sum].x,min(b[2].x,b[1].x))==b[2].x){
							sx-=b[2].x;
							b[2].x=b[sum].x;
							b[sum].x=0;
							sum--;
						}	
						else{
							sum--;
							sx-=b[sum].x;
							sx+=max(b[sum].y,b[sum].z);
							if(max(b[sum].y,b[sum].z)==b[sum].y)ans++;
							else cnt++;
						}             
					}
				}
				else if(max(a[i].x,max(a[i].y,a[i].z))==a[i].y){
					sort(b+1,b+n+1,cmp2);
					sy+=a[i].y;
					ans++;
					b[ans].y=a[i].y;
					if(ans>n/2){
						if(min(b[ans].y,min(b[2].y,b[1].y))==b[1].y){
							sy-=b[1].y;
							b[1].y=b[ans].y;
							b[ans].y=0;
							ans--;
						}	    
						else if(min(b[ans].y,min(b[2].y,b[1].y))==b[2].y){
							sy-=b[2].y;
							b[2].y=b[ans].y;
							b[ans].y=0;
							ans--;
						}	
						else{
							ans--;
							sy-=b[ans].y;
							sy+=max(b[ans].x,b[ans].z);
							if(max(b[ans].x,b[ans].z)==b[ans].x)sum++;
							else cnt++;
						}                
					}
				}
				else if(max(a[i].x,max(a[i].y,a[i].z))==a[i].z){
					sort(b+1,b+n+1,cmp3);
					sz+=a[i].z;
					cnt++;
					b[cnt].z=a[i].z;
					if(cnt>n/2){
						if(min(b[cnt].z,min(b[2].z,b[1].z))==b[1].z){
							sz-=b[1].z;
							b[1].z=b[cnt].z;
							b[cnt].z=0;
							cnt--;
						}	    
						else if(min(b[cnt].z,min(b[2].z,b[1].z))==b[2].z){
							sz-=b[2].z;
							b[2].z=b[cnt].z;
							b[cnt].z=0;
							cnt--;
						}	
						else{
							cnt--;
							sz-=b[cnt].z;
							sz+=max(b[cnt].y,b[cnt].x);
							if(max(b[ans].x,b[ans].y)==b[ans].x)sum++;
							else ans++;
						}         
					}
				}
			}
		
			

		}
		maxn+=(sx+sy+sz);
		g++;
		c[g]=maxn;
	}
	for(int i=1;i<=g;i++){
		cout<<c[i]<<endl;
	}
	freopen(stdin);
	freopen(stdout);
	return 0;            
} 
