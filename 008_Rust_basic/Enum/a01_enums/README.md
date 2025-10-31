# Result

```bash
❯ cargo r
    Finished `dev` profile [unoptimized + debuginfo] target(s) in 0.01s
     Running `target/debug/a01_enums`
It's Monday!
It's Tuesday!
It's Wednesday!
It's Thursday!
It's Friday!
It's the weekend!
It's the weekend!
Colors:
  Red color
  Green color
  Blue color
  Custom color: Purple
  RGB color: (255, 128, 0)
Statuses:
  Operation succeeded
  Error: Something went wrong
  Operation is pending
  Operation is complete
  IPv4: 192.168.1.1
  IPv6: 2001:0db8:85a3:0000:0000:8a2e:0370:7334
Payments:
  Processing credit card ending in 3456: 12/2025
  Processing PayPal payment for user@example.com
  Processing bank transfer from account 123456789 with routing number 987654321
  Processing crypto payment to wallet 1A2b3C4d5E6f7G8h9i
  Processing cash payment
  Move to coordinates (10, 20)
  Write message: Hello, Rust!
  Change color to RGB(255, 0, 0)
  Quit message received
  Found value: 5
  No value found
  Success: Operation successful
  Error: Connection failed
Animals:
  Dog named Buddy is 5 years old
  Cat named Whiskers is indoor
  Bird named Tweety is a Canary
  Fish named Nemo lives in Saltwater
  Other animal named Hamster
Vehicles:
  2020 Toyota Camry (Car)
  2019 Harley without sidecar (Motorcycle)
  2018 Ford 5000.5 (Truck)
  Giant with gears (Bicycle)
  Yamaha Speedboat (Boat)
```


# enum

  1. Basic enum usage - Simple Day enum with pattern matching
  2. Enum with different data types - Color enum with no data, String, and tuple variants
  3. Enum with String data - Status enum showing error handling
  4. IP address representation - IpAddress enum with different address formats
  5. Complex enum with multiple fields - PaymentMethod enum with various payment types
  6. Enum with different data structures - Message enum with struct-like and tuple variants
  7. Option enum usage - Custom Option<T> enum similar to Rust's built-in
  8. Result enum usage - Custom Result<T, E> enum for error handling
  9. Animal representation - Animal enum with different properties per variant
  10. Vehicle representation - Vehicle enum showing complex data structures

  Each example demonstrates different aspects of Rust enums including:
  - Basic pattern matching
  - Enums with associated data
  - Different data types per variant
  - Struct-like and tuple variants
  - Generic enums
