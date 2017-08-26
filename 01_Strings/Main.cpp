#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

void tStrings()
{
    std::string a, b;
    std::cin >> a >> b;

    std::cout << a.size() << " " << b.size() << std::endl;
    std::cout << a + b << std::endl;

    char swap = a[0];
    a[0] = b[0];
    b[0] = swap;
    std::cout << a << " " << b;
}

std::vector<int> parseInts(std::string str)
{
    std::vector<int> result;
    std::stringstream ss(str);
    int a;
    char c;
    while (!ss.eof())
    {        
        ss >> a >> c;
        result.push_back(a);
    }
    return result;
}

void tStringStream()
{
    // Defult main function from HackerRank:
    std::string str;
    std::cin >> str;
    std::vector<int> integers = parseInts(str);
    for (int i = 0; i < integers.size(); i++) {
        std::cout << integers[i] << "\n";
    }
}

struct Tag
{
    std::string name;
    std::map<std::string, std::string> attributes;
    std::map<std::string, Tag> children;
    Tag* parent = nullptr;
};

void printHRML(std::map<std::string, Tag> HRML, int level = 0)
{
    for (auto &tagIter : HRML)
    {
        std::cout << std::string(level, '-') << tagIter.first << " - ";
        Tag currentTag = tagIter.second;
        for (auto attributeIter : currentTag.attributes)
        {
            std::cout << attributeIter.first << " : " << attributeIter.second << ", ";
        }
        std::cout << std::endl;
        printHRML(tagIter.second.children, level + 2);
    }
}

std::vector<std::string> splitQuery(std::string query)
{
    std::vector<std::string> result;
    std::string temp = "";
    for (auto c : query)
    {
        if (c == '.' || c == '~')
        {
            result.push_back(temp);
            result.push_back(std::string(1,c));
            temp = "";
        }
        else
        {
            temp += c;
        }
    }
    result.push_back(temp);
    return result;
}

void tAttributeParser(std::istream& inputStream = std::cin)
{
    int N, Q;
    inputStream >> N >> Q;
    std::map<std::string, Tag> HRML;

    // Parse HRML
    Tag* currentTag = nullptr;
    std::string temp;
    for (size_t i = 0; i < N; i++)
    {
        inputStream >> temp;
        if (temp[1] == '/')
        {
            currentTag = currentTag->parent;
        }
        else
        {
            bool lastAttribute = false;
            std::string tagName = temp.substr(1);
            if (tagName.back() == '>')
            {
                tagName.pop_back();
                lastAttribute = true;
            }
            Tag createTag{ tagName };

            if (currentTag == nullptr)
            {
                HRML.emplace(tagName, createTag);
                currentTag = &HRML[tagName];
            }
            else
            {
                createTag.parent = currentTag;
                currentTag->children.emplace(tagName, createTag);
                currentTag = &currentTag->children[tagName];
            }

            std::string attribute, value;
            while (!lastAttribute)
            {
                inputStream >> attribute >> temp >> value;
                if (value.back() == '>')
                {
                    value.pop_back();
                    lastAttribute = true;
                }
                value.pop_back();
                currentTag->attributes.emplace(std::make_pair(attribute, value.substr(1)));
            }
        }
    }
    //printHRML(HRML);

    // Execute Queries
    std::vector<std::string> *queries = new std::vector<std::string>[Q];
    for (size_t i = 0; i < Q; i++)
    {
        std::string query;
        inputStream >> query;
        std::vector<std::string> queryElements = splitQuery(query);
        queries[i] = queryElements;
    }
     
    for (size_t i = 0; i < Q; i++)
    {
        std::vector<std::string> query = queries[i];

        if (HRML.find(query[0]) != HRML.end())
        {
            currentTag = &HRML[query[0]];
        }
        else
        {
            std::cout << "Not Found!" << std::endl;
            continue;
        }

        for (size_t i = 1; i < query.size(); i += 2)
        {
            std::string symbol = query[i];
            std::string elementName = query[i + 1];

            if (symbol == ".")
            {
                if (currentTag->children.find(elementName) != currentTag->children.end())
                {
                    currentTag = &currentTag->children[elementName];
                }
                else
                {
                    std::cout << "Not Found!" << std::endl;
                    break;
                }
            }
            else if (symbol == "~")
            {
                if (currentTag->attributes.find(elementName) != currentTag->attributes.end())
                {
                    std::cout << currentTag->attributes[elementName] << std::endl;
                }
                else
                {
                    std::cout << "Not Found!" << std::endl;
                    break;
                }
            }
        }
    }
}

int main()
{
    //tStrings();
    //tStringStream();
    //tAttributeParser();
    //tAttributeParser(std::ifstream("AttributeParser_4.in"));

    return 0;
}