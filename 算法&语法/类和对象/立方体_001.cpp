#include<iostream>
using namespace std;
class Box
{
public:
	double m_a;
	void SetA(double);
	double GetVolume();
	double GetArea();
	void Display();
};

void Box::SetA(double x)
{
	m_a = x;
}

double Box::GetVolume()
{
	return m_a * m_a * m_a;
}

double Box::GetArea()
{
	return m_a * m_a * 6;
}

void Box::Display()
{
	cout << "体积：" << this->GetVolume() << "面积：" << this->GetArea() << endl;
}
int main()
{
	double a;
	cin >> a;
	Box object1;
	object1.SetA(a);
	object1.Display();
	return 0;
}
