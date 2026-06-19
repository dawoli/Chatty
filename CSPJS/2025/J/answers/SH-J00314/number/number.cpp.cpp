#include<bits/stdc++.h>
using namespace std;
int a[1000005],cnta=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		int aa=s[i]-'0';
		if(aa>=0&&aa<=9){
			a[cnta]=aa;
			cnta++;
		}
	}
	sort(a+1,a+cnta);
	for(int i=cnta-1;i>=1;i--){
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
