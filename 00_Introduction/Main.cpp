#include <cstdio>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <vector>

#include "Person.h"

#pragma warning(disable : 4996)

void tSayHelloWorld()
{
    std::cout << "Hello, World!";
}

void tInputAndOutput()
{
    int a, b, c;
    std::cin >> a >> b >> c;
    std::cout << (a + b + c);
}

void tBasicDataTypes()
{
    int i;
    long long l;
    char c;
    float f;
    double d;

    std::cin >> i >> l >> c >> f >> d;
    std::cout << i << "\n" << l << "\n" << c << "\n";
    std::cout << std::fixed << std::setprecision(3) << f << "\n";
    std::cout << std::fixed << std::setprecision(9) << d << std::endl;
}

void tConditionalStatements()
{
    std::string textNums[10] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
    int n;
    std::cin >> n;

    if (n <= 9)
    {
        std::cout << textNums[n];
    }
    else
    {
        std::cout << "Greater than 9";
    }
}

void tForLoop()
{
    int a, b;
    std::string textNums[10] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
    std::cin >> a >> b;

    for (int i = a; i <= b; i++)
    {
        if (i <= 9)
        {
            std::cout << textNums[i] << std::endl;
        }
        else if (i % 2 == 0)
        {
            std::cout << "even" << std::endl;
        }
        else
        {
            std::cout << "odd" << std::endl;
        }
    }
}

int max_of_four(int a, int b, int c, int d)
{
    return std::max(std::max(a, b), std::max(c, d));
}

void tFunctions()
{
    // Default main function from HackerRank:
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int ans = max_of_four(a, b, c, d);
    printf("%d", ans);
}

void update(int *a, int *b)
{
    int tempA = *a;
    int tempB = *b;
    *a = tempA + tempB;
    *b = abs(tempA - tempB);
}

void tPointer()
{
    // Default main function from HackerRank:
    int a, b;
    int *pa = &a, *pb = &b;

    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);
}

void tArraysIntroduction()
{
    int n;
    int arr[1000];
    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        std::cout << arr[i] << " ";
    }
}

void tVariableSizedArrays()
{
    int N, Q;
    std::cin >> N >> Q;
    int** arr = new int*[N];
    for (int i = 0; i < N; i++)
    {
        int n;
        std::cin >> n;
        arr[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            std::cin >> arr[i][j];
        }
    }

    for (int i = 0; i < Q; i++)
    {
        int a, b;
        std::cin >> a >> b;
        std::cout << arr[a][b] << std::endl;
    }
}

void tVirtualFunctions()
{
    // Default main function from HackerRank:
    int n, val;
    Person *per[1000];
    std::cin >> n; //The number of objects that is going to be created.

    for (int i = 0; i < n; i++)
    {
        std::cin >> val;
        if (val == 1)
        {
            per[i] = new Professor;
        }
        else
        {
            per[i] = new Student;
        }
        per[i]->getdata();
    }

    for (int i = 0; i < n; i++)
    {
        per[i]->putdata();
    }
}

int main()
{
    //tSayHelloWorld();
    //tInputAndOutput();
    //tBasicDataTypes();
    //tConditionalStatements();
    //tForLoop();
    //tFunctions();
    //tPointer();
    //tArraysIntroduction();
    //tVariableSizedArrays();
    //tVirtualFunctions();

    return 0;
}