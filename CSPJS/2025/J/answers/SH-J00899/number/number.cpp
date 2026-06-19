#include <bits\stdc++.h>
using namespace std;
const int N=1e6+10;
string a,c;
int b[N];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int cnt=0;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[i]=a[i]-'0';
			cnt++;
		}
	}
	sort(b,b+a.size(),cmp);
	for(int i=0;i<cnt;i++){
		c+=b[i]+'0';
	}
	cout<<c;
	return 0;
} 
