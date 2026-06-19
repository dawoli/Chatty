#include<bits/stdc++.h>
using namespace std;
ifstream fin("employ.in");
ofstream fout("employ.out");
int n,m,c[505],cnt,flag;
string s; 
long long pl=1;
int main(){
	fin>>n>>m;
	for(int i=1;i<=n;i++){
		fin>>c[i]; 
		if(c[i]==0)cnt++;
	}
	fin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0')flag++;
	}
	//cout<<flag<<endl<<"cnt"<<cnt<<endl;
	if(!flag){
		for(int i=n;i>0;i--){
	    	pl*=i;
	    	pl%=998,244,353;
	    	//cout<<pl<<" ";
		}
		
	}
	else{
	    if(n-flag<=m||n-cnt<=m)pl=0;
	    else pl=10;
	}
	fout<<pl;
	return 0;
}
