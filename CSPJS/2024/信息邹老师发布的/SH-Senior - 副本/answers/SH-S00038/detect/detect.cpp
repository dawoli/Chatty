#include<bits/stdc++.h>
using namespace std;
int a[100005][4],b[100005][2];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T;
	cin>>T;
	for(int q=1;q<=T;q++){
		int n,m,L,V,cnt=0;
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
		}
		for(int i=1;i<=m;i++){
			cin>>b[i][0];
			for(int j=1;j<=n;j++){
				if(a[j][0]<b[i][0]){
					if(pow(pow(a[j][1],2)+2*a[j][2]*(b[i][0]-a[j][0]),0.5)>V){
						b[i][1]++;
						if(a[j][3]==0){
							cnt++;
							a[j][3]++;
						}
					}
				}
			}
		}
		cout<<cnt<<" ";
		cnt=0;
		for(int i=1;i<=m;i++){
			if(b[i][1]==0){
				cnt++;
			}
		}
		cout<<cnt+2<<endl;
	}
	return 0;
}
