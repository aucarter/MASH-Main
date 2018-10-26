//
//  test.hpp
//  MACRO-CPP
//
//  Created by Sean Wu on 11/9/17.
//  Copyright © 2017 Sean Wu. All rights reserved.
//

#ifndef test_hpp
#define test_hpp

#include <stdio.h>
#include <memory>


#include "human.hpp"
#include "humanPop.hpp"
#include "immune.hpp"


inline void f(int a){
    std::cout << "function f has integer a: " << a << std::endl;
};


void testImmune(){
    human* h = new human(1);
    
    
    immune_base* p = new immune_PfSI(*h,"hi",false);
    p->get_immune_model();
    
    std::cout << "killing human " << std::endl;
    delete h;
    
    std::cout << "killing immune_PfSI " << std::endl;
    delete p;
};

//'@export
// [[Rcpp::export]]
void testEventQueue(){
    
    std::vector<event> eventQ;
    event anEvent = event("hi",100,std::bind(f,5));
    eventQ.push_back(anEvent);
    
    eventQ[0].eventF();
};


//'@export
// [[Rcpp::export]]
void testHuman(){
    human* h = new human(1);
    std::cout << "human 1 id: " << h->get_id() << std::endl;
    h->set_state("state1");
    std::cout << "human 1 state: " << h->get_state() << std::endl;
    h->add2Q_set_stateTest(1.00,"state2");
    h->fireEventTest();
    std::cout << "human 1 state: " << h->get_state() << std::endl;
    
    human* h1 = new human(2);
    std::cout << "human 2 id: " << h1->get_id() << std::endl;
    h1->set_state("state53");
    std::cout << "human 2 state: " << h1->get_state() << std::endl;
    h1->add2Q_set_stateTest(1.00,"state223");
    h1->fireEventTest();
    std::cout << "human 2 state: " << h1->get_state() << std::endl;
    std::cout << "human 1 state: " << h->get_state() << std::endl;
    
    delete h;
    delete h1;
}

//'@export
// [[Rcpp::export]]
void testHumanQ(){
    
    human* h1 = new human(1);
    human* h2 = new human(2);
    
    std::cout << "human 1 state: " << h1->get_state() << std::endl;
    h1->add2Q_set_state(1.0,"blah");
    h1->add2Q_set_state(3.34,"MEOOOOW!!!!");
    h1->printEventQ();
    
    h1->fireEvent();
    std::cout << "human 1 state: " << h1->get_state() << std::endl;
    
    std::cout << "human 2 state: " << h2->get_state() << std::endl;
    h2->add2Q_set_state(10.34234,"!!!!MMMMMEOWWWW");
    h2->printEventQ();
    h2->fireEvent();
    
    std::cout << "human 1 state: " << h1->get_state() << std::endl;
    std::cout << "human 2 state: " << h2->get_state() << std::endl;
    
    delete h1;
    delete h2;
}

//'@export
// [[Rcpp::export]]
void testHumanPop(const std::vector<int> pop){
    humanPop h(pop);
    h.get_human(pop.at(0))->death();
    h.get_human(pop.at(1))->check_inf();
    h.printPop();
}


#endif /* test_hpp */
