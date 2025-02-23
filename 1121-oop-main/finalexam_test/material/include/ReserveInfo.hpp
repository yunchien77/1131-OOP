//
// Created by 黃漢軒 on 2023/12/17.
//

#ifndef OOP_RESERVEINFO_H
#define OOP_RESERVEINFO_H

class ReserveInfo {
private:
    int train;
    int seat;

public:
    ReserveInfo(int train, int seat);
    int GetTrain();
    int GetSeat();
};

#endif // OOP_RESERVEINFO_H
