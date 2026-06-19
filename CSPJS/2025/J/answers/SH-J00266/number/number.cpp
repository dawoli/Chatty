#include<bits/stdc++.h>
//pwd #Shang4Shan3Ruo6Shui4
using namespace std;
int a[1000005],cnt = 0;
int main(){
	ifstream fin("number.in");
	ofstream fout("number.out");
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	string s,ans = "";
	fin>>s;
	for(int i = 0; i < s.size();++i){
		if('0'<=s[i]&&s[i]<='9'){
			a[cnt] = s[i]-'0';
			cnt+=1;		
		}

	}
	sort(a,a+cnt);
	if(a[cnt-1] == 0){
		fout<<0;
		return 0;
	}
	for(int i = cnt-1; i >=0 ; --i){
		fout<<char(a[i]+'0');
	}
	return 0;
}
