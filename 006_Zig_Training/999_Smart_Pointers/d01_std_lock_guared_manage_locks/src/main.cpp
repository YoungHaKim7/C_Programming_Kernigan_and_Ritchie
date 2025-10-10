#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

class BankAccount {
private:
    int balance;
    std::mutex mtx;

public:
    BankAccount(int initial_balance)
        : balance(initial_balance)
    {
    }

    void deposit(int amount)
    {
        std::lock_guard<std::mutex> lock(mtx);
        balance += amount;
        std::cout << "Deposited: " << amount << ", New balance: " << balance << std::endl;
    }

    void withdraw(int amount)
    {
        std::lock_guard<std::mutex> lock(mtx);
        if (balance >= amount) {
            balance -= amount;
            std::cout << "Withdrew: " << amount << ", New balance: " << balance << std::endl;
        } else {
            std::cout << "Failed to withdraw: " << amount << ", Insufficient funds. Balance: " << balance << std::endl;
        }
    }

    int get_balance()
    {
        std::lock_guard<std::mutex> lock(mtx);
        return balance;
    }

    void transfer(BankAccount& to, int amount)
    {
        std::lock_guard<std::mutex> lock1(mtx);
        std::lock_guard<std::mutex> lock2(to.mtx);

        if (balance >= amount) {
            balance -= amount;
            to.balance += amount;
            std::cout << "Transferred: " << amount << " from one account to another" << std::endl;
        } else {
            std::cout << "Failed to transfer: " << amount << ", Insufficient funds" << std::endl;
        }
    }
};

void worker_thread(BankAccount& account, int thread_id)
{
    for (int i = 0; i < 5; ++i) {
        account.deposit(10 * thread_id);
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        account.withdraw(5 * thread_id);
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

int main()
{
    BankAccount account1(100);
    BankAccount account2(50);

    std::cout << "Initial balances:" << std::endl;
    std::cout << "Account 1: " << account1.get_balance() << std::endl;
    std::cout << "Account 2: " << account2.get_balance() << std::endl;
    std::cout << "\nStarting concurrent operations...\n"
              << std::endl;

    std::vector<std::thread> threads;

    for (int i = 1; i <= 3; ++i) {
        threads.emplace_back(worker_thread, std::ref(account1), i);
    }

    for (auto& thread : threads) {
        thread.join();
    }

    std::cout << "\nFinal balances:" << std::endl;
    std::cout << "Account 1: " << account1.get_balance() << std::endl;
    std::cout << "Account 2: " << account2.get_balance() << std::endl;

    std::cout << "\nDemonstrating transfer between accounts:" << std::endl;
    account1.transfer(account2, 30);

    std::cout << "\nFinal balances after transfer:" << std::endl;
    std::cout << "Account 1: " << account1.get_balance() << std::endl;
    std::cout << "Account 2: " << account2.get_balance() << std::endl;

    return 0;
}
