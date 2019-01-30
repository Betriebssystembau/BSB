//
// Created by drieke on 30.01.19.
//

#ifndef BSB_BUZZERTESTER_H
#define BSB_BUZZERTESTER_H

#include "syscall/guarded_buzzer.h"
#include "thread/customer.h"

class BuzzerTester : public Thread {
private:
    BuzzerTester(const BuzzerTester &ref);

    int yPos;
    int buzzerCounter;
    Guarded_Semaphore *writeMutex;

public:
    BuzzerTester(void *tos, int y, int counter, Guarded_Semaphore *writeMutex) : Thread(tos) {
        this->buzzerCounter = counter;
        this->yPos = y;
        this->writeMutex = writeMutex;
    };

    void action() {
        int counter = 0;
        Guarded_Buzzer buzzer;
        while (true) {
            int x = 0;
            int y = 0;
            this->writeMutex->wait();
            cga_stream.getpos(x, y);
            cga_stream.setpos(0, yPos);
            cga_stream << "Hallo: " << ++counter << endl;
            cga_stream.setpos(x, y);
            this->writeMutex->signal();
            buzzer.set(buzzerCounter);
            buzzer.sleep();
        }
    }
};

#endif //BSB_BUZZERTESTER_H
