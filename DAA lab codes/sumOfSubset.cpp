#include <iostream>
#include <stack>
using namespace std;
const int MAX_N = 100;
int a[MAX_N];
int n, target;
bool found = false;
stack<int> orig, temp;

void bubbleSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
void print()
{
    while (!orig.empty())
    {
        temp.push(orig.top());
        orig.pop();
    }
    while (!temp.empty())
    {
        cout << temp.top() << ",";
        orig.push(temp.top());
        temp.pop();
    }
    cout << "\n";
}
void solve(int currsum, int index)
{
    if (currsum > target)
        return;
    if (currsum == target)
    {
        print();
        found = true;
        return;
    }
    for (int i = index; i < n; i++)
    {
        orig.push(a[i]);
        solve(currsum + a[i], i + 1);
        orig.pop();
    }
}
int main()
{
    cout << "Enter the number of elements: "<<endl;
    cin >> n;
    cout<<"---------------------------------------"<<endl;
    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout<<"---------------------------------------"<<endl;
    cout << "Enter the target sum: "<<endl;
    cin >> target;

    bubbleSort(a, n);

    solve(0, 0);
    if (!found)
        cout << "No solution";
    return 0;
}