//#include<vector>
//#include<iostream>
//using namespace std;
//
////把迷宫表示为n个有编码路口的集合
//class Crossing
//{
//public:
//	//0为不通路口的3个方向
//	int turn1, turn2, turn3;
//public:
//	Crossing(int turn1, int turn2, int turn3) :turn1(turn1), turn2(turn2), turn3(turn3) {}
//};
//
////定义迷宫类
//class Maze
//{
//private:
//	int exit;
//	vector<Crossing> crossings;
//	vector<int> result;
//
//public:
//	Maze(int the_exit, vector<Crossing> the_crossings) :exit(the_exit), crossings(the_crossings) {}
//	int findExit(int entrance)
//	{
//		if (entrance > 0) {
//			if (entrance == Maze::exit) {
//				result.push_back(entrance);
//				return 1;
//			}
//			if (findExit(crossings[entrance].turn1))
//			{
//				result.push_back(entrance);
//				return 1;
//			}
//			if (findExit(crossings[entrance].turn2))
//			{
//				result.push_back(entrance);
//				return 1;
//			}
//			if (findExit(crossings[entrance].turn3))
//			{
//				result.push_back(entrance);
//				return 1;
//			}
//		}
//	}
//	void getResult()
//	{
//		findExit(1);
//		for (int i = result.size(); i > 0; i--)
//			cout << result[i - 1] << "->";
//		cout<< "Exit" << endl;
//	}
//};
//
//int main()
//{
//	Crossing c1(2, 0, 0);
//	Crossing c2(4, 0, 0);
//	Crossing c3(0, 0, 0);
//	Crossing c4(3, 5, 0);
//	Crossing c5(6, 0, 0);
//	Crossing c6(7, 0, 0);
//	Crossing c7(8, 9, 0);
//	Crossing c8(0, 0, 0);
//	Crossing c9(10, 0, 0);
//	Crossing c0(0, 0, 0);
//
//	vector<Crossing> crossings;
//	crossings.push_back(c0);
//	crossings.push_back(c1);
//	crossings.push_back(c2);
//	crossings.push_back(c3);
//	crossings.push_back(c4);
//	crossings.push_back(c5);
//	crossings.push_back(c6);
//	crossings.push_back(c7);
//	crossings.push_back(c8);
//	crossings.push_back(c9);
//
//	Maze newMaze(10, crossings);
//	newMaze.getResult();
//	cin.get();
//	return 0;
//}