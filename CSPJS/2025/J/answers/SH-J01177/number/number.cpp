#include<bits/stdc++.h>
using namespace std;
const int N=1000009;
string s;
int n;
int a[N],cnt=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	for(int i=0;i<=n;i++){
		char c=s[i];
		if(c>='0'&&c<='9'){
			int num=c-'0';
			a[++cnt]=num;
		}
	}
	sort(a+1,a+cnt+1);
	for(int i=cnt;i;i--){
		cout<<a[i];
	}
	return 0;
}
