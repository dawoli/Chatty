#include<bits/stdc++.h>
using namespace std;
int n,m;
string a[10007][10007];
int ans;
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
		if(a[i][j] =="."){
			if(!(a[i][j+1]=="x" && a[i][j-1]=="x" && a[i+1][j+1]=="x" && a[i+1][j-1]=="x" && a[i-1][j+1]=="x" && a[i-1][j-1]=="x" && a[i+1][j]=="x" && a[i-1][j]=="x")){
				ans++;
			}
		}
		}
	}
return 0;
}
	
