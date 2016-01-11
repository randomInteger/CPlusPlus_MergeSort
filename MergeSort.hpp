//
//  MergeSort.hpp
//  MergeSort implemented on a std::list sequential container.
//
//  Polymorphic: Type can be any numeric type.
//
//  Created by Christopher Gleeson on 1/11/16.
//  Copyright © 2016 Christopher Gleeson. All rights reserved.
//

#ifndef MergeSort_hpp
#define MergeSort_hpp

#include <list>

template <typename T>
std::list<T> _merge(std::list<T> left, std::list<T> right){
    std::list<T> result;
    //merge the lists by comparing first elements
    while(!left.empty() && !right.empty()){
        if(left.front() <= right.front()){
            result.push_back(left.front());
            left.pop_front();
        }else{
            result.push_back(right.front());
            right.pop_front();
        }
    }
    //if the lists were not of even size, one could be non empty
    while(!left.empty()){
        result.push_back(left.front());
        left.pop_front();
    }
    while(!right.empty()){
        result.push_back(right.front());
        right.pop_front();
    }
    return result;
}

template <typename T>
std::list<T> mergeSort(std::list<T> origlist){
    //Catch base recursive case
    if(origlist.size() == 1){
        return origlist;
    }
    //Make sublists
    std::list<T> left;
    std::list<T> right;
    //Populate the "left" and "right" sublists
    while(!origlist.empty()){
        //The "odd vs even" trick is nice to split an array of unknown size
        if(i % 2 == 0){ //Any number % 2 == 0 is even, else its odd.
            left.push_back(origlist.front());
            origlist.pop_front();
        }else{
            right.push_back(origlist.front());
            origlist.pop_front();
        }
    }
    //Call mergeSort recursively on each half of the list
    left = mergeSort(left);
    right = mergeSort(right);
    //Merge the result of the call and return the sorted list
    return _merge(left,right);
}
#endif /* MergeSort_hpp */
