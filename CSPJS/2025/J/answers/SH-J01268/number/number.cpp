#include <bits/stdc++.h>
using namespace std;

int a[1000010];

int main(){
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	
	string s;
	cin >> s;
	int l=s.size();
	int cnt=1;
	for (int i=0;i<l;i++){
		if ('a'<=s[i]&&s[i]<='z'){
			continue;
		}
		else{
			a[cnt]=int(s[i])-48;
			cnt++;
		}
	}
	sort(a+1,a+cnt);
	for (int i=cnt-1;i>=1;i--){
		cout << a[i];
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
