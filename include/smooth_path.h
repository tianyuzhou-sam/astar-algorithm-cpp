#ifndef SMOOTH_PATH_H
#define SMOOTH_PATH_H


#include <iostream>
#include <vector>
#include <cstdlib>
#include "MapInfo.h"
#include "line_of_sight.h"


/*


Input:
    path: {x0,y0, x1,y1, x2,y2, ...}
    Map: a struct MapInfo

Output:
    block_flag: true if there is at least one obstacle cell blocks the line-of-sight.
                false if the line-of-sight is clear.
*/


inline std::vector<int> smooth_path(
    std::vector<int> &path,
    const MapInfo &Map)
{
    std::vector<int> path_output;
    int num_group = (int) (path.size()/2) / 3;
    // auto [q, r] = std::div(divisor, dividend);
    for (int idx_group = 0; idx_group < num_group; ++idx_group) {
        int previousPoint[2] = {path[6*idx_group], path[6*idx_group+1]};
        int currentPoint[2] = {path[6*idx_group+4], path[6*idx_group+5]};
        bool block_flag = line_of_sight(previousPoint, currentPoint, Map);
        // For each 3-point group, if the first one and the third one has a line-of-sight,
        // discard the second one. If not, don't change the group.
        if (!block_flag) {
            path_output.insert(path_output.end(), path.begin()+6*idx_group, path.begin()+6*idx_group+1+1);
            path_output.insert(path_output.end(), path.begin()+6*idx_group+4, path.begin()+6*idx_group+5+1);
        }
        else path_output.insert(path_output.end(), path.begin()+6*idx_group, path.begin()+6*idx_group+5+1);
    }
    return path_output;
}


#endif