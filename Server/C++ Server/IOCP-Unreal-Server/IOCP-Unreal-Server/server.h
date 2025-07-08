#pragma once
#include "room.h"
#include "event.h"
#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <atomic>
#include <string>
#include "db.h"

class server
{
public:
    HANDLE h_iocp;
    SOCKET g_s_socket, g_c_socket;
    ex_over g_a_over;                                    

    concurrency::concurrent_unordered_map<long long, std::shared_ptr<session>> clients;
    concurrency::concurrent_priority_queue<ROOM_EVENT> event_queue;
    concurrency::concurrent_unordered_map<int, std::shared_ptr<ROOM>> rooms;

    std::atomic<long long> next_client_id = 0;
    std::atomic<int> pid_counter = 0;

    std::thread event_thread;
    std::vector <std::thread> worker_threads;
public:
    void InitServer();
    bool ConnectToServer(const char* server_ip);
    void DisconnectToServer(long long c_id);
    void ProcessPacket(long long c_id, char* packet);
    
    void AcceptThreadFunc();
    void WorkerThreadFunc();
};

