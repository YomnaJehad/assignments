#include<iostream>
#include<fstream>
#include<string>
#include<vector>
int countSwaps=0;
using namespace std;
void swapnow(int &a, int &b)
{
  int temp=a;
  a=b;
  b=temp;

}
void MaxHeap(vector<int> &arr, int n, int i)
{
    int max = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    if (left< n && arr[left] > arr[max])
    {
      max = left;
    }

    if (right < n && arr[right] > arr[max])
    {
      max = right;
    }
    if (max != i)
    {
      countSwaps++;
      swapnow(arr[i], arr[max]);
      MaxHeap(arr, n, max);
    }
}

void Sort(vector<int> &arr, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
      MaxHeap(arr, n, i);
    }
    for (int i=n-1; i>0; i--)
    {
      swapnow(arr[0], arr[i]);
      countSwaps++;
      MaxHeap(arr, i, 0);
    }
}
void printArray(vector<int> &arr, int n)
{
    for (int i=0; i<n; ++i)
        cout << arr[i] << "\n";
}

int main()
{
  //Get the files ready
  ifstream myfile("unsorted.txt");
  cin.rdbuf(myfile.rdbuf());
  ofstream out("33927_YomnaJehad.txt");
  cout.rdbuf(out.rdbuf());
  int n=0;
  string line;
  std::vector<int> numbers;
  if (myfile.is_open())
  {
    while(getline(myfile,line)){
    numbers.push_back(atoi(line.c_str()));
  }
    myfile.close();
  }
  Sort(numbers, numbers.size());
  printArray(numbers, numbers.size());
  cout<<countSwaps<<endl;
  return 0;
}
