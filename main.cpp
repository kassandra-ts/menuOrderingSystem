//
// File: main.cpp
// Author: Kassandra Tovar
// Topic: Menu ordering system
//


#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
// error message if non ordered items try to be removed
void update(bool del, int& cnt) {
   if (del)
      if (cnt > 0)
         --cnt;
      else
         std::cout << "Item cannot be removed. You don't have any ordered!\n";
   else
      ++cnt;
}
int main() {
   //item price
   const double
      burger_price = 9.00,
      fries_price = 2.75,
      drink_price = 2.5,
      salad_price = 12,
      ice_price = 1.99;

   //item calories
   const int
      burger_cal = 500,
      fries_cal = 300,
      drink_cal = 200,
      salad_cal = 400,
      ice_cal = 400;

   //menu options
   enum menu { burger = 'b', fries = 'f', drink = 'd', salad = 's', ice_cream = 'i', clear = 'c', order = 'o', quit = 'q' };
    // b adds a burger
    // f adds fries
    // d adds a drink
    // s adds a salad
    // i adds ice cream
    // c clears entire order
    // o completes your order and shows total price
    // q quits program

   //counters
   menu menuChoice {};
   int b_count {}, f_count {}, d_count {}, s_count {}, i_count {};

   cout << "Place your order from Kassandra T's Burger Joint. This app shows your calories and cost \nas you add items to your food order. You can clear, order, remove, or quit at any time.\n";
   cout << "\nCurrent order: b)urger:" << b_count << " f)ries:" << f_count << " d)rink:" << d_count << " s)alad:" <<
      s_count << " i)ce cream:" << i_count << " TOTAL calories:" << 0 << " cost:$" << 0 << '\n';

   while (menuChoice != quit && menuChoice != order) {
      char choice {};
      bool del {};
      cout << "Choose: b)urger f)ries d)rink s)alad, i)ce cream, c)lear, o)order, q)uit (- to remove item): ";
      cin >> choice;

      if (choice == '-') {
         del = true;
         cin >> choice;
      }
      menuChoice = static_cast<menu>(choice);
      switch (menuChoice) {
         case burger:
            update(del, b_count);
            break;
            
         case fries:
            update(del, f_count);
            break;
            
         case drink:
            update(del, d_count);
            break;

         case salad:
            update(del, s_count);
            break;

         case ice_cream:
            update(del, i_count);
            break;

         case clear:
            b_count = d_count = s_count = f_count = i_count = 0;
            break;

         case order:
         {
            const auto totalPrice {burger_price * b_count + fries_price * f_count + drink_price * d_count + salad_price * s_count + ice_price * i_count};
            cout << "\nThank you for your order! Your total comes to: $" << totalPrice << endl << "Good-bye. Thank you for giving us the opportunity to serve you." << '\n';
         }
            break;
            
         case quit:
            std::cout << "Sorry you decided not to order. Please try us again!" << '\n';
            break;

         default:
            std::cout << "\nUnknown order! Please choose something from the menu..\n";
            break;
      }
// print following message then quit when o or q are entered
      if (menuChoice != quit && menuChoice != order) {
         const auto totalPrice = burger_price * b_count + fries_price * f_count + drink_price * d_count + salad_price * s_count + ice_price * i_count;
         const auto totalCal = burger_cal * b_count + fries_cal * f_count + drink_cal * d_count + salad_cal * s_count + ice_cal * i_count;

         cout << "\nCurrent order: b)urger:" << b_count << " f)ries:" << f_count << " d)rink:" << d_count << " s)alad:" <<
            s_count << " i)ce cream:" << i_count << " TOTAL calories:" << totalCal << " cost:$" << totalPrice << '\n';
      }
   }
}

/* sample output:
Place your order from Kassandra T's Burger Joint. This app shows your calories and cost 
as you add items to your food order. You can clear, order, remove, or quit at any time.

Current order: b)urger:0 f)ries:0 d)rink:0 s)alad:0 i)ce cream:0 TOTAL calories:0 cost:$0
Choose: b)urger f)ries d)rink s)alad, i)ce cream, c)lear, o)order, q)uit (- to remove item): b

Current order: b)urger:1 f)ries:0 d)rink:0 s)alad:0 i)ce cream:0 TOTAL calories:500 cost:$9
Choose: b)urger f)ries d)rink s)alad, i)ce cream, c)lear, o)order, q)uit (- to remove item): f

Current order: b)urger:1 f)ries:1 d)rink:0 s)alad:0 i)ce cream:0 TOTAL calories:800 cost:$11.75
Choose: b)urger f)ries d)rink s)alad, i)ce cream, c)lear, o)order, q)uit (- to remove item): d

Current order: b)urger:1 f)ries:1 d)rink:1 s)alad:0 i)ce cream:0 TOTAL calories:1000 cost:$14.25
Choose: b)urger f)ries d)rink s)alad, i)ce cream, c)lear, o)order, q)uit (- to remove item): s

Current order: b)urger:1 f)ries:1 d)rink:1 s)alad:1 i)ce cream:0 TOTAL calories:1400 cost:$26.25
Choose: b)urger f)ries d)rink s)alad, i)ce cream, c)lear, o)order, q)uit (- to remove item): i

Current order: b)urger:1 f)ries:1 d)rink:1 s)alad:1 i)ce cream:1 TOTAL calories:1800 cost:$28.24
Choose: b)urger f)ries d)rink s)alad, i)ce cream, c)lear, o)order, q)uit (- to remove item): l

Unknown order! Please choose something from the menu..

Current order: b)urger:1 f)ries:1 d)rink:1 s)alad:1 i)ce cream:1 TOTAL calories:1800 cost:$28.24
Choose: b)urger f)ries d)rink s)alad, i)ce cream, c)lear, o)order, q)uit (- to remove item): b

Current order: b)urger:2 f)ries:1 d)rink:1 s)alad:1 i)ce cream:1 TOTAL calories:2300 cost:$37.24
Choose: b)urger f)ries d)rink s)alad, i)ce cream, c)lear, o)order, q)uit (- to remove item): c

Current order: b)urger:0 f)ries:0 d)rink:0 s)alad:0 i)ce cream:0 TOTAL calories:0 cost:$0
Choose: b)urger f)ries d)rink s)alad, i)ce cream, c)lear, o)order, q)uit (- to remove item): b

Current order: b)urger:1 f)ries:0 d)rink:0 s)alad:0 i)ce cream:0 TOTAL calories:500 cost:$9
Choose: b)urger f)ries d)rink s)alad, i)ce cream, c)lear, o)order, q)uit (- to remove item): b

Current order: b)urger:2 f)ries:0 d)rink:0 s)alad:0 i)ce cream:0 TOTAL calories:1000 cost:$18
Choose: b)urger f)ries d)rink s)alad, i)ce cream, c)lear, o)order, q)uit (- to remove item): o

Thank you for your order! Your total comes to: $18
Good-bye. Thank you for giving us the opportunity to serve you.
*/

/* sample output to test quit option:
Place your order from Kassandra T's Burger Joint. This app shows your calories and cost 
as you add items to your food order. You can clear, order, remove, or quit at any time.

Current order: b)urger:0 f)ries:0 d)rink:0 s)alad:0 i)ce cream:0 TOTAL calories:0 cost:$0
Choose: b)urger f)ries d)rink s)alad, i)ce cream, c)lear, o)order, q)uit (- to remove item): q
Sorry you decided not to order. Please try us again! */
