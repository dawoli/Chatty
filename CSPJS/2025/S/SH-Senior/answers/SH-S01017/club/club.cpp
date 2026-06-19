#include<bits/stdc++.h>
using namespace std;
int t;
int n;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		int a[100001][3];
		n=0;
		cin>>n;
		int not2=0,not3=0;
		for(int j=0;j<n;j++){
			for(int k=0;k<3;k++){
				cin>>a[j][k];
				if(k==1&&a[j][1]==0){
					not2++;
//					cout<<a[j][1]<<" "<<not2<<endl;////////////////
				}
				if(k==2&&a[j][2]==0)not3++;
			}
		}
//		cout<<not2<<" "<<not3<<endl;/////////////////
		if(n==2){
			int ans=0;
			for(int j=0;j<3;j++){
				for(int k=0;k<3;k++){
					if(j!=k&&ans<=a[0][j]+a[1][k])ans=a[0][j]+a[1][k];
				}
			}
			cout<<ans<<endl;
			continue;
		}
//		cout<<"a";//////////////
		if(not2==n&&not3==n){
			int jl[100001]={};
			jl[0]=100000;
			int ybn=n/2;
			for(int j=0;j<n;j++){
				for(int k=1;k<=ybn;k++){
					if(a[j][0]>jl[k]&&jl[k-1]>a[j][0]){
					//	
						for(int h=n-1;h>=k;h--){
							jl[h+1]=jl[h];
						}
						jl[k]=a[j][0];
//						for(int h=1;h<=ybn;h++){
//							cout<<jl[h]<<" ";
//						}
//						cout<<endl;
					}
					
				}
				
			}
			long long ans=0;
			for(int k=1;k<=ybn;k++){
//				cout<<jl[k]<<" ";//////////////
				ans+=jl[k];
			}
			cout<<ans<<endl;
			continue;
		}
	}
	return 0;
} 
