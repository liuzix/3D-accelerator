#pragma once
#include <vector>
#include <list>
#include <iostream>
#include <cstdint>
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
        : memory(memSize / sizeof(Value), 0)
    {
        cout << "Initializting SDRAM model, size = 0x"
             << hex << memSize << endl;
        cout << "SDRAM controller word size = "
             << sizeof(Value) << endl;
    }

    void tick(int port, uint32_t addr, bool read, bool write,
              Value *readdata, unsigned char &readvalid, Value *writedata,
              unsigned char &waitrequest)
    {
        // handle output
        if (!readRequests.empty()
            && readRequests.front().targetTick <= tickCount
            && readRequests.front().port == port) {
            
            Value v = memory[readRequests.front().address / sizeof(Value)];
            memcpy(readdata, &v, sizeof(Value));
            readRequests.pop_front();
            readvalid = true;
        } else {
            readvalid = false;
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
            cout << "sdram: write " << dec << addr << endl;
            WriteRequest req;
            req.address = addr;
            memcpy(&req.value, writedata, sizeof(Value));
            req.targetTick = tickCount + MEMORY_LATENCY;
            writeRequests.push_back(req);
        }

        // handle write queue
        if (!writeRequests.empty()
            && writeRequests.front().targetTick <= tickCount) {
            
            WriteRequest &req = writeRequests.front();
            memory[req.address / sizeof(Value)] = req.value;
            writeRequests.pop_front();
        }

        // check of any queue is full
        if (readRequests.size() >= MAX_QUEUE_LENGTH
            || writeRequests.size() >= MAX_QUEUE_LENGTH) {
            
            waitrequest = true;
        } else {
            waitrequest = false;
        }
        
        tickCount++; 
    }
};
