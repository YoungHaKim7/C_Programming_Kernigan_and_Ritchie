// Enum declarations
enum Day {
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday,
}

enum Color {
    Red,
    Green,
    Blue,
    Custom(String),
    RGB(u8, u8, u8),
}

enum Status {
    Success,
    Error(String),
    Pending,
    Complete,
}

enum IpAddress {
    V4(u8, u8, u8, u8),
    V6(String),
}

enum PaymentMethod {
    CreditCard(String, u16, u16), // number, exp_month, exp_year
    PayPal(String),               // email
    BankTransfer(String, String), // account_number, routing_number
    Crypto(String),               // wallet_address
    Cash,
}

enum Message {
    Quit,
    Move { x: i32, y: i32 },
    Write(String),
    ChangeColor(i32, i32, i32),
}

enum Option<T> {
    Some(T),
    None,
}

enum Result<T, E> {
    Ok(T),
    Err(E),
}

enum Animal {
    Dog(String, u8),      // name, age
    Cat(String, bool),    // name, is_indoor
    Bird(String, String), // name, species
    Fish(String, String), // name, water_type
    Other(String),
}

enum Vehicle {
    Car(String, u16, String),      // make, year, model
    Motorcycle(String, u16, bool), // make, year, has_sidecar
    Truck(String, u16, f32),       // make, year, cargo_capacity
    Bicycle(String, bool),         // brand, has_gears
    Boat(String, String),          // make, boat_type
}

fn main() {
    // Example 1: Basic enum usage
    let days = vec![
        Day::Monday,
        Day::Tuesday,
        Day::Wednesday,
        Day::Thursday,
        Day::Friday,
        Day::Saturday,
        Day::Sunday,
    ];

    for day in &days {
        match day {
            Day::Monday => println!("It's Monday!"),
            Day::Tuesday => println!("It's Tuesday!"),
            Day::Wednesday => println!("It's Wednesday!"),
            Day::Thursday => println!("It's Thursday!"),
            Day::Friday => println!("It's Friday!"),
            Day::Saturday | Day::Sunday => println!("It's the weekend!"),
        }
    }

    // Example 2: Enum with different data types
    let colors = vec![
        Color::Red,
        Color::Green,
        Color::Blue,
        Color::Custom("Purple".to_string()),
        Color::RGB(255, 128, 0),
    ];

    println!("Colors:");
    for color in &colors {
        print_color(color);
    }

    // Example 3: Enum with String data
    let statuses = vec![
        Status::Success,
        Status::Error("Something went wrong".to_string()),
        Status::Pending,
        Status::Complete,
    ];

    println!("Statuses:");
    for status in &statuses {
        check_status(status);
    }

    // Example 4: Enum representing IP addresses
    let ipv4 = IpAddress::V4(192, 168, 1, 1);
    let ipv6 = IpAddress::V6("2001:0db8:85a3:0000:0000:8a2e:0370:7334".to_string());

    print_ip_address(&ipv4);
    print_ip_address(&ipv6);

    // Example 5: Complex enum with multiple fields
    let payments = vec![
        PaymentMethod::CreditCard("1234-5678-9012-3456".to_string(), 12, 2025),
        PaymentMethod::PayPal("user@example.com".to_string()),
        PaymentMethod::BankTransfer("123456789".to_string(), "987654321".to_string()),
        PaymentMethod::Crypto("1A2b3C4d5E6f7G8h9i".to_string()),
        PaymentMethod::Cash,
    ];

    println!("Payments:");
    for payment in &payments {
        process_payment(payment);
    }

    // Example 6: Enum with different data structures
    let messages = vec![
        Message::Move { x: 10, y: 20 },
        Message::Write("Hello, Rust!".to_string()),
        Message::ChangeColor(255, 0, 0),
        Message::Quit,
    ];

    for message in messages {
        process_message(message);
    }

    // Example 7: Using Option enum (similar to built-in Option)
    let some_number: Option<i32> = Option::Some(5);
    let no_number: Option<i32> = Option::None;

    process_option(some_number);
    process_option(no_number);

    // Example 8: Using Result enum (similar to built-in Result)
    let success_result: Result<&str, &str> = Result::Ok("Operation successful");
    let error_result: Result<&str, &str> = Result::Err("Connection failed");

    process_result(success_result);
    process_result(error_result);

    // Example 9: Enum representing animals with different properties
    let animals = vec![
        Animal::Dog("Buddy".to_string(), 5),
        Animal::Cat("Whiskers".to_string(), true),
        Animal::Bird("Tweety".to_string(), "Canary".to_string()),
        Animal::Fish("Nemo".to_string(), "Saltwater".to_string()),
        Animal::Other("Hamster".to_string()),
    ];

    println!("Animals:");
    for animal in &animals {
        describe_animal(animal);
    }

    // Example 10: Enum representing different vehicle types
    let vehicles = vec![
        Vehicle::Car("Toyota".to_string(), 2020, "Camry".to_string()),
        Vehicle::Motorcycle("Harley".to_string(), 2019, false),
        Vehicle::Truck("Ford".to_string(), 2018, 5000.5),
        Vehicle::Bicycle("Giant".to_string(), true),
        Vehicle::Boat("Yamaha".to_string(), "Speedboat".to_string()),
    ];

    println!("Vehicles:");
    for vehicle in &vehicles {
        describe_vehicle(vehicle);
    }
}

