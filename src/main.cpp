////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// STL A* Search implementation
// (C)2001 Justin Heyes-Jones
//
// Finding a path on a simple grid maze
// This shows how to do shortest path finding using A*

////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <vector>
#include "MapInfo.h"
#include "find_path.h"

#define DEBUG_LISTS 0
#define DEBUG_LIST_LENGTHS_ONLY 0


// Main
int main()
{
	std::vector<int> world_map = 
	{
	// 0001020304050607080910111213141516171819
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,   // 00
		1,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,1,   // 01
		1,9,9,1,1,9,9,9,1,9,1,9,1,9,1,9,9,9,1,1,   // 02
		1,9,9,1,1,9,9,9,1,9,1,9,1,9,1,9,9,9,1,1,   // 03
		1,9,1,1,1,1,9,9,1,9,1,9,1,1,1,1,9,9,1,1,   // 04
		1,9,1,1,9,1,1,1,1,9,1,1,1,1,9,1,1,1,1,1,   // 05
		1,9,9,9,9,1,1,1,1,1,1,9,9,9,9,1,1,1,1,1,   // 06
		1,9,9,9,9,9,9,9,9,1,1,1,9,9,9,9,9,9,9,1,   // 07
		1,9,1,1,1,1,1,1,1,1,1,9,1,1,1,1,1,1,1,1,   // 08
		1,9,1,9,9,9,9,9,9,9,1,1,9,9,9,9,9,9,9,1,   // 09
		1,9,1,1,1,1,9,1,1,9,1,1,1,1,1,1,1,1,1,1,   // 10
		1,9,9,9,9,9,1,9,1,9,1,9,9,9,9,9,1,1,1,1,   // 11
		1,9,1,9,1,9,9,9,1,9,1,9,1,9,1,9,9,9,1,1,   // 12
		1,9,1,9,1,9,9,9,1,9,1,9,1,9,1,9,9,9,1,1,   // 13
		1,9,1,1,1,1,9,9,1,9,1,9,1,1,1,1,9,9,1,1,   // 14
		1,9,1,1,9,1,1,1,1,9,1,1,1,1,9,1,1,1,1,1,   // 15
		1,9,9,9,9,1,1,1,1,1,1,9,9,9,9,1,1,1,1,1,   // 16
		1,1,9,9,9,9,9,9,9,1,1,1,9,9,9,1,9,9,9,9,   // 17
		1,9,1,1,1,1,1,1,1,1,1,9,1,1,1,1,1,1,1,1,   // 18
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,   // 19
	};

	int map_width = 20;
	int map_height = 20;
	struct MapInfo Map;
	Map.world_map = world_map;
	Map.map_width = map_width;
	Map.map_height = map_height;

    std::vector<int> start = {0, 0}; // Create a start state
    std::vector<int> end = {14, 10}; // Define the goal state

    auto [path_full, path_short] = find_path(start, end, Map);

    std::cout << "This is the full path:" << std::endl;
	for(long unsigned int i=0; i<path_full.size(); i=i+2)
  		std::cout << path_full[i] << "," << path_full[i+1] << std::endl;

	std::cout << "This is the short path:" << std::endl;
	for(long unsigned int i=0; i<path_short.size(); i=i+2)
  		std::cout << path_short[i] << "," << path_short[i+1] << std::endl;

	return 0;
}