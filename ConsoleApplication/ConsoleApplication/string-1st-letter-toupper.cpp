#include <iostream>
#include <string>

using namespace std;


int main()
{
	// ������ʽ�� string ����ĸ ��д

	string s = "helloWorld";

	//// ��������ʽ
	//if (s.begin() != s.end())
	//{
	//	string::iterator it = s.begin();
	//	*it = toupper(*it);

	//}


	// at

	//s.at(0) = toupper(s.at(0));


	// �±�
	//s[0] = toupper(s[0]);

	//s.front() = toupper(s.front());


	// ������ begin
	*s.begin() = toupper(*s.begin());





	cout << "Toupper : " << s << endl;


}