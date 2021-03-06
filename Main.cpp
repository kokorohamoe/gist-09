//test 09#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <iostream>

int main(void){
    // Your code here!
    std::mutex m;
    std::condition_variable cv;
    
    std::unique_lock<std::mutex> lk(m);
    
    std::cout << "lock" << std::endl;
    std::thread t1([&]{cv.notify_one();std::cout <<"pass thread unlock one"<<std::endl;});
    std::thread t2([&]{cv.notify_one();std::cout <<"pass thread unlock one"<<std::endl;});
    cv.wait(lk);
    std::cout << "pass lock" << std::endl;
    cv.wait(lk);
    std::cout << "pass lock" << std::endl;
    t1.join();
    t2.join();
    std::cout << "pass join" << std::endl;

}
