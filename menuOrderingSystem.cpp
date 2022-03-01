//
//  main.cpp
// Author: Kassandra Tovar
// Course: cosc1337 section: DL5
// Lab: lab 4
// Topic: Menu ordering system
//

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
//error message is non order items try to be removed
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

   //counters
   menu menuChoice {};
   int b_count {}, f_count {}, d_count {}, s_count {}, i_count {};

   cout << "Place your order from Kassandra T's Burger Joint. This app shows your calories and cost \nas you add items to your food order. You can clear, order, remove, or quit at any time.\n";
   cout << "\nCurrent order: b)urger:" << b_count << " f)ries:" << f_count << " d)rink:" << d_count << " s)alad:" <<
      s_count << " i)ce cream:" << i_count << " TOTAL calories:" << 0 << " cost:$" << 0 << '\n';

   while (menuChoice != quit && menuChoice != order) {
      char choice {};
      bool del {};
      std::cout << "Choose: b)urger f)ries d)rink s)alad c)lear, i)ce cream, c)lear, o)order, q)uit (- to remove item): ";
      std::cin >> choice;
      if (choice == '-') {
         del = true;
         std::cin >> choice;
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
            cout << "Thank you for your order! Your total comes to: $" << totalPrice << endl << "Good-bye. Thank you for giving us the opportunity to serve you." << '\n';
         }
            break;
            
         case quit:
            std::cout << "Sorry you decided not to order. Please try us again!" << '\n';
            break;

         default:
            std::cout << "Unknown order\n";
            break;
      }
//print message then quit when o or q are entered
      if (menuChoice != quit && menuChoice != order) {
         const auto totalPrice = burger_price * b_count + fries_price * f_count + drink_price * d_count + salad_price * s_count + ice_price * i_count;
         const auto totalCal = burger_cal * b_count + fries_cal * f_count + drink_cal * d_count + salad_cal * s_count + ice_cal * i_count;

         cout << "\nCurrent order: b)urger:" << b_count << " f)ries:" << f_count << " d)rink:" << d_count << " s)alad:" <<
            s_count << " i)ce cream:" << i_count << " TOTAL calories:" << totalCal << " cost:$" << totalPrice << '\n';
      }
   }
}

