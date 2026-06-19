#include<bits/stdc++.h>
using namespace std;
int a[15];
string s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	cin >> s;
	for(int i = 0; i < s.size(); i++)
	{
		if(s[i] <= '9' && '0' <= s[i])
			a[s[i] - '0']++;
	}
	for(int i = 9; i >= 0; i--)
		while(a[i]--)
			cout << i;
	/*
	庆历四年春，滕子京谪守巴陵郡，越明年，政通人和，百废俱兴，乃重修岳阳楼，增其旧制，刻唐贤今人诗赋于其上，属予作文以记之。
	予观夫巴陵盛状，在洞庭一湖，衔远山，吞长江，浩浩汤汤，横无际涯，朝晖夕阴，气象万千，此则岳阳楼之大观也。前人之述备矣，然则北通巫峡，南极潇湘，迁客骚人，多会于此，览物之情，得无异乎？
	若夫淫雨霏霏，连月不开，阴风怒号，浊浪排空，日星隐曜，山岳潜形，商旅不行，樯倾楫摧，薄暮冥冥，虎啸猿啼。登斯楼也，则有去国怀乡，忧谗畏讥，满目萧然，感极而悲者矣。 
	*/
	return 0;
}
