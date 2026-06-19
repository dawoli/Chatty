#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string s;
int a[1000010];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int x=1,len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[x]=s[i]-'0';
			x++;
		}
	}
	x--;
	sort(a+1,a+x+1);
	for(int i=x;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
