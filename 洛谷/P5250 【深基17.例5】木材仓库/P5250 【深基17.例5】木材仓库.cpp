#include<bits/stdc++.h>
using namespace std;
int m,x,y;
set<int> s;
int main()
{
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y;
		if(x==1)
		{
			bool flag=s.insert(y).second;
			if(!flag)cout<<"Already Exist"<<endl;
		}
		if(x==2)
		{
			if(s.empty())cout<<"Empty"<<endl;
			else if(s.erase(y))cout<<y<<endl;
			else
			{
				auto it=s.insert(y).first,up=it,down=it;
				bool u=0,d=0;
				if(it!=(--s.end()))
				{
					up=++it;
					it--;
					u=1;
				}
				if(it!=(s.begin()))
				{
					down=--it;
					it++;
					d=1;
				}
				if(u==1&&d==0)
				{
					cout<<*up<<endl;
					s.erase(up);
				}
				else if(u==0&&d==1)
				{
					cout<<*down<<endl;
					s.erase(down);
				}
				else 
				{
					if(*it-*down<=*up-*it)
					{
						cout<<*down<<endl;
						s.erase(down);
					}
					else
					{
						cout<<*up<<endl;
						s.erase(up);
					}
				}
				s.erase(it);
			}
		}
	}
	return 0;
}