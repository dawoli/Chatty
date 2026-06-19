#include<bits/stdc++.h>
using namespace std;
void read(int &x){
	x^=x;
	int f=1;
	char a=getchar();
	while('0'>a||a>'9'){
		if(a=='-')f=-1;
		a=getchar();
	}
	while('0'<=a&&a<='9'){
		x*=10;
		x+=a-'0';
		a=getchar();
	}
	x*=f;
	return ;
}

const int SIZE=100009;
int n,r[SIZE],sum,ans;
set<int>type;
map<int,int>cnt;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	read(n);
	int i,temp;
	for(i=1;i<=n;i++){
		read(temp); 
		type.insert(temp);
		cnt[temp]++;
	}
	set<int>::iterator it;
	for(it=type.begin();it!=type.end();it++){
		temp=cnt[*it];
		ans+=min(temp,sum);
		sum-=min(temp,sum);
		sum+=temp;
	}
	printf("%d",n-ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
