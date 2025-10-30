// std Result
// 1. Generic Function - Find the largest item in a slice
fn largest<T: PartialOrd>(list: &[T]) -> &T {
    let mut largest = &list[0];
    for item in list {
        if item > largest {
            largest = item;
        }
    }
    largest
}

// 2. Generic Struct - Point with coordinates of any type
#[derive(Debug, Clone, Copy)]
struct Point<T, U> {
    x: T,
    y: U,
}

impl<T: Copy, U: Copy> Point<T, U> {
    fn new(x: T, y: U) -> Self {
        Point { x, y }
    }

    fn mixup<V, W>(self, other: Point<V, W>) -> Point<T, W> {
        Point {
            x: self.x,
            y: other.y,
        }
    }
}

// 3. Generic Enum - Result-like type that can hold success or error values
enum MyResult<T, E> {
    Ok(T),
    Err(E),
}

impl<T, E> MyResult<T, E> {
    fn is_ok(&self) -> bool {
        match self {
            MyResult::Ok(_) => true,
            MyResult::Err(_) => false,
        }
    }

    fn unwrap(self) -> T {
        match self {
            MyResult::Ok(value) => value,
            MyResult::Err(_) => panic!("called `unwrap` on an `Err` value"),
        }
    }
}

// 4. Generic Trait - Define behavior for items that can be compared
trait Comparable {
    fn compare(&self, other: &Self) -> i32;
}

#[derive(Debug, PartialEq)]
struct GenericNumber<T> {
    value: T,
}

impl<T: PartialOrd> Comparable for GenericNumber<T> {
    fn compare(&self, other: &Self) -> i32 {
        if self.value < other.value {
            -1
        } else if self.value > other.value {
            1
        } else {
            0
        }
    }
}

// 5. Generic Implementation - Add methods to any type that implements Display
use std::fmt::Display;

trait MyDisplay {
    fn print_twice(&self) -> String;
}

impl<T: Display> MyDisplay for T {
    fn print_twice(&self) -> String {
        format!("{} {}", self, self)
    }
}

// 6. Generic Function with Multiple Type Parameters
fn compare_and_print<T: Display, U: Display + PartialOrd>(t: T, u: U) {
    println!("Comparing {} and {}", t, u);
    if t.to_string() < u.to_string() {
        println!("{} is smaller", t);
    } else {
        println!("{} is not smaller", t);
    }
}

// 7. Generic Struct with Lifetime Parameters
#[derive(Debug)]
struct ImportantExcerpt<'a, T> {
    part: &'a str,
    data: T,
}

impl<'a, T> ImportantExcerpt<'a, T> {
    fn level(&self) -> i32 {
        3
    }

    fn announce_and_return_part(&self, announcement: &str) -> &str {
        println!("Attention please: {}", announcement);
        self.part
    }
}

// 8. Generic Vector Operations
fn filter<T, F>(vec: &[T], predicate: F) -> Vec<&T>
where
    F: Fn(&T) -> bool,
{
    let mut result = Vec::new();
    for item in vec {
        if predicate(item) {
            result.push(item);
        }
    }
    result
}

fn map<T, U, F>(vec: &[T], mapper: F) -> Vec<U>
where
    F: Fn(&T) -> U,
{
    let mut result = Vec::new();
    for item in vec {
        result.push(mapper(item));
    }
    result
}

// 9. Generic Wrapper for Optional Values
#[derive(Debug)]
struct Wrapper<T> {
    value: Option<T>,
}

impl<T> Wrapper<T> {
    fn new(value: T) -> Self {
        Wrapper { value: Some(value) }
    }

    fn empty() -> Self {
        Wrapper { value: None }
    }

    fn is_some(&self) -> bool {
        self.value.is_some()
    }

    fn unwrap_or(self, default: T) -> T {
        self.value.unwrap_or(default)
    }
}

