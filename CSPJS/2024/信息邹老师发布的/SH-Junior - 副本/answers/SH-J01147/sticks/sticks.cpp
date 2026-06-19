#include<bits/stdc++.h>
std::ifstream fin("sticks.in");
std::ofstream fout("sticks.out");
int pos;
std::string dfs(int n,bool a,std::string s){
	if(n==0){
		return s;
	}
	else if(n==1){
		return s+s;
	}
	else if(n==2){
		return s+'1';
	}
	else if(n==3){
		return s+'7';
	}
	else if(n==4){
		return s+'4';
	}
	else if(n==5){
		return s+'2';
	}
	else if(n==6){
		return s+'6';
	}
	else if(n==7){
		return s+'8';
	}
	if(a==1){
		if(n==6){
			return dfs(n-6,0,"6");
		}
		else if(n>=5){
			return dfs(n-5,0,"2");
		}
		else if(n==4){
			return dfs(n-4,0,"4");
		}
		else if(n==3){
			return dfs(n-3,0,"7");
		}
		else if(n==2){
			return dfs(n-2,0,"1");
		}
	}
	else if(a==0){
		if(n==7){
			return dfs(n-7,0,s+'8');
		}
		else if(n>=6){
			return dfs(n-6,0,s+'0');
		}
		else if(n==5){
			return dfs(n-5,0,s+'2');
		}
		else if(n==4){
			return dfs(n-4,0,s+'4');
		}
		else if(n==3){
			return dfs(n-3,0,s+'7');
		}
		else if(n==2){
			return dfs(n-2,0,s+'1');
		}
	}
}
int main(){
	fin>>pos;
	for(int i=1;i<=pos;i++){
		int n;
		fin>>n;
		if(n==1){
			fout<<"-1"<<"\n";
			continue;
		}
		std::string s=dfs(n,1,"");
		for(int i=0;i<s.size();i++){
			int a=s[i]-'0';
			fout<<a;
		}
		fout<<"\n";
	}
//std::cout<<dfs(18,1,"");
	return 0;
}
