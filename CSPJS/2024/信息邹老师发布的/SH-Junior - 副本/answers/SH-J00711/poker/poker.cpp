#include <cstdio>
#include <algorithm>
using namespace std;

struct node{
	char a,b;
	bool operator<(const node& x)const{
		if(a==x.a)return b<x.b;
		return a<x.a;
	}
	bool operator==(const node& x)const{
		return a==x.a&&b==x.b;
	}
}a[100];

int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++){
		char s[10];scanf("%s",s);
		a[i].a=s[0],a[i].b=s[1];
	}
	sort(a+1,a+1+n);
	int x=unique(a+1,a+1+n)-a-1;
	printf("%d\n",52-x);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
