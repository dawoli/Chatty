#include<bits/stdc++.h>
using namespace std;
int t=0,n=0,a[200005][5]={},b[5]={},c[200005][5]={},ans=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int iii=0;iii<t;iii+=1){
		b[1]=0;
		b[2]=0;
		b[3]=0;
		ans=0;
		cin>>n;
		for(int i=0;i<n;i+=1){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
				a[i][0]=1;
				b[1]+=1;
			}
			else if(a[i][2]>=a[i][3]){
				a[i][0]=2;
				b[2]+=1;
			}
			else{
				a[i][0]=3;
				b[3]+=1;
			}
			ans+=a[i][a[i][0]];
		}
		if(b[1]>n/2){
			for(int i=0;i<n;i+=1){
				if(a[i][0]!=1){
					c[i][0]=1;
					continue;
				}
				c[i][0]=0;
				if(a[i][3]>a[i][2]){
					c[i][1]=a[i][1]-a[i][3];
				}
				else{
					c[i][1]=a[i][1]-a[i][2];
				}
			}
			for(int i=0;i<b[1]-n/2;i+=1){
				int num=20005,f;
				for(int j=0;j<n;j+=1){
					if(c[j][0]){
						continue;
					}
					if(c[j][1]<num){
						num=c[j][1];
						f=j;
					}
				}
				ans-=c[f][1];
				c[f][0]=1;
			}
		}
		else if(b[2]>n/2){
			for(int i=0;i<n;i+=1){
				if(a[i][0]!=2){
					c[i][0]=1;
					continue;
				}
				c[i][0]=0;
				if(a[i][3]>a[i][1]){
					c[i][2]=a[i][2]-a[i][3];
				}
				else{
					c[i][2]=a[i][2]-a[i][1];
				}
			}
			for(int i=0;i<b[2]-n/2;i+=1){
				int num=20005,f;
				for(int j=0;j<n;j+=1){
					if(c[j][0]){
						continue;
					}
					if(c[j][2]<num){
						num=c[j][2];
						f=j;
					}
				}
				ans-=c[f][2];
				c[f][0]=1;
			}
		}
		else if(b[3]>n/2){
			for(int i=0;i<n;i+=1){
				if(a[i][0]!=3){
					c[i][0]=1;
					continue;
				}
				c[i][0]=0;
				if(a[i][2]>a[i][1]){
					c[i][3]=a[i][3]-a[i][2];
				}
				else{
					c[i][3]=a[i][3]-a[i][1];
				}
			}
			for(int i=0;i<b[3]-n/2;i+=1){
				int num=20005,f;
				for(int j=0;j<n;j+=1){
					if(c[j][0]){
						continue;
					}
					if(c[j][3]<num){
						num=c[j][3];
						f=j;
					}
				}
				ans-=c[f][3];
				c[f][0]=1;
			}
		}
		cout<<ans<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
