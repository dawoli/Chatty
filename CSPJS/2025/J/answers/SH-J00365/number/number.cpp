#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
string s;
int a[N],k;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&& s[i]<='9'){
			a[k]=int(s[i]-'0');
			k++;
		}
	}
	sort(a,a+k);
	for(int i=k-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
} -
