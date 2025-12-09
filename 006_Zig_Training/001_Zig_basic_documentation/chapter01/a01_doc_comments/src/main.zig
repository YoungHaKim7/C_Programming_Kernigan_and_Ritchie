const std = @import("std");
const a01_doc_comments = @import("a01_doc_comments");

/// A structure for storing a timestamp, with nanosecond precision (this is a
/// multiline doc comment).
const Timestamp = struct {
    /// The number of seconds since the epoch (this is also a doc comment).
    seconds: i64, // signed so we can represent pre-1970 (not a doc comment)
    /// The number of nanoseconds past the second (doc comment again).
    nanos: u32,

    /// Returns a `Timestamp` struct representing the Unix epoch; that is, the
    /// moment of 1970 Jan 1 00:00:00 UTC (this is a doc comment too).
    pub fn unixEpoch() Timestamp {
        return Timestamp{
            .seconds = 0,
            .nanos = 0,
        };
    }
};
pub fn main() !void {
    // Create a timestamp for the Unix epoch
    const epoch = Timestamp.unixEpoch();

    // Create a custom timestamp
    const custom_time = Timestamp{
        .seconds = 1704067200, // 2024 Jan 1 00:00:00 UTC
        .nanos = 500000000,    // 0.5 seconds
    };

    // Print the timestamps
    std.debug.print("Unix epoch: {} seconds, {} nanoseconds\n", .{ epoch.seconds, epoch.nanos });
    std.debug.print("Custom time: {} seconds, {} nanoseconds\n", .{ custom_time.seconds, custom_time.nanos });

    // Example of creating a timestamp representing a specific time
    const current_time = Timestamp{
        .seconds = 1736486400, // Example: 2025 Jan 10 00:00:00 UTC
        .nanos = 123456789,    // Example nanoseconds
    };

    std.debug.print("Example time: {} seconds, {} nanoseconds since epoch\n", .{current_time.seconds, current_time.nanos});
}

test "simple test" {}

test "fuzz example" {}
