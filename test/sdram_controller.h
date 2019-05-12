#pragma once
#include <vector>
#include <list>
#include <iostream>
#include <cstdint>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

#define MEMORY_LATENCY 5
#define MAX_QUEUE_LENGTH 8

template<typename Value>
class SDRAMController {
private:
    struct ReadRequest {
        uint32_t port;
        uint32_t address;
        int targetTick;
    };

    struct WriteRequest {
        uint32_t address;
        Value value;
        int targetTick;
    };

    list<ReadRequest> readRequests;
    list<WriteRequest> writeRequests;

    int tickCount = 0;
public:
    vector<Value> memory;
    SDRAMController(uint32_t memSize)
        : memory(memSize / sizeof(Value), 0xcc)
    {
        cout << "Initializting SDRAM model, size = 0x"
             << hex << memSize << endl;
        cout << "SDRAM controller word size = "
             << sizeof(Value) << endl;
        srand(time(NULL));
    }

    void tick(int port, uint32_t addr, bool read, bool write,
              Value *readdata, unsigned char &readvalid, Value *writedata,
              unsigned char &waitrequest)
    {
        tickCount++; 
        
        // handle output
        if (!readRequests.empty()
            && readRequests.front().targetTick <= tickCount
            && readRequests.front().port == port) {
           
            if (rand() % 4 != 0) {
                Value v = memory[readRequests.front().address / sizeof(Value)];
                memcpy(readdata, &v, sizeof(Value));
                cout << "sdram read address " << hex << readRequests.front().address << " data " << hex << *readdata << endl;
                readRequests.pop_front();
                readvalid = true;
            } else {
                readvalid = false;
            }
        } else {
            readvalid = false;
        }
        
        // handle write queue
        if (!writeRequests.empty()
            && writeRequests.front().targetTick <= tickCount) {
            
            WriteRequest &req = writeRequests.front();

            cout << "sdram handle write request to addr " << hex << req.address << endl;
            memory[req.address / sizeof(Value)] = req.value;
            writeRequests.pop_front();
        }

        // check of any queue is full
        if (readRequests.size() >= MAX_QUEUE_LENGTH
            || writeRequests.size() >= MAX_QUEUE_LENGTH) {
            
            cout << "sdram delay" << endl;
            waitrequest = true;
            return;
        } else {
            waitrequest = false;
        }

        // handle input
        if (read) {
            cout << "sdram: read " << dec << addr << endl;
            ReadRequest req;
            req.address = addr;
            req.port = port;
            req.targetTick = tickCount + MEMORY_LATENCY;
            readRequests.push_back(req);
        } else if (write) {
            cout << "sdram: write " << dec << addr <<  " with " << hex << *writedata << endl;
            WriteRequest req;
            req.address = addr;
            memcpy(&req.value, writedata, sizeof(Value));
            req.targetTick = tickCount + MEMORY_LATENCY;
            writeRequests.push_back(req);
        } else {
        }

    }
};
