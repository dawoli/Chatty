#include <bits/stdc++.h>
using namespace std;
int flag[100]={0};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
			flag[a[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=flag[i];j++){
			cout<<i;
		}
	}
	return 0;
}
