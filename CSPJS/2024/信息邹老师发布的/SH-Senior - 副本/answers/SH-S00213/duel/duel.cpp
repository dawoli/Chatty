#include<bits/stdc++.h>
using namespace std;

int n;

struct R{
	int r;
	bool used;
}r[100002];

bool c(R a,R b){
	return a.r<b.r;
}

int main(){
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	scanf("%d", &n);
	for(int i=1;i<=n;i++)
		scanf("%d", &r[i].r);
	sort(r+1,r+n+1,c);
	int head=1;
	bool flag=0;
	int place = head;
	do{
		flag = 0;
		for(int i=place+1;i<=n;i++){
			if(r[i].r>r[head].r && !r[i].used){
				r[i].used=true;
				head++;
				flag = 1;
				place = i;
				break;
			}
		}
	}while(flag);
	int num=n-head+1;
	printf("%d", num);
	return 0;
} 
