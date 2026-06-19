#include<bits/stdc++.h>
using namespace std;
#define N 1000005
string s;
char num[N];
int l;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			num[++l]=s[i];
		}
	}
	sort(num+1,num+l+1);
	for(int i=l;i>=1;i--){
		cout<<num[i];
	}
	return 0;
}
