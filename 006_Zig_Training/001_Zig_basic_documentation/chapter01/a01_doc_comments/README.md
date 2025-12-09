# Result

```bash
$ zig build run

Unix epoch: 0 seconds, 0 nanoseconds
Custom time: 1704067200 seconds, 500000000 nanoseconds
Example time: 1736486400 seconds, 123456789 nanoseconds since epoch
```

# Perfect! I've added a main example that demonstrates:

  1. Using the static method: Timestamp.unixEpoch() to get the Unix epoch (1970-01-01)
  2. Creating custom timestamps: Using struct literal syntax with field names
  3. Displaying timestamp data: Using std.debug.print to show the seconds and nanoseconds

  The example shows:
  - Unix epoch: 0 seconds, 0 nanoseconds
  - Custom timestamp: January 1, 2024 with 0.5 seconds (500,000,000 nanoseconds)
  - Example timestamp: January 10, 2025 with specific nanoseconds

  This demonstrates the basic usage of structs in Zig including:
  - Field initialization using .fieldName = value syntax
  - Accessing struct fields with dot notation
  - Using public methods (pub fn) associated with structs
  - Documenting fields with /// comments
