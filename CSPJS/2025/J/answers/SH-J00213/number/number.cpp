#include<bits/stdc++.h>
using namespace std;
char a[1000000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int u=1;
	while(cin>>a[u]){
		if(a[u]>='0'&&a[u]<='9'){
			u++;
		}
	}
	sort(a+1,a+u);
	for(int i=u-1;i>=1;i--){
		cout<<a[i]; 
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
