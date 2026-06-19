#include<bits/stdc++.h>
using namespace std;
#define N 100001
typedef long long LL;
LL a[N],maxn=0;
string f[N]={"-1","1","1","7","4","2","6","8","16","18","22","20","28","68","88",
			"108","188","228","268","288","688"};
//f[i]:使用i根木棍能拼出的最小数(使各位数字的和最小） 
void solve(LL x){	//输入最大的n设为x 
	for(LL i=21;i<=x;i++){
		int modx=i%7;
		if(modx==0){		//首位为8
			f[i]="8"+f[i-7]; 
		}else if(modx<=2){	//首位为1 
			f[i]="1"+f[i-2];
		}else if(modx<=5){	//首位为2 
			f[i]="2"+f[i-5];
		}else{				//首位为6 
			f[i]="6"+f[i-6];
		}
	}
}
string erase0(string x){	//将所有非前导6转换为0 
	for(int i=1;i<x.length();i++){
		if(x[i]=='6') x[i]='0';
	}
	return x;
}

int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T; cin>>T;
	for(int i=1;i<=T;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	solve(maxn);
	for(int i=1;i<=T;i++){
		if(a[i]==1){	//特判 
			cout<<-1<<endl;
		}else cout<<erase0(f[a[i]])<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
8
1
2
3
6
18
23
25
8
*/
