#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <chrono>

// Example demonstrating std::scoped_lock for managing multiple mutexes
// Prevents deadlocks through deadlock-avoidance algorithm

class BankAccount {
private:
    std::string name;
    double balance;
    std::mutex mtx;

public:
    BankAccount(const std::string& n, double b) : name(n), balance(b) {}

    void deposit(double amount) {
        std::lock_guard<std::mutex> lock(mtx);
        depositUnsafe(amount);
    }

    void withdraw(double amount) {
        std::lock_guard<std::mutex> lock(mtx);
        withdrawUnsafe(amount);
    }

    // Internal methods without locking (for use by functions that already hold locks)
    void depositUnsafe(double amount) {
        balance += amount;
        std::cout << name << " deposited $" << amount
                  << ", new balance: $" << balance << std::endl;
    }

    void withdrawUnsafe(double amount) {
        if (balance >= amount) {
            balance -= amount;
            std::cout << name << " withdrew $" << amount
                      << ", new balance: $" << balance << std::endl;
        } else {
            std::cout << name << " insufficient funds for $" << amount
                      << ", balance: $" << balance << std::endl;
        }
    }

    double getBalance() const {
        return balance;
    }

    std::string getName() const {
        return name;
    }

    // Get reference to mutex for external locking
    std::mutex& getMutex() {
        return mtx;
    }
};

// Safe transfer using std::scoped_lock - prevents deadlocks
void safeTransfer(BankAccount& from, BankAccount& to, double amount) {
    std::cout << "\nTransfer $" << amount << " from " << from.getName()
              << " to " << to.getName() << std::endl;

    // std::scoped_lock locks multiple mutexes atomically
    // Uses deadlock-avoidance algorithm to prevent deadlocks
    std::scoped_lock lock(from.getMutex(), to.getMutex());

    if (from.getBalance() >= amount) {
        from.withdrawUnsafe(amount);
        // Add small delay to demonstrate thread safety
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        to.depositUnsafe(amount);
        std::cout << "Transfer completed successfully" << std::endl;
    } else {
        std::cout << "Transfer failed: insufficient funds" << std::endl;
    }
}

// Unsafe transfer that can cause deadlock (for demonstration)
void unsafeTransfer(BankAccount& from, BankAccount& to, double amount) {
    std::cout << "\nUnsafe transfer $" << amount << " from " << from.getName()
              << " to " << to.getName() << std::endl;

    // This can cause deadlock if threads acquire locks in different order
    from.getMutex().lock();
    std::this_thread::sleep_for(std::chrono::milliseconds(50)); // Increase deadlock chance
    to.getMutex().lock();

    if (from.getBalance() >= amount) {
        from.withdraw(amount);
        to.deposit(amount);
        std::cout << "Transfer completed" << std::endl;
    }

    to.getMutex().unlock();
    from.getMutex().unlock();
}

int main() {
    std::cout << "=== std::scoped_lock Example ===" << std::endl;
    std::cout << "Demonstrating safe multi-mutex management\n" << std::endl;

    // Create bank accounts
    BankAccount alice("Alice", 1000.0);
    BankAccount bob("Bob", 500.0);
    BankAccount charlie("Charlie", 750.0);

    std::cout << "Initial balances:" << std::endl;
    std::cout << "Alice: $" << alice.getBalance() << std::endl;
    std::cout << "Bob: $" << bob.getBalance() << std::endl;
    std::cout << "Charlie: $" << charlie.getBalance() << std::endl;

    // Safe transfers using std::scoped_lock
    std::cout << "\n=== Safe Transfers (using std::scoped_lock) ===" << std::endl;

    std::vector<std::thread> safeThreads;

    // Multiple concurrent transfers
    safeThreads.emplace_back(safeTransfer, std::ref(alice), std::ref(bob), 200.0);
    safeThreads.emplace_back(safeTransfer, std::ref(bob), std::ref(charlie), 150.0);
    safeThreads.emplace_back(safeTransfer, std::ref(charlie), std::ref(alice), 100.0);
    safeThreads.emplace_back(safeTransfer, std::ref(alice), std::ref(charlie), 300.0);

    // Wait for all safe transfers to complete
    for (auto& t : safeThreads) {
        t.join();
    }

    std::cout << "\nBalances after safe transfers:" << std::endl;
    std::cout << "Alice: $" << alice.getBalance() << std::endl;
    std::cout << "Bob: $" << bob.getBalance() << std::endl;
    std::cout << "Charlie: $" << charlie.getBalance() << std::endl;

    // Demonstrate with different types of lockables
    std::cout << "\n=== Using std::scoped_lock with different mutex types ===" << std::endl;

    std::timed_mutex tmtx1;
    std::recursive_mutex rmtx1;
    std::mutex mtx1;

    std::cout << "Locking different mutex types with scoped_lock..." << std::endl;

    // Scoped lock works with any lockable types
    {
        std::scoped_lock lock(tmtx1, rmtx1, mtx1);
        std::cout << "All mutexes locked successfully" << std::endl;
        std::cout << "Critical section protected by multiple mutex types" << std::endl;
    } // All mutexes automatically unlocked here

    std::cout << "All mutexes unlocked" << std::endl;

    // Benefits of std::scoped_lock
    std::cout << "\n=== Key Benefits of std::scoped_lock ===" << std::endl;
    std::cout << "1. Deadlock prevention: Uses deadlock-avoidance algorithm" << std::endl;
    std::cout << "2. Exception safety: Automatic unlocking on scope exit" << std::endl;
    std::cout << "3. Multiple mutex support: Lock any number of mutexes atomically" << std::endl;
    std::cout << "4. Generic: Works with any lockable type" << std::endl;
    std::cout << "5. RAII: Resource acquisition is initialization pattern" << std::endl;

    return 0;
}
