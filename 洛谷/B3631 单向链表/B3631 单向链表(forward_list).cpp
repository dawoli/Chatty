//B3631 单向链表
#include<bits/stdc++.h>
using namespace std;
forward_list<int> lt(1,1);
int q,a,x,y;
void put(int x,int y)
{
	auto it=find(lt.begin(), lt.end(),x);
	if(it!=lt.end())lt.insert_after(it,y);
	//cout<<1<<endl;
}
void ask(int x)
{
	auto it=find(lt.begin(),lt.end(),x);
	if(it!=lt.end())
	{
		if(++it==lt.end())cout<<0<<endl;
		else cout<<*it<<endl;
	}
	//cout<<2<<endl;
}
void cut(int x)
{
	auto it=find(lt.begin(),lt.end(),x);
	if(it!=lt.end())lt.erase_after(it);
	//cout<<3<<endl;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>q;
	for(int i=1;i<=q;i++)
	{
		cin>>a;
		if(a==1){
			cin>>x>>y;
			//cout<<'a'<<endl;
			put(x,y);
		}
		if(a==2)
		{
			cin>>x;
			//cout<<'b'<<endl;
			ask(x);
		}
		if(a==3)//写成else导致代码崩溃？？？:(
		{
			cin>>x;
			//cout<<'c'<<endl;
			cut(x);
		}
	}
	return 0;
}
