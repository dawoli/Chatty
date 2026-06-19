#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string s;
int a[N];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freeopen("number.in","r",stdin);
	freeopen("number.out","w",stdout);
	cin>>s;
	int l=s.length(),cnt=1;
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[cnt++]=s[i]-'0';
		}
	}
	sort(a+1,a+cnt,cmp);
	for(int i=1;i<cnt;i++){
		cout<<a[i];
	}
	cout<<endl;
	return 0;
}
