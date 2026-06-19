#include <bits/stdc++.h>
 using namespace std;
 const int N=1e5+10;
 int a[5][N],tow1[N];
int n,t;
 int main(){
 	freopen("club.in","r",stdin);
 	freopen("club.out","w",stdout);
 	cin>>t;
 	while(t!=0){
 		cin>>n;
 		for(int j=0;j<n;j++){
 			for(int k=0;k<3;k++){
 				cin>>a[j][k];
			}
		}
		if(n==2){
			int m=0;
			for(int i=0;i<3;i++){
				for(int j=0;i<3;j++){
					if(a[i][0]+a[j][1]>m && i!=j){
						m=a[i][0]+a[j][1];
					}
				}	
			}
		cout<<m;
		return 0;
		}
		for(int i=0;i<n;i++){
			tow1[i]=a[1][i];
		}
		int q=tow1[0];
		for(int i=0;i<n;i++){
			if(tow1[i]>q){
				q=tow1[i];
			}
		}
		for(int i=0;i<n;i++){
			bool res=true;
			if(a[2][i]!=0 || a[3][i]!=0){
				res=false;
			}
			if(res){
				cout<<q;
				return 0;
			}
		}
	t--;
	}
 	fclose(stdin);
 	fclose(stdout);
 	return 0;
}
