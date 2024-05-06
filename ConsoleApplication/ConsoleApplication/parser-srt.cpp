#include <iostream>
#include <string>
#include <fstream>
#include <regex>

using namespace std;





/// <summary>
/// ��Ļ��Ϣ
/// </summary>
struct SRTItem
{
	unsigned int nItemKey;		// ��Ļ����
	std::string timeText;		// ʱ��ֵ�ı�δ�ָ�
	std::string srtText;		// ��Ļ�ı�
	unsigned int nStartTime;	// �ָ��ǰ��Ļ��ʼʱ��
	unsigned int nStopTime;		// �ָ��ǰ��Ļ����ʱ��
	unsigned int nDurationTime;	// �ָ��ǰ��Ļ����ʱ��

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
/// ��ȡSRT���ļ������ʽ�� UTF-8 with BOM
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

	// ��Ҫ�� fopen_s ������ C ����
		//FILE* f;
		//if (fopen_s(&f, this->m_strPath.c_str(), "r") != 0)
		//	std::cout << "�ļ���ʧ��" << std::endl;


	// �����ļ���
	std::fstream fs(m_strPath, std::ios::in);

	// ��ȡ����
	char s[1024];

	// ���� UTF-8 with BOM ����ı�־��3���ֽ� EF BB BF
	fs.seekg(3);

	// ����һ����׼�ָ���Ļ��  ��Ļ����ʽ����һ�У�1���ڶ��У�ʱ�䣬�����У���Ļ�ı��������У�0�ַ���ֵ
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
			// ��Ļ����

			srtItem.nItemKey = std::stoi(s);
		}
		else if (i == 1)
		{
			// ʱ��	: 00:00:05,080 --> 00:00:10,720
			srtItem.timeText = s;

			// ƥ��
			std::cmatch cmatch;
			std::regex_match(s, cmatch, std::basic_regex("(.*) --> (.*)"), std::regex_constants::match_any);
			std::string sStartTime	= cmatch[1].str();
			std::string sStopTime	= cmatch[2].str();

			// ����ʱ�䴮 1��ƥ��� ʱ���֣��룬����
			std::regex_match(sStartTime.c_str(), cmatch, std::basic_regex("(.*):(.*):(.*),(.*)"), std::regex_constants::match_any);
			std::string sHour = cmatch[1].str();
			std::string sMinute = cmatch[2].str();
			std::string sSecond = cmatch[3].str();
			std::string sMillisecond = cmatch[4].str();

			srtItem.nStartTime = std::stoi(sHour) * 3600000 + std::stoi(sMinute) * 60000 + std::stoi(sSecond) * 1000 + std::stoi(sMillisecond);

			// ����ʱ�䴮 2��ƥ��� ʱ���֣��룬����
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

			// ��Ļ�ı�
			srtItem.srtText = s;

			// ���� vector �������
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





