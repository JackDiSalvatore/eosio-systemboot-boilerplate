#include "hello.hpp"


void hello::hi( name user ) {
   require_auth( user );
}

void hello::update( bool freeze ) {
   require_auth( _self );
   set_frozen( freeze );
}

void hello::checkfrozen() {
   assert_frozen( _self );
}

// traditional dispatch macro
// EOSIO_DISPATCH( hello, (hi) )

extern "C" {
   void apply( uint64_t receiver, uint64_t code, uint64_t action ) {
      // hello _hello(receiver);
      //auto self = receiver;

      /****************************************************************************
       *  ACTION HANDLERS
      ***************************************************************************/
      if (code != receiver) return;

      // Runs for every actions that is not "update"
      if( code==receiver && action != name("update").value ) {
         execute_action( name(receiver), name(code), &hello::checkfrozen );
      }
      if( code==receiver && action== name("update").value ) {
         execute_action( name(receiver), name(code), &hello::update );
      }
      // else if(code==receiver && action== name("notify").value) {
      //   execute_action(name(receiver), name(code), &hello::notify );
      // }
      else if( code==receiver && action== name("hi").value ) {
         execute_action( name(receiver), name(code), &hello::hi );
      }
      /*else if( code==receiver && action== name("safetransfer").value ) {
         execute_action( name(receiver), name(code), &hello::safetransfer );
      }*/
      /*eosio_exit(0);*/
   }
};
