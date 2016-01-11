//
//  main.cpp
//  Tester for the MergeSort.hpp library.
//
//  Created by Christopher Gleeson on 1/11/16.
//  Copyright © 2016 Christopher Gleeson. All rights reserved.
//

#include <iostream>
#include "MergeSort.hpp"

int main(int argc, const char * argv[]) {

    std::cout << "Welcome to Mergesort.\n\n";
    
    //Test mergesort, use duplicates and negative values.
    std::list<int> originalist;
    originalist.push_back(-7);
    originalist.push_back(1);
    originalist.push_back(1);
    originalist.push_back(5);
    originalist.push_back(-4);
    originalist.push_back(2);
    originalist.push_back(3);
    originalist.push_back(0);
    
    //Print out the original list
    std::cout << "Original list is: ";
    for(auto it = originalist.begin();it != originalist.end();it++){
        std::cout << *it << " ";
    }
    std::cout << "\n\n";
    
    //Run the sort
    std::cout << "Sorting...\n";
    std::list<int> sortedlist = mergeSort(originalist);
    
    //Print out the final list
    std::cout << "\nFinal list is: ";
    while(!sortedlist.empty()){
        std::cout << sortedlist.front() << " ";
        sortedlist.pop_front();
    }
    std::cout << "\n\n";
    return 0;
}
