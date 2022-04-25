#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> v;
int x;
int records_per_page;  
int records;
void first_iter()
{
    for (int i = 0; i < v.size(); i += x)
    {
        for (int j = i; j < min(i + x, (int)v.size()); j++)
            sort(v[j].begin(), v[j].end());
    }
}
void ext_sort()
{
    while (v.size() > 1)
    {
        vector<vector<int>> v2;

        for (int i = 0; i < v.size(); i += x - 1)
        {
            int number_of_pages_brought;
            if (v.size() - i >= x - 1)
            {
                number_of_pages_brought = x - 1;
            }
            else
                number_of_pages_brought = v.size() - i;
            int arr[number_of_pages_brought];
            for (int j = 0; j < number_of_pages_brought; j++)
            {
                arr[j] = 0;
            }
            vector<vector<int>> temp1;

            vector<int> temp;
            while (true)
            {
                int mini = 10000000;
                int ind = -1;
                for (int j = i; j < i + number_of_pages_brought; j++)
                {
                    if (arr[j - i] < v[j].size())
                    {
                        if (v[j][arr[j - i]] < mini)
                        {
                            mini = min(v[j][arr[j - i]], mini);
                            ind = j - i;
                            //                            cout<<mini<<" ";
                        }
                    }
                }
                //                cout<<endl;
                if (ind == -1)
                    break;
                arr[ind]++;
                temp.push_back(mini);
            }
            v2.push_back(temp);
        }
        v = v2;
    }
}
int main()
{
    cin >> x >> records_per_page >> records;
    int i = 0;
    vector<int> temp;
    //    cout<<records<<endl;
    while (i < records)
    {
        int x;
        cin >> x;
        temp.push_back(x);
        i++;
        if (temp.size() == records_per_page)
        {
            v.push_back(temp);
            temp.clear();
        }
    }
    if (temp.size() > 0)
        v.push_back(temp);
    first_iter();
    ext_sort();
    for (auto x : v)
    {
        for (auto y : x)
            cout << y << endl;
    }
}
