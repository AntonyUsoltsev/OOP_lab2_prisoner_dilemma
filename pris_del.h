#ifndef LAB2_PRISONER_DILEMMA_PRIS_DEL_H
#define LAB2_PRISONER_DILEMMA_PRIS_DEL_H

#include <vector>
#include <iostream>
#include <fstream>

class matrix_constructor {
public:
    std::vector<std::vector<int>> matrix;
    matrix_constructor();
};

class simulator{
public:
    int s1,s2,s3;
    //int reg;
    simulator(){
        std:: cout << "insert num of strategies\n";
        std::cin >> s1 >> s2 >> s3;
    }

};

class strategies{
public:
    std::vector<std::vector<char>> history;
    virtual strategies create_strategy(int id);
    virtual void do_decision(int round){
        history.resize(history.size()+1);
    };
};

class strategy_1 : public strategies{
public:
   void do_decision(int round) override{
       history[round].push_back(1);
   }
};

class strategy_2 : public strategies{
public:
    void do_decision(int round) override{
        history[round].push_back(0);
    }
};

class strategy_3 : public strategies {
public:
    void do_decision(int round) override{
        history[round].push_back(0);
    }
};

#endif //LAB2_PRISONER_DILEMMA_PRIS_DEL_H
