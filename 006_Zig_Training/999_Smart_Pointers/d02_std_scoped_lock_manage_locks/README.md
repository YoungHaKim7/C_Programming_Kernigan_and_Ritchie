# Result

```bash

=== std::scoped_lock Example ===
Demonstrating safe multi-mutex management

Initial balances:
Alice: $1000
Bob: $500
Charlie: $750

=== Safe Transfers (using std::scoped_lock) ===

Transfer $200 from Alice to Bob
Alice withdrew $200, new balance: $800

Transfer $
Transfer $
Transfer $100300 from Alice to Charlie
150 from Bob to Charlie
 from Charlie to Alice
Bob deposited $200, new balance: $700
Transfer completed successfully
Alice withdrew $300, new balance: $500
Charlie deposited $300, new balance: $1050
Transfer completed successfully
Charlie withdrew $100, new balance: $950
Alice deposited $100, new balance: $600
Transfer completed successfully
Bob withdrew $150, new balance: $550
Charlie deposited $150, new balance: $1100
Transfer completed successfully

Balances after safe transfers:
Alice: $600
Bob: $550
Charlie: $1100

=== Using std::scoped_lock with different mutex types ===
Locking different mutex types with scoped_lock...
All mutexes locked successfully
Critical section protected by multiple mutex types
All mutexes unlocked

=== Key Benefits of std::scoped_lock ===
1. Deadlock prevention: Uses deadlock-avoidance algorithm
2. Exception safety: Automatic unlocking on scope exit
3. Multiple mutex support: Lock any number of mutexes atomically
4. Generic: Works with any lockable type
5. RAII: Resource acquisition is initialization pattern
```
