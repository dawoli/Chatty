#include<iostream>
#include<algorithm>
#include<fstream>
using namespace std;
ifstream fin("club.in");
ofstream fout("club.out");
long long a[100005][4];
long long c[100005];
long long p[10];
long long d[100005];
int main(){
	int t;
	//cin>>t;
	fin>>t;
	while(t--){
		int n;
		//cin>>n;
		fin>>n;
		for(int i=0;i<=n+3;i++){
			a[i][0]=-1;
			a[i][1]=-1;
			a[i][2]=-1;
			c[i]=-1;
			d[i]=0;
		}
		for(int i=0;i<5;i++){
			p[i]=0;
		}
		for(int i=0;i<n;i++){
			fin>>a[i][0]>>a[i][1]>>a[i][2];
			//cin>>a[i][0]>>a[i][1]>>a[i][2];
		}
		for(int i=0;i<n;i++){
			long long w=max(a[i][0],max(a[i][1],a[i][2]));
			if(w==a[i][0]){
				c[i]=0;
				p[0]++;
			}
			else if(w==a[i][1]){
				c[i]=1;
				p[1]++;
			}
			else if(w==a[i][2]){
				c[i]=2;
				p[2]++;
			}
		}
		long long ans=0;
		for(int i=0;i<n;i++){
			ans+=a[i][c[i]];
		}
		if(p[0]<=n/2&&p[1]<=n/2&&p[2]<=n/2){
			fout<<ans<<"\n";
			//cout<<ans<<"\n";
		}
		else{
			int l=0;
			if(p[0]>n/2){
				for(int i=0;i<n;i++){
					if(c[i]==0){
						d[l]=min(a[i][0]-a[i][1],a[i][0]-a[i][2]);
						l++;
					}
				}
				sort(d,d+l);
				for(int i=0;i<p[0]-n/2;i++){
					ans-=d[i];
				}
				fout<<ans<"\n";
				//cout<<ans<<"\n";
			}
			else if(p[1]>n/2){
				for(int i=0;i<n;i++){
					if(c[i]==1){
						d[l]=min(a[i][1]-a[i][0],a[i][1]-a[i][2]);
						l++;
					}
				}
				sort(d,d+l);
				for(int i=0;i<p[1]-n/2;i++){
					ans-=d[i];
				}
				fout<<ans<"\n";
				//cout<<ans<<"\n";
			}
			else if(p[2]>n/2){
				for(int i=0;i<n;i++){
					if(c[i]==2){
						d[l]=min(a[i][2]-a[i][1],a[i][2]-a[i][0]);
						l++;
					}
				}
				sort(d,d+l);
				for(int i=0;i<p[2]-n/2;i++){
					ans-=d[i];
				}
				fout<<ans<"\n";
				//cout<<ans<<"\n";
			}	
		}
	}
} 
