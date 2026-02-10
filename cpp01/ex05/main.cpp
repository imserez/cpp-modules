#include "Harl.hpp"

int main(void)
{
    Harl harly;

    harly.complain("DEBUG");
    harly.complain("INFO");
    harly.complain("WARNING");
    harly.complain("ERROR");

    harly.complain("nothing");
   
    harly.complain("DEBUG");
    harly.complain("INFO");
    harly.complain("WARNING");
    harly.complain("ERROR");
    return 0;
}