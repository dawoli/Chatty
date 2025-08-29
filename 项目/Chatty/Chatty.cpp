#include<iostream>
#include<string>
#include<random>
#include"Chatty_private.h"
using namespace std;
string s;
int x;
int random(int upr)
{
	srand(time(NULL));
	return rand()%upr+1;
}//upr=upper_range
int main()
{
	cout<<"Chatty1.0.0.0E - Your Personal Therapist\n";
	cout<<"Developed by dawoli\n";
	cout<<"Hello!This is the English version of Chatty.\n";
	cout<<"What can you do with Chatty?\n";
	cout<<"Chatty can listen to your emotions,and help you get out of your emotional storm.\n";
	cout<<"Please talk with me with short coversational sentences but NOT questions.\n";
	cout<<"If you want to stop chatting with me,please type in -1.\n";
	cout<<"Now you can start chatting with me!\n";
	while(1)
	{
		cout<<"User:";
		getline(cin,s);
		cout<<"Chatty:";
		if(s=="-1")
		{
			cout<<"Bye!";
			return 0;
		}
		if(s.find("happy")!=string::npos)
		{
			x=random(4);
			switch (x) 
			{
			case 1:
				cout<<"You feel happy,that makes me happy too.Please go on.\n";
				break;
			case 2:
				cout<<"Your happiness is my biggest goal.I'd like to hear that.\n";
				break;
			case 3:
				cout<<"I would like to hear that you are happy!\n";
				break;
			case 4:
				cout<<"I hope you'll be happy every day!\n";
				break;
			default:
				cout<<"It's good to hear you are happy.Please go on.\n";
				break;
			};
		}
		else if(s.find("sad")!=string::npos)
		{
			x=random(4);
			switch (x) 
			{
			case 1:
				cout<<"You feel sad,that makes me sad too.I hope you'll be better.\n";
				break;
			case 2:
				cout<<"Your sadness will go away soon enough,cheer up!\n";
				break;
			case 3:
				cout<<"I'll cure your sadness as soon as I can!\n";
				break;
			case 4:
				cout<<"I hope your sadness will fly away like a cloud.\n";
				break;
			default:
				cout<<"It's sad to hear about your sadness.\n";
				break;
			};
		}
		else if(s.find("angry")!=string::npos)
		{
			x=random(4);
			switch (x) 
			{
			case 1:
				cout<<"Please calm down!Your angriness will go away soon enough!\n";
				break;
			case 2:
				cout<<"I'll help you go out of your angriness!Please go on.\n";
				break;
			case 3:
				cout<<"You're angry,that makes me sad.Please go on.\n";
				break;
			case 4:
				cout<<"Your angriness will go away soon!Please go on.\n";
				break;
			default:
				cout<<"It's sad to hear you are angry.Please go on.\n";
				break;
			};
		}
		else
		{
			x=random(4);
			switch (x) 
			{
			case 1:
				cout<<"I'm into you words.Please go on.\n";
				break;
			case 2:
				cout<<"Your chat is interesting.Please go on.\n";
				break;
			case 3:
				cout<<"I like to chat with you.Please go on.\n";
				break;
			case 4:
				cout<<"I hope to hear more of your words.Please go on.\n";
				break;
			default:
				cout<<"It's good to hear you words.Please go on.\n";
				break;
			};
		}			
	}
}
