#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'maxRegion' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY grid as parameter.
 */

int call_dfs(int x, int y, vector<vector<int>> grid, vector<vector<int>> &visited, int &count, int n, int m){
    if(visited[x][y]){
        return 0;
    }
    visited[x][y] = true;
    count++;
    // cout<<"this is final"<<endl;
    int rd[8] = {-1,-1,-1,0,1,1,1,0};
    int cd[8] = {-1,0,1,1,1,0,-1,-1};
    for(int i = 0; i<8; i++){
        int nx = x + rd[i];
        int ny = y + cd[i];
        if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny] == 1 && !visited[nx][ny]){
            call_dfs(nx, ny, grid, visited, count, n, m);
        }
    }
    return count;
}

int maxRegion(vector<vector<int>> grid, int n, int m) {
    vector<vector<int>> visited(n, vector<int> (m));
    int connected_component = 0;
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            visited[i][j] = false;
            // cout<<visited[i][j]<<" ";
        }
        // cout<<endl;
    }
    int max_count = INT_MIN;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(grid[i][j] == 1 && !visited[i][j]){
                int count = 0;
                // cout<<"i->"<<i<<"j->"<<j<<endl;
                count = call_dfs(i,j, grid, visited, count, n, m);
                // for(int i = 0; i<n; i++){
                //     for(int j = 0; j<m; j++){
                //         // visited[i][j] = false;
                //         cout<<visited[i][j]<<" ";
                //     }
                //     cout<<endl;
                // }
                // cout<<"this->"<<count<<endl;
                max_count = max(max_count, count);
            }
            else{
                visited[i][j] = true;
            }
        }
    }
    return max_count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string m_temp;
    getline(cin, m_temp);

    int m = stoi(ltrim(rtrim(m_temp)));

    vector<vector<int>> grid(n);

    for (int i = 0; i < n; i++) {
        grid[i].resize(m);

        string grid_row_temp_temp;
        getline(cin, grid_row_temp_temp);

        vector<string> grid_row_temp = split(rtrim(grid_row_temp_temp));

        for (int j = 0; j < m; j++) {
            int grid_row_item = stoi(grid_row_temp[j]);

            grid[i][j] = grid_row_item;
        }
    }

    int res = maxRegion(grid, n, m);

    fout << res << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
