echo '========================================================================'
echo '==                          R U N  H E L L O                          =='
echo '========================================================================'
echo 'cleos push action hello hi ["dummyaccount"] -p dummyaccount'
cleos push action hello hi '["dummyaccount"]' -p dummyaccount; sleep 1

echo '== FREEZE ACCOUNT =='
echo 'cleos push action hello update ["1"] -p hello'
cleos push action hello update '["1"]' -p hello; sleep 1

echo 'test it by sending the hello action'
echo 'this should fail'
echo 'cleos push action hello hi ["dummyaccount"] -p dummyaccount'
cleos push action hello hi '["dummyaccount"]' -p dummyaccount; sleep 1

echo '== UNFREEZE ACCOUNT =='
echo 'cleos push action hello update ["0"] -p hello'
cleos push action hello update '["0"]' -p hello; sleep 1

echo 'this should work'
echo 'cleos push action hello hi ["dummyaccount"] -p dummyaccount'
cleos push action hello hi '["dummyaccount"]' -p dummyaccount; sleep 1

echo '========================================================================'
echo '==                              D O N E                               =='
echo '========================================================================'
