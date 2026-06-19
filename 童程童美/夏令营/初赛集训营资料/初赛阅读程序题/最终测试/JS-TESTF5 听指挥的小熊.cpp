#include <iostream>
using namespace std;
char dir[]="ENWS";
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
int main()
{
	string s; cin>>s;
	int x=0,y=0,k=0;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='#') break;
		if(s[i]>='a'&&s[i]<='z') s[i]-=32;
		if(s[i]=='F') ;
		else if(s[i]=='L') k++;
		else if(s[i]=='R') k--;
		else continue;
		k=(k+4)%4;
		x+=dx[k];
		y+=dy[k];
	}
    printf("(%d,%d)\n%c\n",x,y,dir[k]);
	return 0;
}

