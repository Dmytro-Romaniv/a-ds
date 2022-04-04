#include <iostream>
using namespace std;

int main() 
{
	char answer;
	cout << "[......] 0%";
	system("countSort.exe > countSort.txt");
	cout << "\r[|.....] 16%";
	system("shellSort.exe > shellSort.txt");
	cout << "\r[||....] 32%";
	system("quickSort.exe > quickSort.txt");
	cout << "\r[|||...] 48%";
	system("heapSort.exe > heapSort.txt");
	cout << "\r[||||..] 64%";
	system("mergeSort.exe > mergeSort.txt");
	cout << "\r[|||||.] 80%";
	system("bubbleSort.exe > bubbleSort.txt");
	cout << "\r[||||||] 100%\n";
	cout << "Do you want to open the files? (y / n): ";
	cin >> answer;
	if (answer == 'y')
	{
		system("start countSort.txt");
		system("start shellSort.txt");
		system("start quickSort.txt");
		system("start heapSort.txt");
		system("start mergeSort.txt");
		system("start bubbleSort.txt");
	}
    return 0;
}
