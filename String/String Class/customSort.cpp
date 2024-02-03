#include <bits/stdc++.h>
using namespace std;

// assume 'a' is present at a lower position than 'b'
// return true when swap is not needed else return false
bool myLengthComparator(string a , string b){
    if(a.length() < b.length()){
        return true;
    }
    return false;
}

bool myGreaterComparator(int a , int b){  // custom function to sort in decreasing order
    if(a>b){
        return true;
    }
    return false;
}

bool myComparator(string a , string b){
    if(a > b){
        return true;
    }
    return false;
}

int main()
{
    string arr[] = {"abc", "jkl", "ghi", "def"};
    int n = 4;

    sort(arr, arr + n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " " ;
    }

    cout << endl<< "--------------------------------------------------------" << endl;

    // sorting in reverse order i.e descending order
    reverse(arr, arr + n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " " ;
    }

    cout<< endl << "--------------------------------------------------------" << endl;

    string brr[] = {"abcd" ,"ab", "cd" ,"d"}; // sorting based on length
    int bn = sizeof(brr)/sizeof(string);
    sort(brr , brr + bn , myLengthComparator);
    cout << "sorting based on length :" << endl;
    for (int i = 0; i < bn; i++)
    {
        cout << brr[i] << " " ;
    }

    cout << endl << "using custom sort function :" << endl;
    
    sort(brr , brr+bn , myComparator);
    // sort(brr, brr+n, greater<string>());

    for (int i = 0; i < bn; i++)
    {
        cout << brr[i] << " " ;
    }


    cout<< endl << "--------------------------------------------------------" << endl;

    int crr[] = {100, 20, 17, 250, 100};

	int cn = 5;

	sort(crr, crr+cn, myGreaterComparator);  // decreasing order custom sorting
	// sort(drr, drr+n, greater<int>());

	for(int i=0; i<cn; i++) {
		cout << crr[i] << " ";
	}
    cout<< endl << "--------------------------------------------------------" << endl;



}