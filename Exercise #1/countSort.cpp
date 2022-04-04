#include <algorithm>
#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

void countSort(vector<int>& arr)
{
	int max = *max_element(arr.begin(), arr.end());
    int min = *min_element(arr.begin(), arr.end());
    int range = max - min + 1;
  
    vector<int> count(range), output(arr.size());
    for (int i = 0; i < arr.size(); i++)
        count[arr[i] - min]++;
  
    for (int i = 1; i < count.size(); i++)
        count[i] += count[i - 1];
  
    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[arr[i] - min] - 1] = arr[i];
        count[arr[i] - min]--;
    }
  
    for (int i = 0; i < arr.size(); i++)
        arr[i] = output[i];
}


int ran(int s)
{
	srand( (unsigned)time( NULL ) );
	int arr[s];
    for (int i = 0; i < s; i++)
    	arr[i]=rand();
    vector<int> array(arr, arr + sizeof(arr) / sizeof(int));
    countSort(array);
    return 0;
}

int con(int s)
{
	int arr[s];
    for (int i = 0; i < s; i++)
    	arr[i]=0;
    vector<int> array(arr, arr + sizeof(arr) / sizeof(int));
    countSort(array);
    return 0;
}

int inc(int s)
{
	int arr[s];
    for (int i = 0; i < s; i++)
    	arr[i]=i;
    vector<int> array(arr, arr + sizeof(arr) / sizeof(int));
    countSort(array);
    return 0;
}

int dec(int s)
{
	int arr[s];
    for (int i = 0; i < s; i++)
    	arr[i]=-i;
	vector<int> array(arr, arr + sizeof(arr) / sizeof(int));
    countSort(array);
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
    vector<int> array(arr, arr + sizeof(arr) / sizeof(int));
    countSort(array);
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
	vector<int> array(arr, arr + sizeof(arr) / sizeof(int));
    countSort(array);
    return 0;
}

int main() {
	int s = 0;
	cout << "size random constant increasing decreasing ascending descending\n";
	for (int j = 0; j < 15; j++)
    {
    s += 5000;
    
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
