#include <bits/stdc++.h>
using namespace std;
int n,cnt=0,s=0;
string x[60],y[60];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","r",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<52;j++){
			if(y[j]==x[i]){
				cnt=1;
				break;
			}
		}
		if(cnt!=1){
			y[s]=x[i];
			s++;
		}
		cnt=0;
	}
	printf("%d",m-s);
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