// 10. Generic Tree Node
#[derive(Debug)]
struct TreeNode<T> {
    value: T,
    left: Option<Box<TreeNode<T>>>,
    right: Option<Box<TreeNode<T>>>,
}

impl<T: Ord> TreeNode<T> {
    fn new(value: T) -> Self {
        TreeNode {
            value,
            left: None,
            right: None,
        }
    }

    fn insert(&mut self, value: T) {
        if value < self.value {
            if let Some(ref mut left) = self.left {
                left.insert(value);
            } else {
                self.left = Some(Box::new(TreeNode::new(value)));
            }
        } else {
            if let Some(ref mut right) = self.right {
                right.insert(value);
            } else {
                self.right = Some(Box::new(TreeNode::new(value)));
            }
        }
    }

    fn preorder_traverse(&self, result: &mut Vec<T>)
    where
        T: Clone,
    {
        result.push(self.value.clone());
        if let Some(ref left) = self.left {
            left.preorder_traverse(result);
        }
        if let Some(ref right) = self.right {
            right.preorder_traverse(result);
        }
    }
}

fn main() {
    // Example 1: Generic Function
    let numbers = vec![34, 50, 25, 100, 65];
    println!("The largest number is {}", largest(&numbers));

    let chars = vec!['y', 'm', 'a', 'q'];
    println!("The largest char is {}", largest(&chars));

    // Example 2: Generic Struct
    let p1 = Point::new(5, 10.4);
    let p2 = Point::new("Hello", 'c');
    let p3 = p1.mixup(p2);
    println!("p3.x = {}, p3.y = {}", p3.x, p3.y);

    // Example 3: Generic Enum
    let success: MyResult<i32, &str> = MyResult::Ok(42);
    let error: MyResult<i32, &str> = MyResult::Err("Something went wrong");

    println!("Success is ok: {}", success.is_ok());
    println!("Error is ok: {}", error.is_ok());
    println!("Success value: {}", success.unwrap());

    // Example 4: Generic Trait
    let num1 = GenericNumber { value: 5 };
    let num2 = GenericNumber { value: 10 };
    println!("Comparison result: {}", num1.compare(&num2));

    // Example 5: Generic Implementation
    let message = "Hello, World!";
    println!("Printed twice: {}", message.print_twice());

    // Example 6: Multiple Type Parameters
    compare_and_print(42, 3.14);
    compare_and_print("hello", "world");

    // Example 7: Generic with Lifetime
    let novel = String::from("Call me Ishmael. Some years ago...");
    let first_sentence = novel.split('.').next().expect("Could not find a '.'");
    let excerpt = ImportantExcerpt {
        part: first_sentence,
        data: 42,
    };
    println!("Excerpt: {:?}", excerpt);
    println!("Level: {}", excerpt.level());

    // Use the announce_and_return_part method
    let announcement = "Important excerpt follows!";
    let returned_part = excerpt.announce_and_return_part(announcement);
    println!("Returned part: {}", returned_part);

    // Access the part and data fields directly
    println!("Part field: {}", excerpt.part);
    println!("Data field: {}", excerpt.data);

    // Example 8: Generic Vector Operations
    let numbers = vec![1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
    let evens = filter(&numbers, |x| x % 2 == 0);
    println!("Even numbers: {:?}", evens);

    let squared = map(&numbers, |x| x * x);
    println!("Squared numbers: {:?}", squared);

    // Example 9: Generic Wrapper
    let wrapped = Wrapper::new(42);
    let empty = Wrapper::<i32>::empty();

    println!("Wrapped is some: {}", wrapped.is_some());
    println!("Empty is some: {}", empty.is_some());
    println!("Wrapped value: {}", wrapped.unwrap_or(0));
    println!("Empty value: {}", empty.unwrap_or(100));

    // Example 10: Generic Tree
    let mut tree = TreeNode::new(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(12);
    tree.insert(18);

    let mut traversal_result = Vec::new();
    tree.preorder_traverse(&mut traversal_result);
    println!("Tree preorder traversal: {:?}", traversal_result);
}
