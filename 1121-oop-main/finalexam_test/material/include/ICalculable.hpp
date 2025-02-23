//
// Created by 黃漢軒 on 2023/12/18.
//

#ifndef OOP_IDISTANCECALCULATABLE_HPP
#define OOP_IDISTANCECALCULATABLE_HPP

class ICalculable {
    virtual int GetDistance() = 0;
    virtual int GetTerminalStationArrivalTimeInSecond() = 0;
};

#endif // OOP_IDISTANCECALCULATABLE_HPP
