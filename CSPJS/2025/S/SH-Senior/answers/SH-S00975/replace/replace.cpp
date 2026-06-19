#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

vector <string> different(string str1,string str2){
	int l,r;
	for(l=0;str1[l]==str2[l];l++)
	for(r=str1.size()-1;str1[r]==str2[r];r--)
    string ans1="",ans2="";
    for(int i=l;i<=r;i++){
    	ans1+=str1[i];
    	ans2+=str2[i];
	}
	return {ans1,ans2};
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);

	int n,q;
	cin >> n >> q;
	string s[n][2],t[q][2];
	for(int i=0;i<n;i++){
		cin >> s[i][0] >> s[i][1];
	}
	for(int i=0;i<q;i++){
		cin >> t[i][0] >> t[i][1];
	}
	for(int i=0;i<q;i++){
		int count=0;
		vector <string> dif=different(t[i][0],t[i][1]);
		
		for(int j=0;j<n;j++){
			if(dif==different(s[j][0],s[j][1]) && t[i][0].find(s[j][0])!=-1 && t[i][1].find(s[j][1])!=-1){
				count++;
			}
		}
		
		cout<<count<<endl;
	}
		
	fclose(stdin);
	fclose(stdout);
	return 0;
}
