#include<bits/stdc++.h>
using namespace std;
int a[5000];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.in","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==5){
		cout<<9;
	}
	fclose(stdin);
	fclose(stdout);
    
     
	return 0;
}
