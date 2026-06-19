#include <bits/stdc++.h>
using namespace std;
int n,t,a[200010];
bool f=0;
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	while(t--){
		int cnt=0,x=0,y=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[i]==a[j]){
					if(x<i&&i<y&&y-x!=2&&j-i!=2){
						if(a[i]>a[x]) cnt-=min(a[i],a[x]);
					}
					else cnt+=a[i];
					x=i,y=j;						
				}
			}
		}
		cout<<cnt<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
