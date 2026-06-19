#include<bits/stdc++.h>
using namespace std;
int n[10000000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int num=0;
	string s;
	cin>>s;
	int l=s.size();
	for(int i=0;i<l;i++){
		if(s[i]>=48 and s[i]<=57){
			n[num]=s[i]-48;
			num++;
		}
	}
	sort(n,n+num);
	for(int i=num-1;i>=0;i--)cout<<n[i];
	return 0;
}

