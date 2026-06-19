#include<iostream>
#include<cstdio>
int a[100010];
int c[100010];
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	int n,m;
	std::cin>>n>>m;
	for(int i=1;i<=n;i++)std::cin>>a[i];
	for(int i=1;i<=m;i++)std::cin>>c[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
