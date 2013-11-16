#include <vector>
#include <unordered_map>
#include <map>
#include <iostream>
#include <unordered_set>
#include <exception>
#include <cstdlib>
#include <ctime>
using namespace std;


int get_number(vector<int> &numbers)
{
	int Size = numbers.size();
	if (Size == 0)
		throw exception();
	int Sum = 0;
	for (int i = 0; i < Size; i++)
		Sum += numbers[i];
	int Num = rand() % Sum;
	int CummSum = 0;
	for (int i = 0; i < Size; i++) {
		CummSum += numbers[i];
		if (Num < CummSum)
			return numbers[i];
	}

	return -1;
}


int main(int argn, char *argv[])
{
	int Num = atoi(argv[1]);
	unordered_set<int> NumberSet;
	int i = 0;
	srand(time(NULL));
	for (i = 0; i < Num;) {
		int tmp = rand() % 100;
		if (NumberSet.count(tmp))
			continue;
		NumberSet.insert(tmp);
		i++;
	}
	vector<int> Numbers(Num);
	i = 0;
	for (auto num : NumberSet) {
		Numbers[i] = num;
		i++;
	}
	map<int, int> Imap;
	for (i = 0; i < 10000; i++) {
		int Number = get_number(Numbers);
		Imap[Number]++;
	}

	for (auto &x : Imap)
		cout << "(" << x.first << ", " << x.second << ")" << endl;
	return 0;
}






