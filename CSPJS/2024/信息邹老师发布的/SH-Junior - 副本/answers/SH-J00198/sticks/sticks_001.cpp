#include<bits/stdc++.h>
using namespace std;
int t;
int n;
struct Node{
	int a;
	int b;
}st[10];
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	st[1].a=0,st[1].b=6;
	st[2].a=1,st[2].b=2;
	st[3].a=2,st[3].b=5;
	st[4].a=4,st[4].b=4;
	st[5].a=6,st[5].b=6;
	st[6].a=7,st[6].b=3;
	st[7].a=8,st[7].b=7;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int flag=0;
		cin>>n;
		if(n%7==0)
		{
			for(int i=1;i<=n/7;i++)
			{
				cout<<'8';
			}
			flag=1;
			cout<<endl;
		}
		else if(n<=7){
			for(int j=2;j<=7;j++){
				if(st[j].b==n){
					cout<<st[j].a;
					flag=1;
					break;
				}
			}
		}
		else if(n>7 && n<=14){
			for(int j=2;j<=7;j++){
				for(int k=1;k<=7;k++){
					if((st[j].b+st[k].b)==n){
						if(flag==0)	{
							cout<<st[j].a<<st[k].a;
							flag=1;
							break;
						}	
					}
				}	
			}
		}
		else if(n>14 && n<=21){
			for(int j=2;j<=7;j++){
				for(int k=1;k<=7;k++){
					for(int w=1;w<=7;w++){
						if((st[j].b+st[k].b+st[w].b)==n){
							if(flag==0){
								cout<<st[j].a<<st[k].a<<st[w].a;
								flag=1;
								break;
							}
						}
					}
				}	
			}
		}
		else if(n>21 && n<=28){
			for(int j=2;j<=7;j++){
				for(int k=1;k<=7;k++){
					for(int w=1;w<=7;w++){
						for(int e=1;e<=7;e++){
							if((st[j].b+st[k].b+st[w].b+st[e].b)==n){
								if(flag==0){
									cout<<st[j].a<<st[k].a<<st[w].a<<st[e].a;
									flag=1;
									break;
								}
							}
						}
					}
				}	
			}
		}
		if(flag==0)
			cout<<"-1"<<endl;
	}
	return 0;
}
