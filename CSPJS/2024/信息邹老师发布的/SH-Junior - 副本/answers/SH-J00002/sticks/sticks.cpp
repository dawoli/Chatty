#include <bits/stdc++.h>
using namespace std;
//我勒个没想出来的坏深搜 稍微大点就过不了（求保佑ing 
//哈哈↑我样例终于改对了 但是n>=25的时候炸了 
long long ans[55];
int Q=1;
int p(int q,int d,long long num){
	if(q == 1){
	    return 100001;
	} else if(q == 2){
		d ++;
		num = num*10 + 1;
		q -= 2;
		return num;
	}else if(q == 3){
		d ++;
		num = num*10 + 7;
		q -= 3;
		return num;
	}else if(q == 4){
		d ++;
		num = num*10 + 4;
		q -= 4;
		return num;
	}else if(q == 5){
		d ++;
		num = num *10 + 2;
		q -= 5;
		return num;
	}else if(q == 6){
		d ++;
		if(d == 1){
			num = num * 10 + 6;
		}else{
			num *= 10;
		}
		q -= 6;
		return num;
	}else if(q == 7){
		d ++;
		num = num * 10 + 8; 
		q -= 7;
		return num;
	}else{
		long long n1=100001,n2=p(q-2,d+1,num*10+1),n3=p(q-5,d+1,num*10+2),n4=p(q-4,d+1,num*10+4),n5=p(q-6,d+1,num*10+6),n6=p(q-3,d+1,num*10+7),n7=p(q-7,d+1,num*10+8);
		if(d != 0) n1 = p(q-6,d+1,num*10);
		long long ans = min(n1,n2);
		ans = min(ans,n3);
		ans = min(ans,n4);
		ans = min(ans,n5);
		ans = min(ans,n6);
		ans = min(ans,n7); 
		if(ans == 100001 || ans == 0){
			return 100001; //-1?
	    }
		return ans;
	}	 
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T;
	cin>>T;
	for(int i=0;i<T;i++){
		bool fa=0;
		int f;
		cin>>f;
		if(f < 2){
		    ans[Q] = -1;
			fa = 1;
	    }
		long long anss = p(f,0,0);
		if((anss == 100001 || anss == 0) && fa != 1){  //-1?
			ans[Q] = -1;
			fa = 1;
	    }
		if(fa==0) ans[Q] = anss;
		anss = 0;
		Q ++;
	}
	for(int i=1;i<=T;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}
