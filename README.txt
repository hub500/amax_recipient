--- hello_recipient Project ---

 - How to Build -
   - cd to 'build' directory
   - run the command 'cmake ..'
   - run the command 'make'

 - After build -
   - The built smart contract is under the 'hello_recipient' directory in the 'build' directory
   - You can then do a 'set contract' action with 'amcli' and point in to the './build/hello_recipient' directory

 - Additions to CMake should be done to the CMakeLists.txt in the './src' directory and not in the top level CMakeLists.txt


### require_recipient contract

https://developers.eos.io/welcome/v2.1/smart-contract-guides/adding-inline-actions


1. create recipient account
```
amcli create account amax recipient AM6MRyAjQq8ud7hVNYcfnVPJqcVpscN5So8BhtHuGYqET5GDW5CV AM6MRyAjQq8ud7hVNYcfnVPJqcVpscN5So8BhtHuGYqET5GDW5CV

executed transaction: e242fe7307cc9f4e253acf7994dd6835590f0a24d03b430d82052d3560486eca  200 bytes  6920 us
#          amax <= amax::newaccount             {"creator":"amax","name":"recipient","owner":{"threshold":1,"keys":[{"key":"AM6MRyAjQq8ud7hVNYcfnVPJqcVp...

// amax.code permission
amcli set account permission recipient active --add-code -p recipient
```

create hello account
```
amcli create account amax hello AM6MRyAjQq8ud7hVNYcfnVPJqcVpscN5So8BhtHuGYqET5GDW5CV AM6MRyAjQq8ud7hVNYcfnVPJqcVpscN5So8BhtHuGYqET5GDW5CV

executed transaction: e242fe7307cc9f4e253acf7994dd6835590f0a24d03b430d82052d3560486eca  200 bytes  6920 us
#          amax <= amax::newaccount             {"creator":"amax","name":"hello","owner":{"threshold":1,"keys":[{"key":"AM6MRyAjQq8ud7hVNYcfnVPJqcVp...
```


2. build contract
```
cd build
cmake ..
make
```


3. deploy contract
```
amcli set contract recipient ./hello_recipient -p recipient
```


4. call contract

inline action call

```
amcli push action recipient hi '["hello","one msg"]' -p hello

executed transaction: 4f721d154c11cf64c258d2567391ce6c68c7ae3270fd4dae9e00de0dda913ae7  112 bytes  1418 us
#     recipient <= recipient::hi                {"user":"hello","msg":"one msg"}
>> Name : hello
#     recipient <= recipient::notify            {"user":"hello","msg":"helloone msg"}
#         hello <= recipient::notify            {"user":"hello","msg":"helloone msg"}
```


action_wrapper call

```
amcli push action recipient hi2 '["hello","one msg"]' -p hello

executed transaction: 7460bffd4b5f534ea35e874e08a36a8e02db29b25887b614a8bea6ee24739a50  112 bytes  1048 us
#     recipient <= recipient::hi2               {"user":"hello","msg":"one msg"}
>> Name : hello
#     recipient <= recipient::notify            {"user":"hello","msg":"helloone msg"}
#         hello <= recipient::notify            {"user":"hello","msg":"helloone msg"}
```