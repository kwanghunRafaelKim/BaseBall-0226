#include <iostream>

using namespace std;

struct Result
{
	bool solved;
	int strikes;
	int balls;
};

class Baseball{
public:
	explicit Baseball(const string& question)
		: question(question)
	{
	}

	bool isDuplicatedNumber(string guessNumber)
	{
		if(guessNumber[0] == guessNumber[1] ||
			guessNumber[1] == guessNumber[2] || 
			guessNumber[0] == guessNumber[2])
		{
			return true;
		}
		return false;
	}

	bool isIncludeChar(string guessNumber)
	{
		for(char ch:guessNumber){
			if (ch >= '0' && ch <= '9') continue;
			return true;
		}
		return false;
	}

	void assertIllegalArgument(string guessNumber)
	{
		if(guessNumber ==""){
			throw std::invalid_argument("���� �־�� ��");
		}
		if(guessNumber.length()!=3){
			throw std::invalid_argument("�ڸ��� ����");
		}
		if(isIncludeChar(guessNumber)){
			throw std::invalid_argument("���ڷθ� �����Ǿ� ���� ����");
		}
		if(isDuplicatedNumber(guessNumber))	{
			throw std::invalid_argument("���� ���� 2�� �ȵ�");
		}
	}

	int cntStrike(string guessNumber)
	{
		int scnt = 0;

		for(int i = 0;i<3;i++)
		{
			int matchidx = guessNumber.find(question[i]);
			if (matchidx == -1) continue;
			if (i == matchidx) scnt++;
		}

		return scnt;
	}

	int cntball(string guessNumber)
	{
		int bcnt = 0;
		for(int i = 0;i<3;i++)
		{
			int matchidx = guessNumber.find(question[i]);
			if (matchidx == -1) continue;
			if (i == matchidx) continue;
			bcnt++;
		}
		return bcnt;
	}

	Result guess(string guessNumber)
	{
		assertIllegalArgument(guessNumber);

		if (guessNumber == question){
			return { true, 3, 0 };
		}
		int scnt = cntStrike(guessNumber);
		int bcnt =  cntball(guessNumber);

		return { false, scnt,bcnt };
	}

private:
	string question;
		
};