#include <bits/stdc++.h>
using namespace std;

struct Item 
{
    int weight;
    int profit;
};

bool compareItems(const Item &a, const Item &b) 
{
    double ratioA = (double)a.profit / a.weight;
    double ratioB = (double)b.profit / b.weight;
    return ratioA > ratioB;
}

double knapsackGreedy(int capacity, vector<Item> items) 
{
    sort(items.begin(), items.end(), compareItems);

    double total_profit = 0.0;
    int remaining_capacity = capacity;

    for (const Item &item : items) 
    {
        if (item.weight <= remaining_capacity) 
        {
            // Take the whole item
            remaining_capacity -= item.weight;
            total_profit += item.profit;
            cout<<total_profit<<endl;
        } 
        else 
        {
            // Take a fraction of the item to fill the remaining capacity
            total_profit += item.profit * ((double)remaining_capacity / item.weight);
            cout<<total_profit<<endl;
            break;
        }
    }
  return total_profit;
}

int main() 
{
    int capacity = 50;
    vector<Item> items = {{10, 60}, {20, 100}, {30, 120}};
    double maxValue = knapsackGreedy(capacity, items);
    cout << "Maximum profit that can be obtained: " << maxValue << endl;
    return 0;
}
