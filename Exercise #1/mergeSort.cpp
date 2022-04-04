#include <iostream>
#include <chrono>
using namespace std::chrono;
using namespace std;

void merge(int array[], int const left, int const mid, int const right)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;
  
    auto *leftArray = new int[subArrayOne],
         *rightArray = new int[subArrayTwo];
  
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];
  
    auto indexOfSubArrayOne = 0,
        indexOfSubArrayTwo = 0; 
    int indexOfMergedArray = left; 
  
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}
  
void mergeSort(int array[], int const begin, int const end)
{
    if (begin >= end)
        return;
  
    auto mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

int ran(int s)
{
	srand( (unsigned)time( NULL ) );
	int arr[s];
    for (int i = 0; i < s; i++)
    	arr[i]=rand();
    mergeSort(arr, 0, s-1);
    return 0;
}

int con(int s)
{
	int arr[s];
    for (int i = 0; i < s; i++)
    	arr[i]=0;
    mergeSort(arr, 0, s-1);
    return 0;
}

int inc(int s)
{
	int arr[s];
    for (int i = 0; i < s; i++)
    	arr[i]=i;
    mergeSort(arr, 0, s-1);
    return 0;
}

int dec(int s)
{
	int arr[s];
    for (int i = 0; i < s; i++)
    	arr[i]=-i;
	mergeSort(arr, 0, s-1);
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
    mergeSort(arr, 0, s-1);
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
	mergeSort(arr, 0, s-1);
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
