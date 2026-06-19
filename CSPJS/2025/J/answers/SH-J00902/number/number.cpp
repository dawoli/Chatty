#include<bits/stdc++.h>
using namespace std;
int b[1010];
char a[100010];
char ch1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int i=1;
	while(cin>>b[i]){
		i++;
	}
	for(int j=1;j<=i;j++){
		for(int k=1;k<=j;k++){
			if(b[k]<b[k+1]){
				int t=b[k];
				b[k]=b[k+1];
				b[k+1]=t;
			}
		}
	}
	for(int m=1;m<=i;m++){
		cout<<b[m];
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
