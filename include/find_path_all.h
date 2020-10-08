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
    std::vector<std::vector<int>> path_all; 

    for (unsigned long idx = 0; idx < start_goal_pair.size(); idx = idx + 2)
    {
        int start_idx = start_goal_pair[idx];
        int goal_idx = start_goal_pair[idx+1];

        int start[2];
        int goal[2];

        if (start_idx != 0)
        {
            start[0] = targets_position[2*(start_idx-1)];
            start[1] = targets_position[2*(start_idx-1)+1];
        }
        else
        {
            start[0] = agent_position[0];
            start[1] = agent_position[1];
        }

        if (goal_idx != 0)
        {
            goal[0] = targets_position[2*(goal_idx-1)];
            goal[1] = targets_position[2*(goal_idx-1)+1];

        }
        else
        {
            goal[0] = agent_position[0];
            goal[1] = agent_position[1];
        }
        std::vector<int> path_short_single = find_path(start, goal, Map);
        path_all.push_back(path_short_single);
    }

    return path_all;
}


#endif