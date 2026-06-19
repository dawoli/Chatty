#include<bits/stdc++.h>
using namespace std;
int ans[1000005],cnt=0,res[15]={};
int main(){
	freopem("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	for(int i = 0; i < a.size(); i++){
		if(a[i]>='0'&&a[i]<='9'){
			ans[cnt++]=a[i]-'0';
		}
	}
	for(int i = 0; i < 10; i++){
		res[i]=0;
	}
	for(int i = 0; i < cnt; i++){
		res[ans[i]]++;
	}
	for(int i = 10; i >= 0 ; i--){
		if(res[i]!=0)for(int j = 0; j < res[i];j++)cout<<i;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
