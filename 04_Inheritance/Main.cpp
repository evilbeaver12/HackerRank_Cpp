#include <iostream>
#include "Triangle.h"
#include "Rectangle.h"
#include "ABCD.h"
#include "MagicSpells.h"

using namespace std;

void tInheritanceIntroduction()
{
    // Orignal main() from HackerRank
    Isosceles isc;
    isc.isosceles();
    isc.description();
    isc.triangle();
}

void tRectangleArea()
{
    // Original main() from HackerRank
    /*
    * Declare a RectangleArea object
    */
    RectangleArea r_area;

    /*
    * Read the width and height
    */
    r_area.read_input();

    /*
    * Print the width and height
    */
    r_area.Rectangle::display();

    /*
    * Print the area
    */
    r_area.display();
}

void tMultiLevelInheritance()
{
    // Original main() from HackerRank
    Equilateral eqr;
    eqr.equilateral();
    eqr.isosceles();
    eqr.triangle();
}

void tAccessingInheritedFunctions()
{
    // Original main() from HackerRank
    D d;
    int new_val;
    cin >> new_val;
    d.check(new_val);
}

void tMagicSpells()
{
    // Original main() from HackerRank
    int T;
    cin >> T;
    Wizard Arawn;
    while (T--) {
        Spell *spell = Arawn.cast();
        counterspell(spell);
    }
}

int main()
{
    //tInheritanceIntroduction();
    //tRectangleArea();
    //tMultiLevelInheritance();
    //tAccessingInheritedFunctions();
    //tMagicSpells();

    return 0;
}