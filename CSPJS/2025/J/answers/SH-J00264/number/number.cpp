#include<bits/stdc++.h>
using namespace std;
int num[1000100],_i=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;cin>>a;	
	for(int i=0;i<a.size();i++){
		if(a[i]>='0' && a[i]<='9') num[_i++]=a[i]-'0';
	}
	sort(num+1,num+_i+1);
	for(int i=_i;i>1;i--) cout<<num[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
