fn main() {
    //             [[[i32; Z]; Y]; X]
    let mut array: [[[i32; 3]; 3]; 3] = Default::default();

    for x in 0..3 {
        for y in 0..3 {
            for z in 0..3 {
                array[x][y][z] = 0;
            }
        }
    }

    println!("array : {array:?}");
    println!();
    array[0][0][1] = 12;
    println!("array : {array:?}");
    println!();
    array[1][1][0] = 21;
    println!("array : {array:?}");
    println!();
    array[2][0][1] = 31;
    println!("array : {array:?}");
    println!();
    // for d_2d in array {
    //     for d_3d in d_2d {
    //         println!("{:?}", d_2d);
    //     }
    //     println!("{:?} layers", d_2d);
    //     println!();
    // }
    // Print array layers
    println!("array[0][0][1] = 12");
    println!("array[1][1][0] = 21");
    println!("array[2][0][1] = 31\n");

    for (layer_idx, layer) in array.iter().enumerate() {
        println!("Layer {layer_idx}:");
        for row in layer {
            println!("{:?}", row);
        }
        println!();
    }
}
