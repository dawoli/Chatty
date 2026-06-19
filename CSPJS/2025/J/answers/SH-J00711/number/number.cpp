#include<bits/stdc++.h>
using namespace std;
string s;
long long a;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	a=s.length();
	int b[1000005],count=0;
	for(int i=0;i<a;i++){
		if(s[i]>='0'&&s[i]<='9'){
			b[count]=int(s[i]-'0');
			count++;
		}
	}
	for(int i=0;i<count;i++){
		for(int j=i+1;j<count;j++){
			if(b[j]>b[i])swap(b[i],b[j]);
		}
	}
	for(int i=0;i<count;i++)cout<<b[i];
	cout<<endl;
	return 0;
}
