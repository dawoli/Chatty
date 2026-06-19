#include<bits/stdc++.h>

using namespace std;

string s;
string arr[100005];
string str[100005];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	
	if(s.length() == 1){
		cout << s;
		return 0;
	}
	
	int cnt = 0;
	for(int i = 0;i < s.length();i++){
		str[i] = s[i];
//		cout << str[i] <<" ";

		if(str[i] <= "9" && str[i] >= "0"){	
			arr[i] = str[i];
//			cout << arr[i] << " " << endl;
			cnt+=1;
		}
//		cout << arr[i];
	}
	int a = s.length();
	sort(arr,arr+a);
	for(int j = s.length();j >= 0;j--){
		cout << arr[j];
	}
	return 0;
} 









