#include <cstdlib>
#include <iostream>

using namespace std;

class money_t  {

   private:
      int dollars;
      int cents;

   public:
      money_t();

      money_t(double amt);

      // PROTOTYPE FOR THIRD CONSTRUCTOR GOES HERE 
	money_t(int d, int c);
      
      ~money_t();
   
      int get_dollars( );
      int get_cents();
      void set_dollars(int dollars_amt);
      void set_cents(int cents_amt);
      void set(int dollar_amt, int cent_amt);
      int value_in_cents();
      double compute_value();
};

