const MAX_SIZE: usize = 5;

struct Stack {
    data: Vec<i32>,
}

impl Stack {
    // Initialize an empty stack with space for MAX_SIZE elements.
    fn new() -> Self {
        Self {
            data: Vec::with_capacity(MAX_SIZE),
        }
    }

    // Push an element and inspect its memory address.
    fn push(&mut self, value: i32) {
        if self.data.len() >= MAX_SIZE {
            println!("Stack Overflow!");
            return;
        }

        self.data.push(value);

        // Get a reference to the element that was just pushed.
        let address = self.data.last().unwrap() as *const i32;

        println!("Value: {value:2} | Address: {address:p}");
    }

    // Pop an element and inspect its memory address.
    fn pop(&mut self) -> Option<i32> {
        if self.data.is_empty() {
            println!("Stack Underflow!");
            return None;
        }

        // The last element is the top of the stack.
        let index = self.data.len() - 1;

        // Get its address before removing it.
        let address = &self.data[index] as *const i32;
        let value = self.data[index];

        println!("Popped {value} <- Memory Address: {address:p}");

        self.data.pop()
    }
}

fn main() {
    let mut stack = Stack::new();

    println!("--- Pushing to Stack ---");
    stack.push(10);
    stack.push(20);
    stack.push(30);

    println!("\n--- Popping from Stack ---");
    stack.pop();
    stack.pop();
}
