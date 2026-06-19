#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int sum=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			int op=s[i]-'0';
			sum++;
			a[sum]=op;
		}
	}
	sort(a+1,a+sum+1);
	for(int i=sum;i>=1;i--){
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
