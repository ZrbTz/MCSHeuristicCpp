#include "test_utility.h"
#include <iostream>

#include <fstream>

void Test::to_string(){
    std::cout << std::endl << "TEST DESCRIPTION" << std::endl;
    std::cout << "Test Name: " << this->td.test_name << " vertex_labelled: " << this->td.vertex_labelled 
        << " directed: " << this->td.directed << " connected: " << this->td.connected << " edge_labelled: " << this->td.edge_labelled
        << " timeout: " << this->td.timeout << " node_heuristic: " << this->td.node_heuristic << std::endl << std::endl;

    std::cout << "Total Number of Recursions: " << this->recursions << std::endl;
    std::cout << "Total Elapsed Time: " << this->total_time << std::endl;
    std::cout << "MILESTONES" << std::endl;
    for(auto& m : this->milestones){
        std::cout << "Incumbent Size: " << m.first << " Recursions: " << m.second << std::endl;
    }

    std::cout << "SOLUTION" << std::endl;
    std::cout << "Solution size: " << this->solution.size() << std::endl;
    for(auto& m : this->solution){
        std::cout << "(" << m.first << " -> " << m.second << ") ";
    }
}

void Test::save_json(){
    json jsonfile;

    jsonfile["milestones"] = this-> milestones;
    jsonfile["solution"] = this->solution;
    jsonfile["test_description"] = this->td;
    jsonfile["recursions"] = this->recursions;
    jsonfile["total_time"] = this->total_time;

    std::ofstream file(this->td.test_name + ".json");
    file << jsonfile;
 }