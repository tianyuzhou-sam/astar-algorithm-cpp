#ifndef FIND_PATH_H
#define FIND_PATH_H

#include <vector>
#include "MapInfo.h"

std::vector<int> find_path(
    std::vector<int> start,
    std::vector<int> end,
    const MapInfo &Map);

#endif