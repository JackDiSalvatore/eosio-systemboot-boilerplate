/**
 *  @file hello.hpp
 *  @author jackdisalvatore
 *  @copyright defined in LICENSE.txt
 */
#pragma once

#include <eosiolib/eosio.hpp>
#include <eosiolib/singleton.hpp>
#include <eosiolib/time.hpp>

using eosio::action;
using eosio::datastream;
using eosio::permission_level;
using eosio::print;
using eosio::name;
using eosio::time_point;
using eosio::symbol;
using eosio::singleton;
using eosio::same_payer;


CONTRACT hello : public eosio::contract {
private:

   /****************************************************************************
    *                            D A T A  T Y P E S
    ***************************************************************************/

   /*************************************************************************
   *                               T A B L E S
   *************************************************************************/

   struct setting {
     bool frozen = 0;
   };

   typedef singleton< "settings"_n, setting > settings;
   settings _settings;

   /*************************************************************************
   *                             F U N C T I O N S
   *************************************************************************/

   void assert_frozen( name user ) {
     setting app_settings = get_frozen();

     print("frozen: ", app_settings.frozen, "\n");
     eosio_assert( !app_settings.frozen, "contract frozen" );
   }

   setting get_frozen() {
      setting app_settings{ .frozen = 0 };

      return _settings.get_or_create( _self, app_settings );
   }

   void set_frozen( const bool& frozen ) {
      setting app_settings = get_frozen();
      app_settings.frozen = frozen;

      _settings.set( app_settings, _self );
   }

   bool isnewuser( name user ) {
      // get notes by using secordary key
      // auto note_index = _notes.get_index<name("getbyuser")>();
      // auto note_iterator = note_index.find(user.value);

      // return note_iterator == note_index.end();
      return 0;
   }

public:
   using contract::contract;

   // constructor
   hello( name receiver, name code, datastream<const char*> ds ):
          contract( receiver, code, ds ),
          _settings( receiver, receiver.value ) {}

   /*************************************************************************
   *                             A C T I O N S
   *************************************************************************/

   ACTION hi( name user );

   ACTION update( bool freeze );

   ACTION checkfrozen( void );

};
