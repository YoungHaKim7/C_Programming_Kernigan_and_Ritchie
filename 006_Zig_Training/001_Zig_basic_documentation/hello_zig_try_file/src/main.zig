const std = @import("std");

pub fn main() !void {
    // zig 0.16
    // try std.fs.File.stdout().writeAll("Hello, World!\n");

    // zig 0.13
    const stdout = std.io.getStdOut().writer();
    try stdout.print("Hello, {s}!\n", .{"world"});
}

test "simple test" {}
