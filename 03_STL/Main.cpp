#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <deque>

using namespace std;

void tVectorSort()
{
    int n;
    vector<int> v;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }

    sort(v.begin(), v.end());
    for (auto element : v)
    {
        cout << element << " ";
    }
}

void tVectorErase()
{
    int n;
    vector<int> v;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }

    int a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    c--;
    v.erase(v.begin() + a);
    v.erase(v.begin() + b, v.begin() + c);

    cout << v.size() << endl;
    for (auto element : v)
    {
        cout << element << " ";
    }
}

void tLowerBoundSTL()
{
    int N;
    cin >> N;

    vector<int> v;
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        int q;
        cin >> q;
        auto v_it = lower_bound(v.begin(), v.end(), q);
        if (*v_it == q)
        {
            cout << "Yes " << (v_it - v.begin()) + 1 << endl;;
        }
        else
        {
            cout << "No " << (v_it - v.begin()) + 1 << endl;
        }
    }
}

void tSetsSTL()
{
    int Q;
    cin >> Q;

    set<int> s;
    for (int i = 0; i < Q; i++)
    {
        int y, x;
        cin >> y >> x;
        if (y == 1)
        {
            s.insert(x);
        }
        else if (y == 2)
        {
            s.erase(x);
        }
        else if (y == 3)
        {
            if (s.find(x) != s.end())
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
    }
}

void tMapsSTL()
{
    int Q;
    cin >> Q;

    map<string, int> m;
    for (int i = 0; i < Q; i++)
    {
        int t;
        cin >> t;
        int s;
        string n;

        if (t == 1)
        {
            cin >> n >> s;
            m[n] += s;
        }
        else if (t == 2)
        {
            cin >> n;
            m.erase(n);
        }
        else if (t == 3)
        {
            cin >> n;
            cout << m[n] << endl;
        }
    }
}

void tPrintPretty()
{
    int T; cin >> T;
    cout << setiosflags(ios::uppercase);
    cout << setw(0xf) << internal;
    while (T--) {
        double A; cin >> A;
        double B; cin >> B;
        double C; cin >> C;
        // Submission code start
        cout << setw(0) << hex << left << setprecision(0) << showbase << nouppercase << (long long)A << endl;
        cout << setw(15) << fixed << right << setprecision(2) << showpos << setfill('_') << B << endl;
        cout << setw(15) << scientific << right << setprecision(9) << noshowpos << uppercase << C << endl;
        // Submission code end
    }
}

// Signature copied from HackerRank
void printKMax(int arr[], int n, int k)
{
    deque<int> dq;
    for (int i = 0; i < k; i++)
    {
        dq.push_back(arr[i]);
    }

    auto dq_it = max_element(dq.begin(), dq.end());
    int max = *dq_it;
    cout << max << " ";
    for (int i = k; i < n; i++)
    {
        dq.push_back(arr[i]);
        int pop = dq[0];
        dq.pop_front();
        if (arr[i] > max)
        {
            max = arr[i];
        }
        else if (pop == max)
        {
            dq_it = max_element(dq.begin(), dq.end());
            max = *dq_it;
        }
        cout << max << " ";
    }
    cout << endl;
}

void tDequeSTL()
{
    // Original main() from HackerRank
    int t;
    cin >> t;
    while (t > 0) {
        int n, k;
        cin >> n >> k;
        int i;
        int* arr = new int[n];
        for (i = 0; i < n; i++)
            cin >> arr[i];
        printKMax(arr, n, k);
        t--;
    }
}

int main()
{
    //tVectorSort();
    //tVectorErase();
    //tLowerBoundSTL();
    //tSetsSTL();
    //tMapsSTL();
    //tPrintPretty();
    //tDequeSTL(); // TODO compare with Editorial solution

    return 0;
}