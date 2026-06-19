#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	char a[1000001];int cnt=0;
	int l=s.size();
	for (int i=0;i<l;i++){
		if (s[i]>='0' && s[i]<='9'){
			cnt+=1;
			a[cnt]=s[i];
		} 
	}
	sort(a+1,a+cnt+1);
	for (int i=cnt;i>=1;i--){
		cout<<(int(a[i])-48);
	}
	return 0;
}
