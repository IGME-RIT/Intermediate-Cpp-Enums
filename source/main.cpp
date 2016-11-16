/*
Enums
(c) 2016
Author: David Erbelding
Written under the supervision of David I. Schwartz, Ph.D., and
supported by a professional development seed grant from the B. Thomas
Golisano College of Computing & Information Sciences
(https://www.rit.edu/gccis) at the Rochester Institute of Technology.
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or (at
your option) any later version.
This program is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

// Include iostream for output during the program.
#include <iostream>
using namespace std;

// Sometimes, you'll want to store a single variable to store information that could be one of many things.
// For example, you might have a character with many states, i.e. idle, running, jumping, falling, attacking etc.
// The simplest way to do this, would be to assign each one a number:
// Standing = 0, running = 1, jumping = 2, falling = 3, attacking = 4.
// These numbers can be hard to keep track of, which is why C++ has enums. (short for enumerations)

int main() 
{
    {
        // The oldschool C way of using enums is with #define.
        // It's not recommended that you do this, but you may encounter these at some point, so they're worth mentioning.

        #define IDLE 0;         // #define replaces all instances of IDLE in your code with 0.
        #define RUNNING 1;      // This happens before your code is compiled.
        #define JUMPING 2;      // Enums are commonly named with caps to identify them as constants.
        #define FALLING 3;
        #define ATTACKING 4;

        // Then using those constatns in your code later on.
        int state = IDLE;
        cout << "state: " << state << endl;

        // This works fine, but has some problems.
        // Firstly, it's hard for me to make sure that my enums don't overlap.
        // If I have more than 100 #defines, it's going to be hard to keep track of them.

        // Someone could easily just use a number instead of the define:
        state = 5;
        // Then, if the number of the define changes, that code would break.
    }
    cin.get();

    {
        // C and C++ have both improved on this slightly, by introducing enum declarations.

        // This allows us to avoid assigning a value that could change to each constant.
        // You still can if you want to, (see b) but you don't have to.
        enum { R, G, B = 3 };

        // Print out each value to see what it is:
        cout << "R: " << R << endl; // 0
        cout << "G: " << G << endl; // 1
        cout << "B: " << B << endl; // 3
        
        // Unfortunately, this still doesnt solve our type safetly problem.
        // It's still possiple to store an enum as an type, or store any time in a variable meant for an enum.

        int testEnum = R;   // Makes sense.
        testEnum = -5;      // Wait what?

        float x = R;        // What does this even mean?

        
    }
    cin.get();

    {
        // C++ adds an improvement to this, by allowing you to declare your enums with a type identifier:
        enum Element { FIRE = 0, WATER, EARTH, AIR, WUMBO };
        // Each of these values is now unique const variable we can read from, and c.

        // Now we can store a state in an object of this type.
        Element a = FIRE;

        // We can even store our enum type as an integer.
        int b = WATER;

        //      What you can't do, is write a value of a different type.
        // Element c = 3;  // This won't compile.

        enum Flavor { VANILLA, CHOCOLATE, STRAWBERRY, COFFEE, MAPLE };

        //      Not allowed
        // Element d = CHOCOLATE;

        cout << "CHOCOLATE: " << CHOCOLATE << endl;

    }
    cin.get();


    {
        // One more thing, we can use enums as bitfields to store a bunch of booleans
        enum Toppings { CHEESE = 1, PEPPERONI = 2, ONIONS = 4, OLIVES = 8, PINEAPPLE = 16 };
        
        // Using bitwise or, we can combine our values into one number that stores the data of each bit as a boolean.
        int pizza = CHEESE | PEPPERONI | OLIVES;

        //  0001 cheese = 1
        //  0010 pepperoni = 2
        //  1000 olives = 8
        //->1011 all three = 11
        cout << pizza << endl;

        // You'll notice that we're storing our combined variable as an integer.
        // Unfortunately, we have to do this, because the bitwise or casts our enums to integers, and they can't be easily converted back.
        // This isn't a huge problem, but it is a weakness of using enums for bitfields, because it eliminates the type safety that the enum had.
    }
    cin.get();


    return 0;   // End Program.
}