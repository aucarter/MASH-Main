/*
 * ################################################################################
 *
 *        __  __
 *       / / / /_  ______ ___  ____ _____
 *      / /_/ / / / / __ `__ \/ __ `/ __ \
 *     / __  / /_/ / / / / / / /_/ / / / /
 *    /_/ /_/\__,_/_/ /_/ /_/\__,_/_/ /_/
 *
 *    Human Abstract Base Class Implementation
 *    MASH Team
 *    January 2017
 *
 * ################################################################################
*/

#include "Human.hpp"

/* destructor */
human::~human(){};

/* move operators */
human::human(human&&) = default;
human& human::operator=(human&&) = default;

/* event queue */
inline bool compare_tEvent(const event& eventA, const event& eventB) { return eventA.tEvent < eventB.tEvent; }

void human::addEvent2Q(const event &e){
    EventQ.push_back(e);
    std::sort(EventQ.begin(),EventQ.end(),compare_tEvent);
};

void human::rmTagFromQ(const std::string &tag){
    EventQ.erase(std::remove_if(EventQ.begin(),EventQ.end(),
                                [tag](const event& e){
                                    return(tag.compare(e.tag)==0);
                                }));
};

void human::fireEvent(){
    EventQ.front().eventF();
    EventQ.erase(EventQ.begin());
};
