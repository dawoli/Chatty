 #include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k;
int a[100005];
int cnt;
int flag;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
     cin>>n>>k;
    	for(int i=1;i<=n;i++){
    		cin>>a[i];
		}
	if(k==0){
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				cnt++;
				continue;
			}
			else{
				for(int j=i;j<=n;j++){
					if(a[j]!=0){
						flag=j;
					}
				}
				int t=flag-i+1;
				cnt+=t/2;
				i=flag; 
			}
		}
	}
 	if(k==1){
 		for(int i=1;i<=n;i++){
 			if(a[i]==1){
 				cnt++;
		}
		 }
	 }
	 cout<<cnt;
}
