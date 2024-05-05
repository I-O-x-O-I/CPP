#include <iostream>
#include <tchar.h>

using namespace std;




int main__Fuck()
{

	// 参考：https://midoq.github.io/2022/02/27/C%E5%92%8CC++%E4%B8%AD%E7%9A%84%E6%A0%87%E5%87%86%E8%BE%93%E5%85%A5%E8%BE%93%E5%87%BA%E5%87%BD%E6%95%B0%E7%BB%88%E6%9E%81%E6%9C%80%E5%85%A8%E8%A7%A3%E6%9E%90%EF%BC%88%E4%B8%8D%E5%85%A8%E6%8D%B6%E6%88%91%EF%BC%89/

	// C 风格：scanf 对应 printf 【scanf 是按特定格式从stdin读取输入】
	/* {
		printf("请输入 若干个 个数字\n");			// 注意：即便没有在 printf 第一个format参数中看到类似“%”的形式，它也是正确的。因为它只是一个没有 % 百分号的格式化形式。
		int a, b, c, d, e;
		int result = scanf_s("%d%d%d%d %d\n", &a, &b, &c, &d, &e);		// 注意：参数是指向变量类型的指针。且 格式符之间要有空格
		printf("输入了共计 %d 个数字， 对吗？", result);

		printf("打印出刚才输入的 %d 个数字： A:%d, B:%d, C:%d, D:%d, E:%d\n", result, a, b, c, d, e);


		//wprintf 只是 printf 的宽字符版本


		// printf 将格式化输出打印至标准输出流
		// sprintf 是将设置格式的数据写入字符串 【字符串】
		char ch[256];
		sprintf_s(ch, "我内部的数据是 A=%d，B=%d", a, b);
		printf(ch);


		// 将格式化数据输出到流 【文件】
		FILE* stream;
		fopen_s(&stream, "abc.txt", "w");
		fprintf(stream, "我今天拿到的最终数据是A = %d, B = %d", a, b);
		fclose(stream);
		system("type abc.txt");			// system("type xxxxx.txt")  负责输出刚才的文件内容
	}
	*/


	// C 风格：fgets 对应 fputs	【fgets 是从指定输入流读取一行，输入流可显式指定 stdin 或 文件流】
	/*
	{

		char ch[1024];
		memset(ch, 0, sizeof(ch));

		FILE* stream;
		fopen_s(&stream, "C:\\Users\\X\\Desktop\\winget-install.txt", "r");
		if (stream == NULL)
		{
			printf("文件不能正常读取！");

			exit(1);					// exit参数指明进程退出的返回值，操作系统根据这个值来判断是否是正常退出。	通常 0 表示正常退出，其他参数表示异常退出
		}

		while (fgets(ch, 1024, stream))
		{
			printf(ch);
		}
		fclose(stream);



		// fputs 整行写入
		int i = 0;
		const char* ch = "大嚼服\n哦是否2244\n999\nsfsjdfjsdflslfd\n\n\n\nsfsfs99242343\nabcdefgggggg";


		FILE* pStream;
		fopen_s(&pStream, "C:\\Users\\X\\Desktop\\abc.txt", "w");
		if (pStream == NULL)
		{
			printf("文件不能正常打开");
			exit(1);
		}

		printf("测试中文是否正常显示\n");

		// 整行写入到 文件流
		while (fputs(ch, pStream))
		{
			printf("正在写入第 %d ", i++);
		}

		// 整行写入到 stdout 输出流
		while (fputs(ch, stdout))
		{
			printf("正在写入第 %d ", i++);
		}


		fclose(pStream);




		// 读取一个字符
		// fgetc() 和 getc() 和 getchar()
			// getc() 是 由 fgetc() 宏定义而来
			// getc() 和 fgetc() 可以指定，文件流 和 输入流 stdin
			// getchar() 也是有 fgetc() 宏定义而来，区别是 getchar() 指定了输入流为 stdin

		// 写入一个字符
			// fgetc() 对应 fputc
			// getc() 对应 putc()
			// getchar() 对应 putchar

	}
	*/








	// C++ 风格  cin . cout

	{
		// cin.get() 读取 单个 字符
		/*
		char a, b;
		char str[50];

		cin.get(b);

		cout << "B = " << b << endl;

		// cin.get() 读取指定长度的字符

		// 获取到最大第10个字符处 或者 当发现第一个空格时。 这里需要注意一些基础知识。
		// ' '空格字符，就是空格，无其他特殊符号代替。
		// '\n' 是 换行。'\r' 是 回车
		cin.get(str, 10, ' ');		

		cout << "str is : " << str << endl;
		*/

		
		// cout 输出流
		char str[] = "你好啊";
		cout << str << endl;




	}
	


	return 0;
}