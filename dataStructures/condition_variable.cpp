#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
bool ready = false;

void do_print_id(int id)
{
    std::unique_lock <std::mutex> lck(mtx);
}
