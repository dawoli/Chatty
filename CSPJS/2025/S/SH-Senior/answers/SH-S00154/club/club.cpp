#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
long long sum=0;
int as,bs,cs;
bool az=true,bz=true,cz=true;
int half;
int a[N][3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while (t--){
		sum=0;
		long long ans=0;
		int n;
		cin>>n;
		half=n/2;
		for (int i=1;i<=n;i++){
			for (int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		for (int i=1;i<=n;i++){
			int z=0;
			if (a[i][2]==0 && a[i][3]==0){
				if (as==half){
					for (int j=i;j>=1;j--){
						if (a[j][1]!=0){
							sum-=a[j][1];
							int z=max(a[j][2],a[j][3]);
							if (z==a[j][2] && bz==false){
								z=a[j][3];
							}
							else z=a[j][2];
							if (z==a[j][3] && cz==false){
								z=a[j][2];
							}
							else z=a[j][3];
						}
						break;
					}
				}
				else z=a[i][1]; 
				as++;
			}
			if (sum+z>a[i][1]){
				sum+=z;
			}
			else{
				sum+=a[i][1];
			}
			z=max(a[i][1],max(a[i][2],a[i][3]));
			if (z==a[i][1] && az==true){
				as++;
				if (as>half){
					az=false;
				}
			}
			else if (z==a[i][1] && az==false){
				int xz=max(a[i][2],a[i][3]);
				if (xz==a[i][2] && bz==true){
					bs++;
					if (bs>half){
						bz=false;
					}
					z=a[i][2];
				}
				else{
					cs++;
					if (cs>half){
						cz=false;
					}
					z=a[i][3];
				}
			}
			else if (z==a[i][2] && bz==true){
				bs++;
				if (bs>half){
					bz=false;
				}
			}
			else if (z==a[i][2] && bz==false){
				int xz=max(a[i][1],a[i][3]);
				if (xz==a[i][1] && bz==true){
					as++;
					if (as>half){
						az=false;
					}
					z=a[i][1];
				}
				else{
					cs++;
					if (cs>half){
						cz=false;
					}
					z=a[i][3];
				}
			}
			if (z==a[i][3] && cz==true){
				cs++;
				if (cs>half){
					cz=false;
				}
			}
			else if (z==a[i][3] && cz==false){
				int xz=max(a[i][1],a[i][2]);
				if (xz==a[i][1] && az==true){
					as++;
					if (as>half){
						az=false;
					}
					z=a[i][1];
				}
				else{
					bs++;
					if (bs>half){
						bz=false;
					}
					z=a[i][2];
				}
			}
			sum+=z;
		}
		cout<<sum<<endl;
	}
	return 0;
}
