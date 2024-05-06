#include <iostream>
#include <string>
#include <fstream>
#include <regex>

using namespace std;





/// <summary>
/// 字幕信息
/// </summary>
struct SRTItem
{
	unsigned int nItemKey;		// 字幕索引
	std::string timeText;		// 时间值文本未分割
	std::string srtText;		// 字幕文本
	unsigned int nStartTime;	// 分割后当前字幕开始时间
	unsigned int nStopTime;		// 分割后当前字幕结束时间
	unsigned int nDurationTime;	// 分割后当前字幕持续时间

public:

	inline void clear() {
		nItemKey = 0;
		timeText = "";
		srtText = "";
		nStartTime = 0;
		nStopTime = 0;
		nDurationTime = 0;
	};
};


/// <summary>
/// 读取SRT的文件编码格式： UTF-8 with BOM
/// </summary>
class ParserSRT
{
public:
	ParserSRT(std::string srtPath) : m_strPath(srtPath) {}
	~ParserSRT();

	void Parser();


public:
	std::string m_strPath;
	std::vector<SRTItem> srtItems;
};


ParserSRT::~ParserSRT()
{
}

void ParserSRT::Parser()
{

	// 不要用 fopen_s ，这是 C 风格的
		//FILE* f;
		//if (fopen_s(&f, this->m_strPath.c_str(), "r") != 0)
		//	std::cout << "文件打开失败" << std::endl;


	// 构造文件流
	std::fstream fs(m_strPath, std::ios::in);

	// 读取整行
	char s[1024];

	// 跳过 UTF-8 with BOM 编码的标志：3个字节 EF BB BF
	fs.seekg(3);

	// 开启一个标准分隔字幕。  字幕的形式：第一行：1，第二行：时间，第三行：字幕文本，第四行：0字符空值
	int i = 0;
	SRTItem srtItem;
	while (fs.getline(s, sizeof(s)))
	{
		std::setlocale(LC_ALL, "zh-CN.UTF8");
		i = i == 4 ? 0 : i;
		//std::cout << s << std::endl;

		if (i == 0)
		{
			srtItem.clear();
			// 字幕索引

			srtItem.nItemKey = std::stoi(s);
		}
		else if (i == 1)
		{
			// 时间	: 00:00:05,080 --> 00:00:10,720
			srtItem.timeText = s;

			// 匹配
			std::cmatch cmatch;
			std::regex_match(s, cmatch, std::basic_regex("(.*) --> (.*)"), std::regex_constants::match_any);
			std::string sStartTime	= cmatch[1].str();
			std::string sStopTime	= cmatch[2].str();

			// 对子时间串 1，匹配出 时：分：秒，毫秒
			std::regex_match(sStartTime.c_str(), cmatch, std::basic_regex("(.*):(.*):(.*),(.*)"), std::regex_constants::match_any);
			std::string sHour = cmatch[1].str();
			std::string sMinute = cmatch[2].str();
			std::string sSecond = cmatch[3].str();
			std::string sMillisecond = cmatch[4].str();

			srtItem.nStartTime = std::stoi(sHour) * 3600000 + std::stoi(sMinute) * 60000 + std::stoi(sSecond) * 1000 + std::stoi(sMillisecond);

			// 对子时间串 2，匹配出 时：分：秒，毫秒
			std::regex_match(sStopTime.c_str(), cmatch, std::basic_regex("(.*):(.*):(.*),(.*)"), std::regex_constants::match_any);
			sHour = cmatch[1].str();
			sMinute = cmatch[2].str();
			sSecond = cmatch[3].str();
			sMillisecond = cmatch[4].str();

			srtItem.nStopTime = std::stoi(sHour) * 3600000 + std::stoi(sMinute) * 60000 + std::stoi(sSecond) * 1000 + std::stoi(sMillisecond);
			srtItem.nDurationTime = srtItem.nStopTime - srtItem.nStartTime;



		}
		else if (i == 2)
		{

			// 字幕文本
			srtItem.srtText = s;

			// 进行 vector 容器填充
			this->srtItems.push_back(srtItem);
		}
		else if (i == 3)
		{
			// 
		}

		i++;

	}

}





int main___FUCK()
{
	

	ParserSRT parser("D://Temp//liangxie-srt.srt");
	parser.Parser();
	
	for (auto srtItem : parser.srtItems)
	{
		std::cout << srtItem.nItemKey << std::endl;
		std::cout << srtItem.timeText << std::endl;
		std::cout << srtItem.nStartTime << std::endl;
		std::cout << srtItem.nStopTime << std::endl;
		std::cout << srtItem.nDurationTime << std::endl;
		std::cout << srtItem.srtText << std::endl;
		std::cout << endl;
	}
	



	return 0;

}





