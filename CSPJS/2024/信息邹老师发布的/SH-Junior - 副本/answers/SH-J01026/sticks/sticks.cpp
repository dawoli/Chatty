#include<bits/stdc++.h> 
using namespace std;


int t;
int n;
int a[60];
int b[10]={6,2,5,5,4,5,6,3,7,6}; 
int k=0;
string sb="1088888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888";
int minn=INT_MAX;


void dfs(string temp,int nn){
	if(nn==0){
		if(temp[0]!='0'){
			if(atoi(temp.c_str())<minn){
				minn=atoi(temp.c_str());
				return;
			}
		}
	}
	if(nn>=7){
		dfs(temp+'0',nn-6);
		dfs(temp+'8',nn-6); 
	}
	else{
		for(int i=0;i<10;i++){
			if(nn>=b[i]){
				char tt=i+'0';
				string t=temp+tt;
				dfs(t,nn-b[i]);
			}
		}
	}
}


int main(){
	
	
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	
	
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		if(n==1){
			a[i]=-1;
			continue;
		}else{
			if(n%7==0){
				a[i]=atoi(sb.substr(2,n/7).c_str());
				continue;
			}
			else if(n%7==1){
				a[i]=atoi(sb.substr(0,n/7+1).c_str());
				continue;
			}
			dfs("",n);
			a[i]=minn;
			minn=INT_MAX;
		}
	}
	
	for(int i=0;i<t;i++){
		cout<<a[i]<<endl;
	}
	
	
	fclose(stdin);
	fclose(stdout);
	
	
	return 0;
}