// Helper functions for examples
fn print_color(color: &Color) {
    match color {
        Color::Red => println!("  Red color"),
        Color::Green => println!("  Green color"),
        Color::Blue => println!("  Blue color"),
        Color::Custom(name) => println!("  Custom color: {}", name),
        Color::RGB(r, g, b) => println!("  RGB color: ({}, {}, {})", r, g, b),
    }
}

fn check_status(status: &Status) {
    match status {
        Status::Success => println!("  Operation succeeded"),
        Status::Error(msg) => println!("  Error: {}", msg),
        Status::Pending => println!("  Operation is pending"),
        Status::Complete => println!("  Operation is complete"),
    }
}

fn print_ip_address(ip: &IpAddress) {
    match ip {
        IpAddress::V4(a, b, c, d) => println!("  IPv4: {}.{}.{}.{}", a, b, c, d),
        IpAddress::V6(addr) => println!("  IPv6: {}", addr),
    }
}

fn process_payment(payment: &PaymentMethod) {
    match payment {
        PaymentMethod::CreditCard(number, month, year) => {
            println!(
                "  Processing credit card ending in {}: {}/{}",
                &number[number.len() - 4..],
                month,
                year
            );
        }
        PaymentMethod::PayPal(email) => {
            println!("  Processing PayPal payment for {}", email);
        }
        PaymentMethod::BankTransfer(account, routing) => {
            println!("  Processing bank transfer from account {} with routing number {}", account, routing);
        }
        PaymentMethod::Crypto(wallet) => {
            println!("  Processing crypto payment to wallet {}", wallet);
        }
        PaymentMethod::Cash => {
            println!("  Processing cash payment");
        }
    }
}

fn process_message(msg: Message) {
    match msg {
        Message::Quit => println!("  Quit message received"),
        Message::Move { x, y } => println!("  Move to coordinates ({}, {})", x, y),
        Message::Write(text) => println!("  Write message: {}", text),
        Message::ChangeColor(r, g, b) => println!("  Change color to RGB({}, {}, {})", r, g, b),
    }
}

fn process_option(opt: Option<i32>) {
    match opt {
        Option::Some(value) => println!("  Found value: {}", value),
        Option::None => println!("  No value found"),
    }
}

fn process_result(res: Result<&str, &str>) {
    match res {
        Result::Ok(message) => println!("  Success: {}", message),
        Result::Err(error) => println!("  Error: {}", error),
    }
}

fn describe_animal(animal: &Animal) {
    match animal {
        Animal::Dog(name, age) => println!("  Dog named {} is {} years old", name, age),
        Animal::Cat(name, is_indoor) => {
            println!(
                "  Cat named {} is {}",
                name,
                if *is_indoor { "indoor" } else { "outdoor" }
            );
        }
        Animal::Bird(name, species) => println!("  Bird named {} is a {}", name, species),
        Animal::Fish(name, water_type) => println!("  Fish named {} lives in {}", name, water_type),
        Animal::Other(name) => println!("  Other animal named {}", name),
    }
}

fn describe_vehicle(vehicle: &Vehicle) {
    match vehicle {
        Vehicle::Car(make, year, model) => {
            println!("  {} {} {} ({})", year, make, model, "Car");
        }
        Vehicle::Motorcycle(make, year, has_sidecar) => {
            println!(
                "  {} {} {} ({})",
                year,
                make,
                if *has_sidecar {
                    "with sidecar"
                } else {
                    "without sidecar"
                },
                "Motorcycle"
            );
        }
        Vehicle::Truck(make, year, capacity) => {
            println!("  {} {} {} ({})", year, make, capacity, "Truck");
        }
        Vehicle::Bicycle(brand, has_gears) => {
            println!(
                "  {} {} ({})",
                brand,
                if *has_gears {
                    "with gears"
                } else {
                    "single speed"
                },
                "Bicycle"
            );
        }
        Vehicle::Boat(make, boat_type) => {
            println!("  {} {} ({})", make, boat_type, "Boat");
        }
    }
}
