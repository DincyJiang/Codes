//#include <fstream>
//#include <iostream>
//#include<string>
//
//using namespace std;
//
//#define numOfDisks 10
//
//ofstream fout("out.txt");
//
//void Move(int n, string x, string y)
//{
//	fout << "move " << n << "from" << x << "to" << y << endl;
//}
//
//void Hannoi(int n, string a, string b, string c) {
//	if (n == 1)
//		Move(1, a, c);
//	else {
//		Hannoi(n - 1, a, c, b);
//		Move(n, a, c);
//		Hannoi(n - 1, b, a, c);
//	}
//}
//
//int main() {
//	fout << "The solution for hannoi,when the number of disks is " << numOfDisks << endl;
//	string a("a");
//	string b("b");
//	string c("c");
//	Hannoi(numOfDisks, a,b,c);
//	fout.close();
//	cout << "The end: Please Check out.txt ." << endl;
//	cin.get();
//	return 0;
//}