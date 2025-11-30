#include <iostream>
#include <chrono>
#include "ThreadPool.h"

int main() {
    ThreadPool::instance()->Initialize(10);
    ThreadPool::instance()->Start();
    ThreadPool::instance()->Enqueue([](){
        while (ThreadPool::instance()->GetState()){
            std::cout << "Thread1 is running..." << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }
    });
    ThreadPool::instance()->Enqueue([](){
        while (ThreadPool::instance()->GetState()){
            std::cout << "Thread2 is running..." << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }
    });
    ThreadPool::instance()->Enqueue([](){
        while (ThreadPool::instance()->GetState()){
            std::cout << "Thread3 is running..." << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }
    });

    ThreadPool::instance()->Stop();
    ThreadPool::instance()->Wait();
    return 0;
}
