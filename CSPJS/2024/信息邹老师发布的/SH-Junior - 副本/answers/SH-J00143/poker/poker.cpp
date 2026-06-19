#include<bits/stdc++.h>
using namespace std;
int n,ans,a[200][200],x1[5]={'D','C','H','S'},x2[20]={'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
char c1,c2;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>c1>>c2;
		a[c1][c2]=1;
	}
	for(int i=0;i<4;i++){
		for(int j=0;j<13;j++){
			if(a[x1[i]][x2[j]]==0){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
