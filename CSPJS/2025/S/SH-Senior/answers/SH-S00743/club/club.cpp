#include<bits/stdc++.h>
using namespace std;
int a[100005][5],s[20005]={0},sum;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		int M[100005]={0};
		int Max=0;
		for(int j=0;j<n;j++){
			cin>>a[j][1]>>a[j][2]>>a[j][3];
			M[j]=a[j][1];
		}
		if(n==2){
			for(int k=1;k<=3;k++){
				for(int m=1;m<=3;m++){
					if(m==k){
						continue;
					}
					Max=max(a[0][m]+a[1][k],Max);
				}
			}
			cout<<Max<<endl;
		}
		else if (n<=30){
			for(int j=0;j<n-1;j++){
				for(int l=j+1;l<n;l++){
					for(int k=1;k<=3;k++){
						for(int m=1;m<=3;m++){
							if(m==k){
								continue;
							}
							Max=max(a[j][m]+a[l][k],Max);
						}
					}
				}
			}
			cout<<Max<<endl;
		}
		else{
			for(int j=0;j<n;j++){
				s[M[j]]++;
			}
			int m=0;
			for(int j=20001;j>0;j--){
				for(int k=0;k<s[j];k++){
					Max+=j;
					m++;
					if(m>=n/2){
						break;
					}
				}
				if(m>=n/2){
					break;
				}
			}
			
			cout<<Max<<endl;
		}
		
		
	}
	return 0;
}
