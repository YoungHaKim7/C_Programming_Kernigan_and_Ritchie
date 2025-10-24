int main(void)
{
    const char hello[] = "Hello, world!\n";

    // clang-format off
    __asm__ volatile (
       "mov $1, %%rax\n\t"  // syscall number for write
       "mov $1, %%rdi\n\t"  // stdout (fd = 1)
       "lea %0, %%rsi\n\t"  // address of message
       "mov $14, %%rdx\n\t" // length
       "syscall\n\t"
        :
        : "m"(hello)
        : "%rax", "%rdi", "%rsi", "%rdx"
    );
    // clang-format on

    return 0;
}
