#include<bits/stdc++.h>
using namespace std;
int n,m,b[10000000],na[100000],count1,count2,count3,shun[10000],flag[100000],first;
string str;
void dfs(int k){
	if(count2>n-m+1){
		return;
	}
	if(k>n){
		count3++;
		return ;
	}
	if(na[k-1]==1&&shun[k]<count2){
		count1++;
		dfs(k+1);
	}else{
		count2++;
		dfs(k+1);
	}
}
void dfs2(int count4){
	if(count4>n){
		count1=0;
		count2=0;
		for(int i=1;i<n;i++){
			if(shun[i]==shun[i+1]){
				if(first==0){
					first=1;
					return;
				}
				else{
					first=0;
					break;
				}
			}
		}
		dfs(1);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(flag[i]==1)continue;
		flag[i]=1;
		shun[count4]=b[i];
		dfs2(count4+1);
		flag[i]=0;
	}
}
int main(){
    freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>str;
	for(int i=0;i<str.size();i++){
		na[i]=str[i]-'0';
	}

	for(int i=1;i<=n;i++){
		cin>>b[i];
	} 
	dfs2(1);
	cout<<count3;
	fclose(stdin);
	fclose(stdout);
	return 0;
	
}

//10
//5
//1101111011
//6 0 4 2 1 2 5 4 3 3
