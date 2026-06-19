#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 1e6 + 5;
int a[N],cur;

bool cmp(int x,int y)
{
	return x > y;
}

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	for(int i = 0;i < s.size();i++)
		if(s[i] >= '0' && s[i] <= '9')
			a[++cur] = s[i] - '0';
	sort(a + 1,a + cur + 1,cmp);
	for(int i = 1;i <= cur;i++) cout << a[i];
	return 0;
}

//若夫日出而林霏开，云归而岩穴暝，晦明变化者，山间之朝暮也。野芳发而幽香，佳木秀而繁阴，风霜高洁，水落而石出者，山间之四时也。朝而往，暮而归，四时之景不同，而乐亦无穷也，
