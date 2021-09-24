#include <fstream>
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

int maxKarma(int k, std::vector<std::pair<int, bool>> contests);
int maxKarma2(int k, std::vector<std::pair<int, bool>> contests);

int main()
{
	int k;
	std::vector<std::pair<int, bool>> contests;
	std::ifstream fin("input.txt");
	std::pair<int, bool> cur;
	fin >> k;
	while (!fin.eof()) {
		fin >> cur.first >> cur.second;
		contests.push_back(cur);
	}
	std::cout << maxKarma(k, contests) << std::endl;
	std::cout << maxKarma2(k, contests);
	return 0;
}

int maxKarma(int k, std::vector<std::pair<int, bool>> contests) 
{
	int L = 0;
	if (k == contests.size())
	{
		for (auto el : contests)
		{
			L += el.first;
		}
		return L;
	}
	else if(k == 0){
		for (auto el : contests)
		{
			L += el.second ? -el.first : el.first;
		}
		return L;
	}
	else {
		std::list<int> important;
		for (auto el : contests)
		{
			if (el.second)
			{
				if (important.size() != k)
				{
					important.push_back(el.first);
					if (important.size() == k)
					{
						important.sort();
					}
				}
				else if(el.first > important.front())
				{
					L -= important.front();
					important.pop_front();
					if (el.first > important.back())
					{
						important.push_back(el.first);
					}
					else
					{
						for (auto imp = important.begin(); imp != important.end(); ++imp)
						{
							if (el.first < *imp)
							{
								important.emplace(imp, el.first);
							}
						}
					}
				}
			}
			else
			{
				L += el.first;
			}
		}
		for (auto el : important)
		{
			L += el;
		}
		return L;
	}
}

int maxKarma2(int k, std::vector<std::pair<int, bool>> contests)
{
	int L = 0;
	if (k == contests.size())
	{
		for (auto el : contests)
		{
			L += el.first;
		}
		return L;
	}
	else if (k == 0) {
		for (auto el : contests)
		{
			L += el.second ? -el.first : el.first;
		}
		return L;
	}
	else {
		
		std::sort(contests.begin(), contests.end(), [](std::pair<int, bool> a, std::pair<int, bool> b) { return a.first > b.first; });
		for (auto el : contests)
		{
			L += el.second ? (k-- ? el.first : -el.first): el.first;
		}
		
		return L;
	}
}