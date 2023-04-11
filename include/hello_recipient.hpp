#include <eosio/eosio.hpp>

using namespace eosio;
using namespace std;

class [[eosio::contract]] hello_recipient : public contract
{
public:
   using contract::contract;

   [[eosio::action]] void hi(name user, string msg);

   [[eosio::action]] void notify(name user, string msg);

   using hi_action = action_wrapper<"hi"_n, &hello_recipient::hi>;

   using notify_action = action_wrapper<"notify"_n, &hello_recipient::notify>;

private:
   void send_summary(name user, string message)
   {
      action(
          permission_level{get_self(), "active"_n},
          get_self(),
          "notify"_n,
          make_tuple(user, user.to_string() + message))
          .send();
   };
};