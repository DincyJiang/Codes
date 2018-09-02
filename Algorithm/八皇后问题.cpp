#include<iostream>
#include<fstream>
using namespace std;
#define MAX 8
int sum = 0;
ofstream fout("result.txt");
class QueenPuzzle
{
	int queens[MAX];

public:
	void printOut()
	{
		for (int i = 0; i < MAX; i++) {
			for (int j = 0; j < MAX; j++) {
				if (j == queens[i])
					fout << "Q";
				else
					fout << "0";
			}
			fout << endl;
		}
		fout << endl << "按q键盘退出，按其他键继续" << endl;
		if (cin.get() == 'q')
			exit(0);
	}
	int IsValid(int n)
	{
		for (int i = 0; i < n; i++) {
			if (queens[i] == queens[n])
				return 0;
			if (abs(queens[i] - queens[n]) == (n - i))
				return 0;
		}
		return 1;
	}
	void placeQueen(int i)
	{
		for (int j = 0; j < MAX; j++) {
			if (i == MAX) {
				sum++;
				fout << "第" << sum << "组解：" << endl;
				printOut();
				return;
			}
			queens[i] = j;
			if (IsValid(i))
				placeQueen(i + 1);
		}
	}

};
int main()
{
	QueenPuzzle queen;
	queen.placeQueen(0);
	fout << "共" << sum << "组解" << endl;
	cin.get();
	return 0;
}