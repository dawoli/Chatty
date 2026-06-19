#include<bits/stdc++.h>
using namespace std;
int f[20];//最大1e6 
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string s;
	cin >> s;
	//输入
	 
	for(int i=0;i<s.size();i++){//遍历每个字符 
		if(s[i]>='0' && s[i]<='9'){ //当前字符为数字 
			f[s[i]-'0']++;//字符所对应数字+1 "0"->0 
		}
	} 
	//找数字并统计个数 
	 
	for(int i=9;i>=0;i--){ ////按9876543210顺序  
		for(int j=1;j<=f[i];j++){ //按统计个数输出 
			cout << i;
		}
	}
	//时间复杂度最大1e6 
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
