#include <iostream>
#include <chrono>
using namespace std::chrono;
using namespace std;

void heapify(std::vector<int> &arr, int n, int i){
    int largest = i;
    int l = 2*i+1;
    int r = 2*i+2;
    if(l < n && arr[l] > arr[largest]){
        largest = l;
    }
    if(r < n && arr[r] > arr[largest]){
        largest = r;
    }
    if(largest != i){
        int tmp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = tmp;
        heapify(arr, n, largest);
    }
}

void heapSort(std::vector<int> &arr){
    int i, tmp;
    for(i = arr.size()/2-1; i >= 0; i--){
        heapify(arr, arr.size(), i);
    }
    for(i = arr.size()-1; i >= 0; i--){
        tmp = arr[0];
        arr[0] = arr[i];
        arr[i] = tmp;
        heapify(arr, i, 0);
    }
}

int ran(int s)
{
	srand( (unsigned)time( NULL ) );
	int arr[s];
    for (int i = 0; i < s; i++)
    	arr[i]=rand();
    heapSort(arr, s);
    return 0;
}

int con(int s)
{
	int arr[s];
    for (int i = 0; i < s; i++)
    	arr[i]=0;
    heapSort(arr, s);
    return 0;
}

int inc(int s)
{
	int arr[s];
    for (int i = 0; i < s; i++)
    	arr[i]=i;
    heapSort(arr, s);
    return 0;
}

int dec(int s)
{
	int arr[s];
    for (int i = 0; i < s; i++)
    	arr[i]=-i;
	heapSort(arr, s);
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
    heapSort(arr, s);
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
	heapSort(arr, s);
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
