#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Spell {
private:
    string scrollName;
public:
    Spell() : scrollName("") { }
    Spell(string name) : scrollName(name) { }
    virtual ~Spell() { }
    string revealScrollName() {
        return scrollName;
    }
};

class Fireball : public Spell {
private: int power;
public:
    Fireball(int power) : power(power) { }
    void revealFirepower() {
        cout << "Fireball: " << power << endl;
    }
};

class Frostbite : public Spell {
private: int power;
public:
    Frostbite(int power) : power(power) { }
    void revealFrostpower() {
        cout << "Frostbite: " << power << endl;
    }
};

class Thunderstorm : public Spell {
private: int power;
public:
    Thunderstorm(int power) : power(power) { }
    void revealThunderpower() {
        cout << "Thunderstorm: " << power << endl;
    }
};

class Waterbolt : public Spell {
private: int power;
public:
    Waterbolt(int power) : power(power) { }
    void revealWaterpower() {
        cout << "Waterbolt: " << power << endl;
    }
};

class SpellJournal {
public:
    static string journal;
    static string read() {
        return journal;
    }
};
string SpellJournal::journal = "";

void counterspell(Spell *spell)
{
    struct
    {
        int operator()(string a, string b)
        {
            //if (a.size() == 0 || b.size() == 0)
            //{
            //    return 0;
            //}
            //if (a[0] == b[0])
            //{
            //    return 1 + (*this)(a.substr(1), b.substr(1));
            //}
            //return max((*this)(a.substr(1), b), (*this)(a, b.substr(1)));

            vector<vector<int>> DP(a.size() + 1, vector<int>(b.size() + 1));
            for (size_t i = 0; i <= a.size(); i++)
            {
                for (size_t j = 0; j <= b.size(); j++)
                {
                    if (i == 0 || j == 0)
                    {
                        DP[i][j] = 0;
                    }
                    else
                    {
                        DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
                        if (a[i - 1] == b[j - 1])
                        {
                            DP[i][j] = max(DP[i][j], DP[i - 1][j - 1] + 1);
                        }
                    }
                }
            }
            return DP.back().back();
        }
    } longestSubSequence;

    Fireball* fire = dynamic_cast<Fireball*>(spell);
    Frostbite* frost = dynamic_cast<Frostbite*>(spell);
    Thunderstorm* thunder = dynamic_cast<Thunderstorm*>(spell);
    Waterbolt* water = dynamic_cast<Waterbolt*>(spell);

    if (fire != nullptr)
    {
        fire->revealFirepower();
    }
    else if (frost != nullptr)
    {
        frost->revealFrostpower();
    }
    else if (thunder != nullptr)
    {
        thunder->revealThunderpower();
    }
    else if (water != nullptr)
    {
        water->revealWaterpower();
    }
    else
    {
        string scrollName = spell->revealScrollName();
        cout << longestSubSequence(scrollName, SpellJournal::journal) << endl;
    }
}

class Wizard {
public:
    Spell *cast() {
        Spell *spell;
        string s; cin >> s;
        int power; cin >> power;
        if (s == "fire") {
            spell = new Fireball(power);
        }
        else if (s == "frost") {
            spell = new Frostbite(power);
        }
        else if (s == "water") {
            spell = new Waterbolt(power);
        }
        else if (s == "thunder") {
            spell = new Thunderstorm(power);
        }
        else {
            spell = new Spell(s);
            cin >> SpellJournal::journal;
        }
        return spell;
    }
};