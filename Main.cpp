//test 09#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

int main(void){
    // Your code here!
    std::mutex m;
    std::condition_variable cv;
    
    std::unique_lock<std::mutex> lk(m);
    
    std::cout << "lock" << std::endl;
    std::thread t([&]{cv.notify_one();});
    cv.wait(lk);
    t.join();


}
