#include <iostream>
#include <algorithm>
using namespace std;

int cnt=0;
int a[1000005]; 
string s;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.length();
	for(int i=0;i<n;i++){
		if(s[i]<='9'&&s[i]>=0){
			a[cnt]=s[i]-'0';
			cnt++;
		} 
	}
	sort(a,a+cnt,cmp);
	for(int i=0;i<cnt;i++){
		cout<<a[i]; 
	}
	cout<<endl;
	return 0;
}
