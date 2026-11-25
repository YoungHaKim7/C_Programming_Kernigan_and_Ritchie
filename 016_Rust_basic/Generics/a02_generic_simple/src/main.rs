fn add_2x(x: i32, y: i32) -> i32 {
    x + y
}

fn add_2x_f64(x: f64, y: f64) -> f64 {
    x + y
}

// Generic
fn add_x<T>(x: T, y: T) -> T
where
    T: std::ops::Add<Output = T>,
{
    x + y
}

fn main() {
    let res = add_x::<i32>(3, 10);
    let res02 = add_x::<f32>(3.2, 10.5);
    println!("res : add x (3 10) : {res}");
    println!("res02 : add x (3.2 10.5) : {res02}");
}
