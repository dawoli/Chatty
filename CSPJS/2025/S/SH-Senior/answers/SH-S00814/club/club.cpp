#include<iostream> 
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<stdio.h>
#include<ctime>
#include<map>  
#include<bits/stdc++.h>
using namespace std;
int t,n;
int a[10005][10005],soa,sob,soc;
int ans,ansfinal;
int man;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	cin>>n;
	for(int i=1;i<=t;i++){//有多少组数据（每组数据上的小数字） 
		for(int j=1;j<=n;j++){//每个小数字下有多少行数据 
			cin>>soa>>sob>>soc;
			int delta=(soa+sob+soc)/2;
			for(int k=1;k<=n;k++){//枚举行数次每行的最大值，记为ans，要求所有ans的和 
				int dam=max(soa,sob);
				int dan=max(sob,soc);
				man=max(dam,dan);
				ans+=man;
				ansfinal=ans/n;
			}
		}
		cout<<ansfinal<<endl;
	}
	return 0;
} 
//老师好 
