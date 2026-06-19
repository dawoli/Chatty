#include<bits/stdc++.h>

using namespace std;
string s;
int a[1000010];
bool cmp(int a,int b){
	return a>b;
}
 
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	//system("fc number4.txt number4ans.txt");
	cin>>s;
	//cout <<s;
	int j=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[j]=s[i]-'0';
			j++;
		}
	} 
	
	sort(a,a+j,cmp);
	for(int i=0;i<j;i++){
		cout<<a[i]; 
	}

	return 0;
} //#Shang4Shan3Ruo6Shui4
