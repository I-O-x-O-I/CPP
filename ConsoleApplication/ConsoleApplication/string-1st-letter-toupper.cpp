#include <iostream>
#include <string>

using namespace std;


int main()
{
	// 数组形式把 string 首字母 大写

	string s = "helloWorld";

	//// 迭代器形式
	//if (s.begin() != s.end())
	//{
	//	string::iterator it = s.begin();
	//	*it = toupper(*it);

	//}


	// at

	//s.at(0) = toupper(s.at(0));


	// 下标
	//s[0] = toupper(s[0]);

	//s.front() = toupper(s.front());


	// 迭代器 begin
	*s.begin() = toupper(*s.begin());





	cout << "Toupper : " << s << endl;


}