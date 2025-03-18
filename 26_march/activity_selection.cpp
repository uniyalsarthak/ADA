#include<bits/stdc++.h>
using namespace std;

bool compare(vector<int> &a, vector<int> &b) 
{
    return a[1] < b[1];                    // Sort by end time 
}

void activitySelection(vector<vector<int>> &activities) 
{
    sort(activities.begin(), activities.end(), compare);  
    
    int lastEnd = 0;  
    cout << "Selected activities:"<<endl;
    for (int i = 0; i < activities.size(); i++) 
    { 
        if (activities[i][0] >= lastEnd) 
        { 
            cout << "[" << activities[i][0] << ", " << activities[i][1] << "]"<<endl;
            lastEnd = activities[i][1];  // Update last selected end time
        }
    }
}

int main() {
    vector<vector<int>> activities = {{1, 3}, {2, 5}, {3, 4}, {6, 8}, {5, 7}};
    activitySelection(activities);
}
