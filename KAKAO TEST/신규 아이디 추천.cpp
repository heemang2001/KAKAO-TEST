#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(string new_id)
{
	string answer = "";
		
	// 1�ܰ� : new_id�� ��� �빮�ڸ� �����Ǵ� �ҹ��ڷ� ġȯ�մϴ�.
	for (int i = 0; i < new_id.size(); i++)
	{		
		if (new_id[i] >= 'A' && new_id[i] <= 'Z')
		{
			new_id[i] = new_id[i] + 32;
		}
	}

	// 2�ܰ� : new_id���� ���ĺ� �ҹ���, ����, ����(-), ����(_), ��ħǥ(.)�� ������ ��� ���ڸ� �����մϴ�.
	for (int i = 0; i < new_id.size();)
	{		
		if (((new_id[i] >= 'a' && new_id[i] <= 'z') || (new_id[i] >= '0' && new_id[i] <= '9') || (new_id[i] == '-') || (new_id[i] == '_') || (new_id[i] == '.')))
		{
			i++;
			continue;
		}		

		new_id.erase(new_id.begin() + i);
	}

	// 3�ܰ� : new_id���� ��ħǥ(.)�� 2�� �̻� ���ӵ� �κ��� �ϳ��� ��ħǥ(.)�� ġȯ�մϴ�.
	for (int i = 0; i < new_id.size(); i++)
	{
		if (new_id[i] == '.')
		{
			for (int j = i + 1; j < new_id.size(); j++)
			{
				if (new_id[j] == '.')
				{
					new_id.erase(new_id.begin() + j);

					if (j > 0)
					{
						j--;
					}
				}

				else
				{
					break;
				}
			}
		}
	}

	// 4�ܰ� : new_id���� ��ħǥ(.)�� ó���̳� ���� ��ġ�Ѵٸ� �����մϴ�.
	if (!new_id.empty())
	{
		if (new_id.front() == '.')
		{
			new_id.erase(new_id.begin());
		}
	}

	if (!new_id.empty())
	{
		if (new_id.back() == '.')
		{
			new_id.erase(new_id.end() - 1);
		}
	}

	// 5�ܰ� : new_id�� �� ���ڿ��̶��, new_id�� "a"�� �����մϴ�.
	if (new_id == "")
	{
		new_id += 'a';
	}

	// 6�ܰ� : new_id�� ���̰� 16�� �̻��̸�, new_id�� ù 15���� ���ڸ� ������ ������ ���ڵ��� ��� �����մϴ�.
	// ���� ���� �� ��ħǥ(.)�� new_id�� ���� ��ġ�Ѵٸ� ���� ��ġ�� ��ħǥ(.) ���ڸ� �����մϴ�.
	if (new_id.size() >= 16)
	{
		new_id = new_id.substr(0, 15);

		if (new_id.back() == '.')
		{
			new_id.erase(new_id.end() - 1);
		}
	}

	// 7�ܰ� : new_id�� ���̰� 2�� ���϶��, new_id�� ������ ���ڸ� new_id�� ���̰� 3�� �� ������ �ݺ��ؼ� ���� ���Դϴ�.
	if (!new_id.empty())
	{
		if (new_id.size() <= 2)
		{
			char cTemp = new_id.back();

			while (1)
			{
				if (new_id.size() >= 3)
				{
					break;
				}

				new_id += cTemp;
			}
		}
	}

	answer = new_id;
	return answer;
}

int main()
{
	cout << solution("...!@BaT#*..y.abcdefghijklm") << '\n';	// "bat.y.abcdefghi"
	cout << solution("z-+.^.") << '\n';							// "z--"
	cout << solution("=.=") << '\n';							// "aaa"
	cout << solution("123_.def") << '\n';						// "123_.def"
	cout << solution("abcdefghijklmn.p") << '\n';				// "abcdefghijklmn"
	cout << solution("b......@") << '\n';						// "bbb"
	cout << solution("-_.~!@#$%^&*()=+[{]}:?,<>/._-") << '\n';	// "-_._-"	
	cout << solution("~!@#$%&*()=+[{]}:?,<>/") << '\n';			// "aaa"
	cout << solution(".1.") << '\n';							// "111"

	return 0;
}