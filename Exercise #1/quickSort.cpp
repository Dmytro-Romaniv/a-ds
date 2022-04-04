#include <iostream>
#include <chrono>
using namespace std::chrono;
using namespace std;

void quickSort(int array[], int left, int right)
{
	if (left >= right)
		return;
	
	int pivot_ind = left + (right - left) / 2;
	int i = left, j = right;
	while (i <= j)
	{
		while (array[i] < array[pivot_ind])
		{
			i++;
		}
		while (array[j] > array[pivot_ind])
		{
			j--;
		}
		if (i <= j)
		{
			swap(array[i], array[j]);
			i++;
			j--;
		}
	}
	quickSort(array, left, i - 1);
	quickSort(array, i, right);
}

int ran(int s)
{
	srand( (unsigned)time( NULL ) );
	int arr[s];
    for (int i = 0; i < s; i++)
    	arr[i]=rand();
    quickSort(arr, 0, s-1);
    return 0;
}

int con(int s)
{
	int arr[s];
    for (int i = 0; i < s; i++)
    	arr[i]=0;
    quickSort(arr, 0, s-1);
    return 0;
}

int inc(int s)
{
	int arr[s];
    for (int i = 0; i < s; i++)
    	arr[i]=i;
    quickSort(arr, 0, s-1);
    return 0;
}

int dec(int s)
{
	int arr[s];
    for (int i = 0; i < s; i++)
    	arr[i]=-i;
	quickSort(arr, 0, s-1);
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
    quickSort(arr, 0, s-1);
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
	quickSort(arr, 0, s-1);
    return 0;
}

int main() {
	int s = 0;
	cout << "size random constant increasing decreasing ascending descending\n";
	for (int j = 0; j < 15; j++)
    {
    s += 30000;
    
	auto rms = steady_clock::now();
    ran(s);
    auto rme = steady_clock::now();
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
    
    auto ran = duration_cast<microseconds>(rme - rms);
    auto con = duration_cast<microseconds>(cte - cts);
    auto inc = duration_cast<microseconds>(ige - igs);
    auto dec = duration_cast<microseconds>(dge - dgs);
    auto asc = duration_cast<microseconds>(age - ags);
    auto des = duration_cast<microseconds>(dse - dss);
    
    cout << s << " " << ran.count() << " " << con.count() << " " << inc.count() << " " << dec.count() << " " << asc.count() << " " << des.count() << endl;
	}
	return 0;
}
