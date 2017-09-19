#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

struct StudentStruct
{
    int age;
    string first_name;
    string last_name;
    int standard;
};

void tStructs()
{
    StudentStruct student;
    cin >> student.age >> student.first_name >> student.last_name >> student.standard;
    cout << student.age << " " << student.first_name << " " << student.last_name << " " << student.standard;
}

class Student1
{
    int age;
    int standard;
    string first_name;
    string last_name;
public:
    int get_age() { return age; }
    void set_age(int newAge) { age = newAge; }
    int get_standard() { return standard; }
    void set_standard(int newStandard) { standard = newStandard; }
    string get_first_name() { return first_name; }
    void set_first_name(string newFirstName) { first_name = newFirstName; }
    string get_last_name() { return last_name; }
    void set_last_name(string newLastName) { last_name = newLastName; }
    string to_string()
    {
        stringstream ss;
        ss << age << "," << first_name << "," << last_name << "," << standard;
        return ss.str();
    }
};

void tClass()
{
    // Original main() code from HackerRank
    int age, standard;
    string first_name, last_name;

    cin >> age >> first_name >> last_name >> standard;

    Student1 st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);

    cout << st.get_age() << "\n";
    cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    cout << st.get_standard() << "\n";
    cout << "\n";
    cout << st.to_string();
}

class Student2
{
    int scores[5];
public:
    void input()
    {
        for (int i = 0; i < 5; i++)
        {
            cin >> scores[i];
        }
    }

    int calculateTotalScore()
    {
        int sum = 0;
        for (int i = 0; i < 5; i++)
        {
            sum += scores[i];
        }
        return sum;
    }
};

void tClassesAndObjects()
{
    // Original main() code from HackerRank
    int n; // number of students
    cin >> n;
    Student2 *s = new Student2[n]; // an array of n students

    for (int i = 0; i < n; i++) {
        s[i].input();
    }

    // calculate kristen's score
    int kristen_score = s[0].calculateTotalScore();

    // determine how many students scored higher than kristen
    int count = 0;
    for (int i = 1; i < n; i++) {
        int total = s[i].calculateTotalScore();
        if (total > kristen_score) {
            count++;
        }
    }

    // print result
    cout << count;
}

class Box
{
    int l, b, h;
public:
    Box() : l(0), b(0), h(0)
    {
    }

    Box(int length, int breadth, int height) : l(length), b(breadth), h(height)
    {
    }

    Box(const Box &other)
    {
        l = other.l;
        b = other.b;
        h = other.h;
    }

    ~Box()
    {
    }

    int getLength() { return l; }
    int getBreadth() { return b; }
    int getHeight() { return h; }

    long long CalculateVolume()
    {
        return (long long)l * (long long)b * (long long)h;
    }

    bool operator<(const Box &other)
    {
        if ((l < other.l) ||
            (l == other.l && b < other.b) ||
            (l == other.l && b == other.b && h < other.h))
        {
            return true;
        }
        return false;
    }
};

ostream& operator<<(ostream& out, Box B)
{
    out << B.getLength() << " " << B.getBreadth() << " " << B.getHeight();
    return out;
}

void tBoxIt()
{
    // Original main() from HackerRank
    int n;
    cin >> n;
    Box temp;
    for (int i = 0; i < n; i++)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            cout << temp << endl;
        }
        if (type == 2)
        {
            int l, b, h;
            cin >> l >> b >> h;
            Box NewBox(l, b, h);
            temp = NewBox;
            cout << temp << endl;
        }
        if (type == 3)
        {
            int l, b, h;
            cin >> l >> b >> h;
            Box NewBox(l, b, h);
            if (NewBox < temp)
            {
                cout << "Lesser\n";
            }
            else
            {
                cout << "Greater\n";
            }
        }
        if (type == 4)
        {
            cout << temp.CalculateVolume() << endl;
        }
        if (type == 5)
        {
            Box NewBox(temp);
            cout << NewBox << endl;
        }
    }
}

class BadLengthException : public exception
{
    string length;
public:
    BadLengthException(int l)
    {
        stringstream ss;
        ss << l;
        this->length = ss.str();
    }

    virtual const char* what() const noexcept
    {
        return length.c_str();
    }
};

// Provided as helper on HackerRank
bool checkUsername(string username) {
    bool isValid = true;
    int n = username.length();
    if (n < 5) {
        throw BadLengthException(n);
    }
    for (int i = 0; i < n - 1; i++) {
        if (username[i] == 'w' && username[i + 1] == 'w') {
            isValid = false;
        }
    }
    return isValid;
}

