#include<bits/stdc++.h>
using namespace std;
int t,n,s,o;
//t组数据,n根火柴棒（会变）,结合数字位数s（需更新）,满足要求数字个数o（需更新） 
bool flag=false;
int need[14]={6,2,5,5,4,5,6,3,7,6};
int p_l[1555885];//存储数字的每个位
int c_l[1555885];//存储全部满足要求的数字 
int changenum(int s){
	int sum=0;
	for(int i=0;i<s;i++){
	    sum+=p_l[i]*pow(10,i);
	} 
	return sum;
}
void dfs(int n,int s){
    if(n==0 && p_l[s-1]!=0){
		c_l[o++]=changenum(s);
	    flag=true;
	    return ;
	}
	for(int i=0;i<10;i++){
		if(need[i]<=n){
			p_l[s]=i;
			dfs(n-need[i],s+1);
		}
	}
	return ;
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
    	cin>>n;
    	dfs(n,s);
    	if(!flag){
    		cout<<-1<<endl;
    		continue;
		}
		sort(c_l,c_l+o);
		cout<<c_l[0]<<endl;
		s=0,o=0;flag=false;
	}
	fclose(stdin);
	fclose(stdout);
    return 0;
}

