#include <iostream>
#include <tchar.h>

using namespace std;

int main()
{
	// ��ǰ���� C++���Ա�׼��C++ 20
	// ��ǰ�ĵ����룺��GB2312�� CodePage 936






	// char <==> wchar_t
	// C ����ƽ̨�� ���ֽ��ַ����� ת ���ֽ��ַ�����
	
	{
		cout << "�� ת ��.................................." << endl;

		// �ַ��������������ʽ
		const char* ch1 = "�Ұ�������666abc";
		char cstr2[256] = "�Ұ�������666abc";			// ������ char ch[] = "�Ұ�������666abc"; ��ôδȷ�����ַ����������ɺ�����ַ�����ȷ��������ֵ��\0��Ϊ17��

		cout << "���ֽڣ���ʾ��" << cstr2 << endl;
		cout << "���ֽڣ��ַ�����ռ��С��" << sizeof(cstr2) << endl;					// sizeof() �������	��ȡ���� �ַ����� �Ŀռ䳤�ȡ�	ֵ��256��	���� �ַ��� ���Ұ������š� ʵ�ʳ������ơ�
		cout << "���ֽڣ�ָ���С��" << sizeof(ch1) << endl;				// x86=4��x64=8
		cout << "���ֽڣ�ʵ���ַ������ȣ�" << strlen(cstr2) << "������������������һ�����ֵ���2���ֽڣ���16��" << endl;					// strlen() ������	��ȡ���� �ַ����� �����ݳ��ȡ�	ֵ��16��		������������\0������һ������ռ��2���ֽڡ�
		cout << endl;

		cout << "�� ת ��   ת����......" << endl;
		cout << endl;

		wchar_t* wcstr = new wchar_t[strlen(cstr2) + 1];		// ������ C ����� (wchar_t*) malloc( pReturnValue *sizeof(wchar_t));

		// �ʣ�Ϊʲô wcstombs_s ����Ҫ���ε����أ�
		// �𣺿�ת���ʱ�򣬿��ֽڻ���������Щ�������ڶ��ֽڻ����������Ҫ��2���ֽڴ��ڵġ����ܵ�һ���������ַ��ĳ���������ʵ����Ҫ���ֽ����������ֽ�ת���ֽھ����׶��ˡ���Ϊÿ���ַ����ն�����2�������ġ�

		// mbstowcs_s ��������
		// ���� 1��_PtNumOfCharConverted�� ���Ǳ���ġ�����ɹ�ת����Դ�ַ��������Ὣת�����ַ�����������ֹ�����Ĵ�С���Կ��ַ�Ϊ��λ������ *pReturnValue���ٶ� pReturnValue ���� NULL������NULL���Ǿ��ǲ���Ҫ����ֵ
		// ���� 2��_DstBuf��Ҳ���Ǳ���ġ�����ֻ��Ҫ���� _PtNumOfCharConverted ��ת�����ַ�������ô_DstBuf����ΪNULL�����_SizeInWords = 0��MaxCount = 0��
		// ���� 3��_SizeInWords��Ҫע����ǣ���ֵ�� Word ��������Word �� �֣������ֽڣ�Ҳ���� DWord ˫�֡������ڴ˿��������ֽڱ�ʾ��Ϊ һ�� Word��һ���֣�Ϊ�������ݵ�λ���˴�һ��Word = 2���ֽڡ���ֵҲ���� wcstr ���Կ��ֽڵ�λ�ĳ��ȡ�
		// ���� 4��_SrcBuf������ġ�
		// ���� 5��_MaxCount��Ҫ�洢�� wcstr �еĿ��ַ������������������ֹ����ֻ����Ҫת��һ�����ַ���ʱ�����ʵ�����塣��Ȼ��һֱ�� strlen(_SrcBuf)

		mbstowcs_s(NULL, wcstr, (strlen(cstr2) + 1), cstr2, 16);

		wcout << "���ֽڣ���ʾ��" << wcstr << endl;
		wcout << "���ֽڣ��ַ�����ռ��С��" << sizeof(wchar_t) * wcslen(wcstr) << "��������������16 * 2" << endl;

		const wchar_t* fs = L"��Һ�";
		wcout << "���ֽ���ʾ��" << sizeof(fs) << endl;
		delete[] wcstr;
	}
	

	// C ����ƽ̨�� ���ֽ��ַ����� ת ���ֽ��ַ�����
	 {
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << "�� ת ��.................................." << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;

		// ע�⣺��������� setlocale/_wsetlocale/_tsetlocale Ϊ ""��wcout�᲻��������ʾ
		// ���� locale ���ݲο���https://learn.microsoft.com/zh-cn/cpp/c-runtime-library/reference/setlocale-wsetlocale?view=msvc-170
		// ���Ĳο� 0�� setlocale(LC_ALL, "C")			��������ʱ���൱��Ĭ�ϲ����˸���Ϊ
		// ���Ĳο� 1�� setlocale(LC_ALL, NULL)			�᷵�ص�ǰ��������
		// ���Ĳο� 2�� setlocale(LC_ALL, "")				������������ΪĬ��ֵ����ֵ�ǴӲ���ϵͳ��ȡ���û�Ĭ�ϵ�ANSI����ҳ��������⣺��Ӣ��ϵͳ + ��֧�ֵ�Unicode ��������ʾ���ͻ���Ӣ��ANSIΪ����GBK���Ϊ����Ĭ����ʽ��
		// ���Ĳο� 3�� setlocale(LC_ALL, "en_US")		΢���Ƽ�����ʽ��Ϊָ��������ʹ��Ĭ���˹���/������
		// ���Ĳο� 4�� setlocale(LC_ALL, "en_US.UTF8)	֧��UTF8�����ַ�( - )��ѡ���� UTF8 = UTF-8��

		//setlocale(LC_ALL, "");			// ���ֽڰ汾
		//_wsetlocale(LC_ALL, L"");		// ���ֽڰ汾
		_tsetlocale(LC_ALL, _T(""));	// ͨ�ð汾����Ҫ #include <tchar.h>

		// ������ʽ
		const wchar_t* wcstr1 = L"�Ұ�������ddd666";
		wchar_t wcstr2[256] = L"�Ұ�������666eee";

		wcout << wcstr2 << endl;

		wcout << endl;
		wcout << L"�� ת �� ת����............." << endl;
		wcout << endl;


		// �ʣ�Ϊʲô ���ֽ� ת ���ֽ� ����Ҫ���� wcstombs_s �أ�
		// �����ֻ��һ�� wcstombs_s����û�취׼ȷ������Ҫ�� ���ֽ� ��������С�� �Ͼ�������һ������ռ�� 2 ���ֽڵġ������ȫӢ�����֣���ôֻ��һ�κ����Ϳ����ˡ�

			// ������Ҫ����ʵ�ֽ�����
			size_t pReturnValue;					// ����ʹ�� int�ͣ� wcstombs_s �����޷�ͨ����
			wcstombs_s(&pReturnValue, NULL, 0, wcstr2, 0);

			// �����㹻�ֽڵĻ���������ʼת��
			char* cstr = new char[pReturnValue];

			// wcstombs_s ��������
			// ���� 1��_PtNumOfCharConverted���ڿ��ֽ��������ĵ�����£���ֵ���뷵�أ����ܻ�ȡ׼ȷ����Ҫת������ֽڿռ��С��
			// ���� 2��_Dst�����ֽڻ�����
			// ���� 3��_DstSizeInBytes��ע�ⵥλ�� Byte �ֽڡ�
			// ���� 4��_Src��Դ���ֽ�
			// ���� 5��_MaxCountInBytes���洢�ڶ��ֽڻ������е�ʵ�����ݵ��ֽڳ��ȡ����ô���ֹ����
			wcstombs_s(NULL, cstr, pReturnValue, wcstr2, pReturnValue - 1);


		cout << "���ֽ��ַ����У���ʾ��" << cstr << endl;
		delete[] cstr;

	}
	

	return 0;
}