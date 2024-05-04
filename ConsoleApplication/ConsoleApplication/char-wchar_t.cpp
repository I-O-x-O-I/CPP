#include <iostream>
#include <tchar.h>

using namespace std;

int main()
{
	// 当前工程 C++语言标准：C++ 20
	// 当前文档编码：（GB2312） CodePage 936






	// char <==> wchar_t
	// C 风格跨平台的 多字节字符序列 转 宽字节字符序列
	
	{
		cout << "多 转 宽.................................." << endl;

		// 字符串定义的两种形式
		const char* ch1 = "我爱你老婆666abc";
		char cstr2[256] = "我爱你老婆666abc";			// 若形如 char ch[] = "我爱你老婆666abc"; 那么未确定的字符数组数量由后面的字符串来确定，最终值加\0即为17。

		cout << "多字节，显示：" << cstr2 << endl;
		cout << "多字节，字符数组空间大小：" << sizeof(cstr2) << endl;					// sizeof() 运算符。	获取整个 字符数组 的空间长度。	值：256。	不受 字符串 “我爱你老婆” 实际长度限制。
		cout << "多字节，指针大小：" << sizeof(ch1) << endl;				// x86=4，x64=8
		cout << "多字节，实际字符数长度：" << strlen(cstr2) << "。不包括结束符中文一个汉字等于2个字节，共16个" << endl;					// strlen() 函数。	获取整个 字符数组 的内容长度。	值：16。		不包括结束符\0，中文一个汉字占用2个字节。
		cout << endl;

		cout << "多 转 宽   转换后......" << endl;
		cout << endl;

		wchar_t* wcstr = new wchar_t[strlen(cstr2) + 1];		// 真正的 C 风格是 (wchar_t*) malloc( pReturnValue *sizeof(wchar_t));

		// 问：为什么 wcstombs_s 就需要两次调用呢？
		// 答：宽转多的时候，宽字节缓冲区的有些内容是在多字节缓冲区本身就要以2个字节存在的。不能单一的以内容字符的长度来衡量实际需要的字节数。但多字节转宽字节就容易多了。因为每个字符最终都是以2倍增长的。

		// mbstowcs_s 函数介绍
		// 参数 1：_PtNumOfCharConverted， 不是必须的。如果成功转换了源字符串，它会将转换的字符串（包括终止符）的大小（以宽字符为单位）放入 *pReturnValue（假定 pReturnValue 不是 NULL）。是NULL，那就是不需要返回值
		// 参数 2：_DstBuf，也不是必须的。倘若只需要返回 _PtNumOfCharConverted 被转换的字符数，那么_DstBuf可以为NULL，配合_SizeInWords = 0，MaxCount = 0。
		// 参数 3：_SizeInWords，要注意的是，该值是 Word 的数量，Word 是 字，不是字节，也不是 DWord 双字。可以在此看出，宽字节表示认为 一个 Word（一个字）为基本数据单位。此处一个Word = 2个字节。此值也就是 wcstr 的以宽字节单位的长度。
		// 参数 4：_SrcBuf，必须的。
		// 参数 5：_MaxCount，要存储在 wcstr 中的宽字符的最大数量，不含终止符。只在需要转换一部分字符的时候才有实际意义。不然就一直是 strlen(_SrcBuf)

		mbstowcs_s(NULL, wcstr, (strlen(cstr2) + 1), cstr2, 16);

		wcout << "宽字节，显示：" << wcstr << endl;
		wcout << "宽字节，字符数组空间大小：" << sizeof(wchar_t) * wcslen(wcstr) << "。不包括结束符16 * 2" << endl;

		const wchar_t* fs = L"大家好";
		wcout << "宽字节显示：" << sizeof(fs) << endl;
		delete[] wcstr;
	}
	

	// C 风格跨平台的 宽字节字符序列 转 多字节字符序列
	 {
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << "宽 转 多.................................." << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;

		// 注意：如果不设置 setlocale/_wsetlocale/_tsetlocale 为 ""，wcout会不能正常显示
		// 更过 locale 内容参考：https://learn.microsoft.com/zh-cn/cpp/c-runtime-library/reference/setlocale-wsetlocale?view=msvc-170
		// 核心参考 0： setlocale(LC_ALL, "C")			程序启动时，相当于默认操作了该行为
		// 核心参考 1： setlocale(LC_ALL, NULL)			会返回当前区域设置
		// 核心参考 2： setlocale(LC_ALL, "")				将区域设置设为默认值，该值是从操作系统获取的用户默认的ANSI代码页。个人理解：【英文系统 + 不支持的Unicode 以中文显示】就会以英文ANSI为主，GBK配合为辅的默认形式。
		// 核心参考 3： setlocale(LC_ALL, "en_US")		微软推荐的形式。为指定的语言使用默认了国家/地区。
		// 核心参考 4： setlocale(LC_ALL, "en_US.UTF8)	支持UTF8，连字符( - )可选。即 UTF8 = UTF-8。

		//setlocale(LC_ALL, "");			// 单字节版本
		//_wsetlocale(LC_ALL, L"");		// 宽字节版本
		_tsetlocale(LC_ALL, _T(""));	// 通用版本，需要 #include <tchar.h>

		// 两种形式
		const wchar_t* wcstr1 = L"我爱你老婆ddd666";
		wchar_t wcstr2[256] = L"我爱你老婆666eee";

		wcout << wcstr2 << endl;

		wcout << endl;
		wcout << L"多 转 宽 转换中............." << endl;
		wcout << endl;


		// 问：为什么 宽字节 转 多字节 就需要两次 wcstombs_s 呢？
		// 答：如果只用一次 wcstombs_s，就没办法准确计算需要的 多字节 缓冲区大小。 毕竟中文是一个汉字占用 2 个字节的。如果是全英文数字，那么只用一次函数就可以了。

			// 计算需要的真实字节数量
			size_t pReturnValue;					// 不能使用 int型， wcstombs_s 函数无法通过。
			wcstombs_s(&pReturnValue, NULL, 0, wcstr2, 0);

			// 建立足够字节的缓冲区，开始转换
			char* cstr = new char[pReturnValue];

			// wcstombs_s 函数介绍
			// 参数 1：_PtNumOfCharConverted。在宽字节中有中文的情况下，此值必须返回，才能获取准确的需要转换后的字节空间大小。
			// 参数 2：_Dst。多字节缓冲区
			// 参数 3：_DstSizeInBytes。注意单位是 Byte 字节。
			// 参数 4：_Src。源宽字节
			// 参数 5：_MaxCountInBytes。存储在多字节缓冲区中的实际内容的字节长度。不用带终止符。
			wcstombs_s(NULL, cstr, pReturnValue, wcstr2, pReturnValue - 1);


		cout << "单字节字符序列，显示：" << cstr << endl;
		delete[] cstr;

	}
	

	return 0;
}