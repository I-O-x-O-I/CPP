#include <iostream>
#include <tchar.h>

using namespace std;




int main__Fuck()
{

	// �ο���https://midoq.github.io/2022/02/27/C%E5%92%8CC++%E4%B8%AD%E7%9A%84%E6%A0%87%E5%87%86%E8%BE%93%E5%85%A5%E8%BE%93%E5%87%BA%E5%87%BD%E6%95%B0%E7%BB%88%E6%9E%81%E6%9C%80%E5%85%A8%E8%A7%A3%E6%9E%90%EF%BC%88%E4%B8%8D%E5%85%A8%E6%8D%B6%E6%88%91%EF%BC%89/

	// C ���scanf ��Ӧ printf ��scanf �ǰ��ض���ʽ��stdin��ȡ���롿
	/* {
		printf("������ ���ɸ� ������\n");			// ע�⣺����û���� printf ��һ��format�����п������ơ�%������ʽ����Ҳ����ȷ�ġ���Ϊ��ֻ��һ��û�� % �ٷֺŵĸ�ʽ����ʽ��
		int a, b, c, d, e;
		int result = scanf_s("%d%d%d%d %d\n", &a, &b, &c, &d, &e);		// ע�⣺������ָ��������͵�ָ�롣�� ��ʽ��֮��Ҫ�пո�
		printf("�����˹��� %d �����֣� ����", result);

		printf("��ӡ���ղ������ %d �����֣� A:%d, B:%d, C:%d, D:%d, E:%d\n", result, a, b, c, d, e);


		//wprintf ֻ�� printf �Ŀ��ַ��汾


		// printf ����ʽ�������ӡ����׼�����
		// sprintf �ǽ����ø�ʽ������д���ַ��� ���ַ�����
		char ch[256];
		sprintf_s(ch, "���ڲ��������� A=%d��B=%d", a, b);
		printf(ch);


		// ����ʽ������������� ���ļ���
		FILE* stream;
		fopen_s(&stream, "abc.txt", "w");
		fprintf(stream, "�ҽ����õ�������������A = %d, B = %d", a, b);
		fclose(stream);
		system("type abc.txt");			// system("type xxxxx.txt")  ��������ղŵ��ļ�����
	}
	*/


	// C ���fgets ��Ӧ fputs	��fgets �Ǵ�ָ����������ȡһ�У�����������ʽָ�� stdin �� �ļ�����
	/*
	{

		char ch[1024];
		memset(ch, 0, sizeof(ch));

		FILE* stream;
		fopen_s(&stream, "C:\\Users\\X\\Desktop\\winget-install.txt", "r");
		if (stream == NULL)
		{
			printf("�ļ�����������ȡ��");

			exit(1);					// exit����ָ�������˳��ķ���ֵ������ϵͳ�������ֵ���ж��Ƿ��������˳���	ͨ�� 0 ��ʾ�����˳�������������ʾ�쳣�˳�
		}

		while (fgets(ch, 1024, stream))
		{
			printf(ch);
		}
		fclose(stream);



		// fputs ����д��
		int i = 0;
		const char* ch = "�����\nŶ�Ƿ�2244\n999\nsfsjdfjsdflslfd\n\n\n\nsfsfs99242343\nabcdefgggggg";


		FILE* pStream;
		fopen_s(&pStream, "C:\\Users\\X\\Desktop\\abc.txt", "w");
		if (pStream == NULL)
		{
			printf("�ļ�����������");
			exit(1);
		}

		printf("���������Ƿ�������ʾ\n");

		// ����д�뵽 �ļ���
		while (fputs(ch, pStream))
		{
			printf("����д��� %d ", i++);
		}

		// ����д�뵽 stdout �����
		while (fputs(ch, stdout))
		{
			printf("����д��� %d ", i++);
		}


		fclose(pStream);




		// ��ȡһ���ַ�
		// fgetc() �� getc() �� getchar()
			// getc() �� �� fgetc() �궨�����
			// getc() �� fgetc() ����ָ�����ļ��� �� ������ stdin
			// getchar() Ҳ���� fgetc() �궨������������� getchar() ָ����������Ϊ stdin

		// д��һ���ַ�
			// fgetc() ��Ӧ fputc
			// getc() ��Ӧ putc()
			// getchar() ��Ӧ putchar

	}
	*/








	// C++ ���  cin . cout

	{
		// cin.get() ��ȡ ���� �ַ�
		/*
		char a, b;
		char str[50];

		cin.get(b);

		cout << "B = " << b << endl;

		// cin.get() ��ȡָ�����ȵ��ַ�

		// ��ȡ������10���ַ��� ���� �����ֵ�һ���ո�ʱ�� ������Ҫע��һЩ����֪ʶ��
		// ' '�ո��ַ������ǿո�������������Ŵ��档
		// '\n' �� ���С�'\r' �� �س�
		cin.get(str, 10, ' ');		

		cout << "str is : " << str << endl;
		*/

		
		// cout �����
		char str[] = "��ð�";
		cout << str << endl;




	}
	


	return 0;
}