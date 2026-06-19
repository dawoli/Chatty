#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	string ans="";
	long long hash[10];
	for(int i=0;i!=10;i++){
		hash[i]=0;
	}
	for(long long i=0;i!=a.size();i++){
		if(a[i]>='0' and a[i]<='9'){
			hash[a[i]-'0']++;
		}
	}
	for(int i=9;i!=-1;i--){
		if(i==0 and ans==""){
			ans="0";
			break;
		}
		for(int j=0;j!=hash[i];j++){
			ans+=('0'+i);
		}
	}
	cout<<ans;
	return 0;
}
