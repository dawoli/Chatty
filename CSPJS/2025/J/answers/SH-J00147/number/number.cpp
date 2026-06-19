#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int cnt=0;
	int q=s.size();
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[i]=int(s[i]-48);
			cnt++;
		}
	}
	sort(a,a+q,cmp);
	for(int i=0;i<cnt;i++){
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