void tInheritedCode()
{
    // Original main() from HackerRank
    int T; cin >> T;
    while (T--) {
        string username;
        cin >> username;
        try {
            bool isValid = checkUsername(username);
            if (isValid) {
                cout << "Valid" << '\n';
            }
            else {
                cout << "Invalid" << '\n';
            }
        }
        catch (BadLengthException e) {
            cout << "Too short: " << e.what() << '\n';
        }
    }
}

// Provided as helper on HackerRank
class Server {
private:
    static int load;
public:
    static int compute(long long A, long long B) {
        load += 1;
        if (A < 0) {
            throw std::invalid_argument("A is negative");
        }
        vector<int> v(A, 0);
        int real = -1, cmplx = sqrt(-1);
        if (B == 0) throw 0;
        real = (A / B)*real;
        int ans = v.at(B);
        return real + A - B*ans;
    }
    static int getLoad() {
        return load;
    }
};
int Server::load = 0;

void tExceptionalServer()
{
    int T; cin >> T;
    while (T--) {
        long long A, B;
        cin >> A >> B;
        // Submission code start
        try
        {
            cout << Server::compute(A, B) << endl;
        }
        catch (std::bad_alloc& ba)
        {
            cout << "Not enough memory" << endl;
        }
        catch (exception& ex)
        {
            cout << "Exception: " << ex.what() << endl;
        }
        catch (...)
        {
            cout << "Other Exception" << endl;
        }
        // Submission code end
    }
    cout << Server::getLoad() << endl;
}

// Provided as helper on HackerRank
struct Node {
    Node* next;
    Node* prev;
    int value;
    int key;
    Node(Node* p, Node* n, int k, int val) :prev(p), next(n), key(k), value(val) {};
    Node(int k, int val) :prev(NULL), next(NULL), key(k), value(val) {};
};

// Provided as helper on HackerRank
class Cache {

protected:
    map<int, Node*> mp; //map the key to the node in the linked list
    int cp;  //capacity
    Node* tail; // double linked list tail pointer
    Node* head; // double linked list head pointer
    virtual void set(int, int) = 0; //set function
    virtual int get(int) = 0; //get function

};

class LRUCache : public Cache
{
public:
    LRUCache(int capacity)
    {
        this->cp = capacity;
        head = nullptr;
        tail = nullptr;
    }

    void set(int key, int value)
    {
        if (mp.count(key) == 0)
        {
            Node* newNode = new Node(key, value);
            setHead(newNode);
            mp[key] = newNode;
            if (mp.size() > cp)
            {
                Node* oldTail = tail;
                tail = tail->prev;
                tail->next = nullptr;
                mp.erase(oldTail->key);
                delete oldTail;
            }
        }
        else
        {
            Node* currentNode = mp[key];
            currentNode->value = value;
            moveToHead(currentNode);
        }
        //printFromHead();
    }

    int get(int key)
    {
        if (mp.count(key) == 1)
        {
            Node* currentNode = mp[key];
            moveToHead(currentNode);
            //printFromHead();
            return currentNode->value;
        }
        return -1;
    }

    void printFromHead()
    {
        Node* node = head;
        cout << "From head: ";
        while (node != nullptr)
        {
            cout << node->key << ":" << node->value << " -> ";
            node = node->next;
        }
        cout << endl;
    }

    void printFromTail()
    {
        Node* node = tail;
        cout << "From tail: ";
        while (node != nullptr)
        {
            cout << node->key << ":" << node->value << " -> ";
            node = node->prev;
        }
        cout << endl;
    }

    void printMp()
    {
        for (auto &item : mp)
        {
            cout << item.first << " : " << item.second->value << endl;
        }
    }
private:
    void setHead(Node* node)
    {
        if (head == nullptr)
        {
            head = node;
            tail = node;
        }
        else
        {
            head->prev = node;
            node->next = head;
            node->prev = nullptr;
            head = node;
        }
    }

    void moveToHead(Node* node)
    {
        if (node->prev != nullptr)
        {
            node->prev->next = node->next;
            if (node->next == nullptr)
            {
                tail = node->prev;
            }
            else
            {
                node->next->prev = node->prev;
            }
            setHead(node);
        }
    }
};

void tAbstractClassesPolymorphism()
{
    // Original main() from HackerRank
    int n, capacity, i;
    cin >> n >> capacity;
    LRUCache l(capacity);
    for (i = 0; i < n; i++) {
        string command;
        cin >> command;
        if (command == "get") {
            int key;
            cin >> key;
            cout << l.get(key) << endl;
        }
        else if (command == "set") {
            int key, value;
            cin >> key >> value;
            l.set(key, value);
        }
    }
}

int main()
{
    //tStructs();
    //tClass();
    //tClassesAndObjects();
    //tBoxIt();
    //tInheritedCode();
    //tExceptionalServer();
    tAbstractClassesPolymorphism();

    return 0;
}