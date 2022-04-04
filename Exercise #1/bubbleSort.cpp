#include <iostream>
#include <chrono>
using namespace std::chrono;
using namespace std;

void bubbleSort(int array[], int size) {
  	for (int step = 0; step < size; ++step)
    	for (int i = 0; i < size - step; ++i)
      		if (array[i] > array[i + 1]) {
        		int temp = array[i];
        		array[i] = array[i + 1];
        		array[i + 1] = temp;
				}
}

int ran(int s)
{
	srand( (unsigned)time( NULL ) );
	int arr[s];
    for (int i = 0; i < s; i++)
    	arr[i]=rand();
    bubbleSort(arr, s);
    return 0;
}

int con(int s)
{
	int arr[s];
    for (int i = 0; i < s; i++)
    	arr[i]=0;
    bubbleSort(arr, s);
    return 0;
}

int inc(int s)
{
	int arr[s];
    for (int i = 0; i < s; i++)
    	arr[i]=i;
    bubbleSort(arr, s);
    return 0;
}

int dec(int s)
{
	int arr[s];
    for (int i = 0; i < s; i++)
    	arr[i]=-i;
	bubbleSort(arr, s);
	return 0;
}

int asc(int s)
{
    int arr[s];
    int t = 1;
    for (int i = 0; t < s; i++)
	{
    	arr[i]=t;
    	arr[s-1-i]=t+1;
    	t += 2;
	}
    bubbleSort(arr, s);
    return 0;
}

int des(int s)
{
	int arr[s];
    int t = 1;
    for (int i = 0; t < s; i++)
	{
    	arr[i]=s-t;
    	arr[s-1-i]=s-t+1;
    	t += 2;
	}
	bubbleSort(arr, s);
    return 0;
}

int main() {
	int s = 0;
	cout << "size random" << endl; //constant increasing decreasing ascending descending\n";
	for (int j = 0; j < 15; j++)
    {
    s += 3000;
    
	auto rms = steady_clock::now();
    ran(s);
    auto rme = steady_clock::now();
    /*
	auto cts = steady_clock::now();
    con(s);
    auto cte = steady_clock::now();
	auto igs = steady_clock::now();
    inc(s);
    auto ige = steady_clock::now();
    auto dgs = steady_clock::now();
    dec(s);
    auto dge = steady_clock::now();
    auto ags = steady_clock::now();
    asc(s);
    auto age = steady_clock::now();
    auto dss = steady_clock::now();
    des(s);
    auto dse = steady_clock::now();
    */
    auto ran = duration_cast<microseconds>(rme - rms);
    /*
    auto con = duration_cast<microseconds>(cte - cts);
    auto inc = duration_cast<microseconds>(ige - igs);
    auto dec = duration_cast<microseconds>(dge - dgs);
    auto asc = duration_cast<microseconds>(age - ags);
    auto des = duration_cast<microseconds>(dse - dss);
    */
    
    cout << s << " " << ran.count() << endl;// << " " << con.count() << " " << inc.count() << " " << dec.count() << " " << asc.count() << " " << des.count() << endl;
	}
	return 0;
}
