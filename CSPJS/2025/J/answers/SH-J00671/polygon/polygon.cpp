#include <bits/stdc++.h>
using namespace std;
int a[5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,num=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				if(a[i]+a[j]>a[k]){
					num++;
				}
				else{
					break;
				}
				for(int m=k+1;m<=n;m++){
					if(a[i]+a[j]+a[k]>a[m]){
						m++;
					}else{
						break;
					}
					for(int x=m+1;x<=n;x++){
						if(a[i]+a[j]+a[k]+a[m]>a[x]){
							num++;
						}else{
							break;
						}
						for(int y=x+1;y<=n;y++){
							if(a[i]+a[j]+a[k]+a[m]>a[x]){
								num++;
							}
						}
					}
				}
			}
		}
	}
	cout<<num;
	return 0;
}
