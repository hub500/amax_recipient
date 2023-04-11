#include <hello_recipient.hpp>

void hello_recipient::hi(name user, string msg)
{
   print_f("Name : %\n", user);

   send_summary(user, msg);
}

void hello_recipient::notify(name user, string msg)
{
   require_auth(get_self());
   require_recipient(user);
}
