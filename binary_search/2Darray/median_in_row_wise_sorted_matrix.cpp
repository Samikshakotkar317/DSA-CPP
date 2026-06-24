/*
leetcode format

class Solution{
    int upperBound(vector<int>&mat, int m, int x){
        int low = 0;
        int high = m - 1;
        int ind = m;
        while(low <= high){
            int mid = (low + high)/2;
            if(mat[mid] > x){
                ind = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1; //look for right
            }
        }
        return ind;
    }
    
    // to find how many smaller elements then x
    int blackbox(vector<vector<int>>&mat,int n, int m, int x){
        int cnt = 0;
        for(int i = 0; i < n; i++){
            cnt += upperBound(mat[i], m, x);
        }
        return cnt;
    }
public:
    int findMedian(vector<vector<int>>&matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int low = INT_MAX;
        int high = INT_MIN;
        for(int i = 0; i < n; i++){
            low = min(low, matrix[i][0]);
            high = max(high, matrix[i][m-1]);
        }
        int required = (n * m) / 2;
        while(low <= high){
            int mid = (low + high)/2;
            int smallerEquals = blackbox(matrix, n, m, mid);
            if(smallerEquals <= required){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return low;
    }
};

*/

#include <bits/stdc++.h>
using namespace std;

// upper bound: first index where value > x
int upperBound(vector<int>& row, int m, int x){
    int low = 0, high = m - 1;
    int ind = m;

    while(low <= high){
        int mid = low + (high - low)/2;

        if(row[mid] > x){
            ind = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ind;
}

// count elements <= x in matrix
int blackbox(vector<vector<int>>& mat, int n, int m, int x){
    int cnt = 0;
    for(int i = 0; i < n; i++){
        cnt += upperBound(mat[i], m, x);
    }
    return cnt;
}

int main(){
    vector<vector<int>> matrix = {
        {1, 5, 7, 9, 11},
        {2, 3, 4, 5, 10},
        {9, 10, 12, 14,16}
    };

    int n = matrix.size();
    int m = matrix[0].size();

    int low = INT_MAX;
    int high = INT_MIN;

    // find min and max in matrix
    for(int i = 0; i < n; i++){
        low = min(low, matrix[i][0]);
        high = max(high, matrix[i][m - 1]);
    }

    int required = (n * m) / 2;

    // binary search on answer
    while(low <= high){
        int mid = low + (high - low)/2;

        int smallerEquals = blackbox(matrix, n, m, mid);

        if(smallerEquals <= required){
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << "Median is: " << low << endl;

    return 0;
}