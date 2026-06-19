#include<bits/stdc++.h>
using namespace std;
struct student{
	int a1;
	int a2;
	int a3;
};

bool compare1(student a,student b){
	if(min(a.a3,min(a.a1 ,a.a2)) >min(b.a3,min(b.a1 ,b.a2)) )return min(a.a3,min(a.a1 ,a.a2)) >min(b.a3,min(b.a1 ,b.a2));
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("clud.out","w",stdout);
	student a[100005];
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		memset(a,0,sizeof(a));
		for(int i=0;i<n;i++)cin>>a[i].a1 >>a[i].a2 >>a[i].a3 ; 
		sort(a,a+n,compare1);
		int ans=0,cnt[3]={0};
		for(int i=0;i<n;i++)
		{
			if(a[i].a1 >a[i].a2 ){
				if(a[i].a1 >a[i].a3 ){
					if(cnt[0]<n/2){
						ans+=a[i].a1 ;
						cnt[0]++;
					}else if(a[i].a2 >a[i].a3 ){
						if(cnt[1]<n/2){
							ans+=a[i].a2 ;
							cnt[1]++;
						}
						else{
							ans+=a[i].a3 ;
							cnt[2]++;
						}
					}
					else{
						ans+=a[i].a3 ;
						cnt[2]++;
					}
				}
				else{
					if(cnt[2]<n/2){
						ans+=a[i].a3 ;
						cnt[2]++;
					}else if(cnt[0]<n/2){
							ans+=a[i].a1 ;
							cnt[0]++;
						}
						else{
							ans+=a[i].a2 ;
							cnt[1]++;
						}
					}
				}
			
			
			
			else{
				if(a[i].a2 >a[i].a3 ){
					if(cnt[1]<n/2){
						ans+=a[i].a2 ;
						cnt[1]++;
					}else if(a[i].a1 >a[i].a3 ){
						if(cnt[0]<n/2){
							ans+=a[i].a1 ;
							cnt[0]++;
						}
						else{
							ans+=a[i].a3 ;
							cnt[2]++;
						}
					}
					else{
						ans+=a[i].a3 ;
						cnt[2]++;
					}
				}
				else{
					if(cnt[2]<n/2){
						ans+=a[i].a3 ;
						cnt[2]++;
					}else if(cnt[1]<n/2){
							ans+=a[i].a2 ;
							cnt[1]++;
						}
						else{
							ans+=a[i].a1 ;
							cnt[0]++;
						}
					}
				}
		}
		cout<<ans<<endl;
	}
	return 0;
}
