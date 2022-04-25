#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> v;
int b, Record_per_page, records;
void first_iter()
{
   for (int i = 0; i < v.size(); i += b)
   {
      for (int j = i; j < min(i + b, (int)v.size()); j++)
         sort(v[j].begin(), v[j].end());
   }
}
void external_sort()
{
   while (v.size() > 1)
   {
      vector<vector<int>> v2;

      for (int i = 0; i < v.size(); i += b - 1)
      {
         int brought_pages;
         if (v.size() - i >= b - 1)
         {
            brought_pages = b - 1;
         }
         else
            brought_pages = v.size() - i;
         int arr[brought_pages];
         for (int j = 0; j < brought_pages; j++)
         {
            arr[j] = 0;
         }
         vector<vector<int>> temp1;

         vector<int> temp;
         while (true)
         {
            int mini = 10000000;
            int ind = -1;
            for (int j = i; j < i + brought_pages; j++)
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
   cin >> b >> Record_per_page >> records;
   int i = 0;
   vector<int> temp;
   //    cout<<records<<endl;
   while (i < records)
   {
      int x;
      cin >> x;
      temp.push_back(x);
      i++;
      if (temp.size() == Record_per_page)
      {
         v.push_back(temp);
         temp.clear();
      }
   }
   if (temp.size() > 0)
      v.push_back(temp);
   first_iter();
   external_sort();
   for (auto x : v)
   {
      for (auto y : x)
         cout << y << endl;
   }
}