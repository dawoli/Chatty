#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	int num=0;
	vector<char> a(s.size(),0);
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			num++;
			a[i]=s[i];
		}
	}
	sort(a.begin(),a.end(),greater<int>());
	for(int i=0;i<num;i++){
		cout << a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
