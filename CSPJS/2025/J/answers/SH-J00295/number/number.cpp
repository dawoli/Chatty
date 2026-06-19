#include<bits/stdc++.h>
using namespace std;
int cnt=0;
int num[1000005]={};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	for(int i=0;(a[i]>='a' && a[i]<='z')||(a[i]>='0' && a[i]<='9');i++){
		if(a[i]>='0' && a[i]<='9'){
			num[cnt]=a[i]-'0';
			cnt++;
		}
	}
	sort(num,num+cnt);
	for(int i=cnt-1;i>=0;i--){
		cout<<num[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
