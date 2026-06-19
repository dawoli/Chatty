//P5266 【深基17.例6】学籍管理
#include<bits/stdc++.h>
using namespace std;
unordered_map<string,int> a;
int n,x;
string name;
bool insert1(string name,int score)
{
	a[name]=score;
	cout<<"OK"<<endl;
	return 1;
}
bool search2(string name)
{
	if(a.find(name)!=a.cend())
	{
		cout<<a[name]<<endl;
		return 1;
	}
	else 
	{
		cout<<"Not found"<<endl;
		return 0;
	}
}
bool delete3(string name)
{
	if(a.erase(name)==1)
	{
		cout<<"Deleted successfully"<<endl;
		return 1;
	}
	else
	{
		cout<<"Not found"<<endl;
		return 0;
	}
}
bool count4()
{
	cout<<a.size()<<endl;
	return 1;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		switch(x)
		{
		case 1:{cin>>name>>x;insert1(name,x);break;}
		case 2:{cin>>name;search2(name);break;}
		case 3:{cin>>name;delete3(name);break;}
		case 4:{count4();break;}
		}
	}
	return 0;
}
