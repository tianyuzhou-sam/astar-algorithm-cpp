////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// STL A* Search implementation
// (C)2001 Justin Heyes-Jones
//
// Finding a path on a simple grid maze
// This shows how to do shortest path finding using A*

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef FIND_PATH_ALL_H
#define FIND_PATH_ALL_H


#include <iostream>
#include <vector>
#include "MapInfo.h"
#include "find_path.h"
#include "get_combination.h"


inline std::vector<std::vector<int>> find_path_all(
	int *agent_position,
	std::vector<int> targets_position,
	const MapInfo &Map)
{
    int num_targets = targets_position.size()/2;
    std::vector<int> start_goal_pair = get_combination(num_targets+1, 2);

    // for (long unsigned int i=0; i<start_goal_pair.size(); i=i+2)
    // {
    //     std::cout << start_goal_pair[i] << ", " << start_goal_pair[i+1] << std::endl;
    // }

    std::vector<std::vector<int>> path_all; 

    for (unsigned long idx = 0; idx < start_goal_pair.size(); idx = idx + 2)
    {
        int start_idx = start_goal_pair[idx];
        int goal_idx = start_goal_pair[idx+1];

        // std::vector<int> start;
        // std::vector<int> goal;

        int start[2];
        int goal[2];

        if (start_idx != 0)
        {
            // start.push_back(targets_position[2*(start_idx-1)]);
            // start.push_back(targets_position[2*(start_idx-1)+1]);
            start[0] = targets_position[2*(start_idx-1)];
            start[1] = targets_position[2*(start_idx-1)+1];
        }
        else
        {
            // start.push_back(agent_position[0]);
            // start.push_back(agent_position[1]);
            start[0] = agent_position[0];
            start[1] = agent_position[1];
        }

        if (goal_idx != 0)
        {
            // goal.push_back(targets_position[2*(goal_idx-1)]);
            // goal.push_back(targets_position[2*(goal_idx-1)+1]);
            goal[0] = targets_position[2*(goal_idx-1)];
            goal[1] = targets_position[2*(goal_idx-1)+1];

        }
        else
        {
            // goal.push_back(agent_position[0]);
            // goal.push_back(agent_position[1]);
            goal[0] = agent_position[0];
            goal[1] = agent_position[1];
        }
        std::vector<int> path_short_single = find_path(start, goal, Map);

        // std::cout << "start:" << start[0] << ", " << start[1] << std::endl;
        // std::cout << "goal:" << goal[0] << ", " << goal[1] << std::endl;

        // for (long unsigned int i=0; i<path_short_single.size(); i=i+2)
        // {
        //     std::cout << path_short_single[i] << ", " << path_short_single[i+1] << std::endl;
        // }

        path_all.push_back(path_short_single);

        // start.clear();
        // goal.clear();
    }

    return path_all;
}


#endif