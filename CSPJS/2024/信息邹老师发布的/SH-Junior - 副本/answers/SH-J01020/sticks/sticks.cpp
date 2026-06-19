#include<bits/stdc++.h>
using namespace std;
string com(int n)
{
	string s;
	 if(n==1) return "-1";
	 if(n==2) return "1";
	 if(n==3) return "7";
	 if(n==4) return "4";
	 if(n==5) return "2";
	 if(n==6) return "6";
	 if(n%7==0)
	 {
	 	for(int i=1;i<=n/7;i++)
	 	{
		    s+="8";
		}
		return s; 
	 }
	 if(n%7==1)
	 {
	 	n-=8;
	 	s="10";
	 	for(int i=1;i<=n/7;i++)
	 	{
		    s+="8";
		}
		return s;
	 }
	 if(n%7==2)
	 {
	 	n-=2;
	 	s="1";
	 	for(int i=1;i<=n/7;i++)
	 	{
		    s+="8";
		}
		return s;
	 }
	 if(n%7==3)
	 {
	 	n-=10;
	 	s="22";
	 	for(int i=1;i<=n/7;i++)
	 	{
		    s+="8";
		}
		return s;
	 }
	if(n%7==4)
	 {
	 	n-=11;
	 	s="20";
	 	for(int i=1;i<=n/7;i++)
	 	{
		    s+="8";
		}
		return s;
	 } 
	 if(n%7==5)
	 {
	 	n-=5;
	 	s="2";
	 	for(int i=1;i<=n/7;i++)
	 	{
		    s+="8";
		}
		return s;
	 }
	 if(n%7==6)
	 {
	 	n-=6;
	 	s="6";
	 	for(int i=1;i<=n/7;i++)
	 	{
		    s+="8";
		}
		return s;
	 }
}
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	cin >> t;
	for(int i=1;i<=t;i++)
	{
		int n;
		cin >> n;
		cout << com(n) << endl;
	}
	return 0;
}
