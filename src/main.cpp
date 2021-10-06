#include <bits/stdc++.h>

using namespace std;

typedef bool (*search_function)(const string &, const string &);

map<const string, vector<pair<const string, const int>>> adj;
map<const string, string> lhs, rhs;
map<const string, bool> visited, wisited;

void load_data(const string &path) {
    string u, v;        // first city(u), second city(v)
    int w;              // distance between 'u' and 'v'
    fstream file(path); // create a file stream
    if (file.is_open()) {
        while (file >> u >> v >> w) {
            // add new edge to the adjacency list
            adj[u].push_back(make_pair(v, w));
            adj[v].push_back(make_pair(u, w));
        }
    }
}

void clear() {
    // clear the visited lists (forward, back)
    visited.clear(); wisited.clear();
    // clear the path lists (left-hand-side, right-hand-side)
    lhs.clear(); rhs.clear();
}

void print(const string &s, vector<string> &a, vector<string> &b) {
    cout << s;
    for (int i = 0; i < a.size(); i++) {
        cout << " ---> " << a[i];   // print the forward path
    }
    for (int i = 0; i < b.size(); i++) {
        cout << " <--- " << b[i];  // print the back path
    }
    cout << endl;
}

pair<bool, string> intersection() {
    // for each city check intersection point
    for (auto i = adj.begin(); i != adj.end(); i++) {
        const string key = i->first;
        if (visited[key] && wisited[key]) {
            return make_pair(true, key);
        }
    }
    return make_pair(false, "nullptr");
}

void dump(const string &a, const string &b, search_function function) {
    // call a search function
    if (function(a, b)) {
        pair<bool, string> intersect = intersection();
        vector<string> left, right;
        string s = b;
        if (intersect.first) {
            s = intersect.second;   // intersect city
            while (s != a) {        // if it's not start city, continue
                left.push_back(s);  // add a new city
                s = lhs[s];         // change to the next city
            }
            s = intersect.second;   // intersect city
            while (s != b) {        // if it's not end city, continue
                s = rhs[s];         // add a new city
                right.push_back(s); // change to the next city
            }
        } else {
            while (s != a) {
                left.push_back(s);  // add a new city
                s = lhs[s];         // change to the next city
            }
        }
        reverse(left.begin(), left.end()); // reverse the forward path
        print(a, left, right);        // print the path
    } else {
        // doesn't exist any path from a to b
        cout << "Нет пути из " << a << " в " << b << "." << endl;
    }
    clear();
}

bool depth_first_search(const string &, const string &);
bool breadth_first_search(const string &, const string &);
bool depth_limited_search(const string &, const string &, const int);
bool iterative_depth_first_search(const string &, const string &);
bool bidirectional_search(const string &, const string &);

pair<const string, search_function> search_functions[] = {
        { "Поиск в глубину", depth_first_search },
        { "Поиск в ширину", breadth_first_search },
//        { "Поиск с итеративным углублением", iterative_depth_first_search },
        { "Двунаправленный поиск", bidirectional_search }
};

int main() {
    // loading adjacency list of cities
    load_data("cities.data");
    // calculate a number of the search functions
    int n = sizeof(search_functions) / sizeof(search_functions[0]);
    // find a path from "С.Петербург" to "Житомир"
    for (int i = 0; i < n; i++) {
        cout << search_functions[i].first << ":" << endl;
        dump("С.Петербург", "Житомир", search_functions[i].second);
        cout << endl;
    }
    return 0;
}

bool depth_first_search(const string &a, const string &b) {
    // make current vertex as visited
    visited[a] = true;
    // recur for all the vertices adjacent to this vertex
    for (auto i = adj[a].begin(); i != adj[a].end(); i++) {
        const string s = i->first;
        // if an adjacent has not been visited
        if (!visited[s]) {
            lhs[s] = a;
            if (depth_first_search(s, b) || s == b) {
                return true; // path successfully found
            }
        }
    }
    return false;
}

bool breadth_first_search(const string &a, const string &b) {
    // create a queue for bfs
    queue<string> que;
    // push current vertex to the queue
    que.push(a);
    // make current vertex as visited
    visited[a] = true;
    while (!que.empty()) {
        // dequeue a vertex from queue
        const string u = que.front();
        que.pop();
        // get all adjacent vertices of the dequeued vertex u
        for (auto i = adj[u].begin(); i != adj[u].end(); i++) {
            const string v = i->first;
            // if an adjacent has not been visited
            if (!visited[v]) {
                visited[v] = true; // mark it visited
                lhs[v] = u;
                que.push(v);       // enqueue it
            }
        }
        // path successfully found
        if (u == b) return true;
    }
    return false;
}

bool depth_limited_search(const string &a, const string &b, const int limit) {
    return false;
}

bool iterative_depth_first_search(const string &a, const string &b) {
    return false;
}

bool bidirectional_search(const string &a, const string &b) {
    // create a queue for bfs
    queue<string> que, pue;
    // push start and end vertices to the queues
    que.push(a);
    pue.push(b);
    // make start and end vertices as visited
    visited[a] = true;
    wisited[b] = true;
    while (!que.empty() && !pue.empty()) {
        // dequeue a vertex from queue
        const string q = que.front();
        que.pop();
        // get all adjacent vertices of the dequeued vertex q
        for (auto i = adj[q].begin(); i != adj[q].end(); i++) {
            const string s = i->first;
            // if an adjacent has not been visited
            if (!visited[s]) {
                visited[s] = true; // mark it visited
                lhs[s] = q;
                que.push(s);       // enqueue it
            }
        }
        // dequeue a vertex from queue
        const string p = pue.front();
        pue.pop();
        // get all adjacent vertices of the dequeued vertex p
        for (auto i = adj[p].begin(); i != adj[p].end(); i++) {
            const string s = i->first;
            // if an adjacent has not been visited
            if (!wisited[s]) {
                wisited[s] = true; // mark it visited
                rhs[s] = p;
                pue.push(s);       // enqueue it
            }
        }
        // path successfully found
        if (intersection().first) return true;
    }
    return false;
}