#!/usr/bin/env python3
import os
import sys
sys.path.append(os.getcwd()+'/build')
sys.path.append(os.getcwd()+'/src')
import AStarPython
import numpy as np
import matplotlib.pyplot as plt
from dataclasses import dataclass

import Simulator as helper


if __name__ == "__main__":
	# define the world map
	map_width = 20
	map_height = 20

	# world_map = [
	# # 00 01 02 03 04 05 06 07 08 09 10 11 12 13 14 15 16 17 18 19
	# 	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,   # 00
	# 	1,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,1,   # 01
	# 	1,9,9,1,1,9,9,9,1,9,1,9,1,9,1,9,9,9,1,1,   # 02
	# 	1,9,9,1,1,9,9,9,1,9,1,9,1,9,1,9,9,9,1,1,   # 03
	# 	1,9,1,1,1,1,9,9,1,9,1,9,1,1,1,1,9,9,1,1,   # 04
	# 	1,9,1,1,9,1,1,1,1,9,1,1,1,1,9,1,1,1,1,1,   # 05
	# 	1,9,9,9,9,1,1,1,1,1,1,9,9,9,9,1,1,1,1,1,   # 06
	# 	1,9,9,9,9,9,9,9,9,1,1,1,9,9,9,9,9,9,9,1,   # 07
	# 	1,9,1,1,1,1,1,1,1,1,1,9,1,1,1,1,1,1,1,1,   # 08
	# 	1,9,1,9,9,9,9,9,9,9,1,1,9,9,9,9,9,9,9,1,   # 09
	# 	1,9,1,1,1,1,9,1,1,9,1,1,1,1,1,1,1,1,1,1,   # 10
	# 	1,9,9,9,9,9,1,9,1,9,1,9,9,9,9,9,1,1,1,1,   # 11
	# 	1,9,1,9,1,9,9,9,1,9,1,9,1,9,1,9,9,9,1,1,   # 12
	# 	1,9,1,9,1,9,9,9,1,9,1,9,1,9,1,9,9,9,1,1,   # 13
	# 	1,9,1,1,1,1,9,9,1,9,1,9,1,1,1,1,9,9,1,1,   # 14
	# 	1,9,1,1,9,1,1,1,1,9,1,1,1,1,9,1,1,1,1,1,   # 15
	# 	1,9,9,9,9,1,1,1,1,1,1,9,9,9,9,1,1,1,1,1,   # 16
	# 	1,1,9,9,9,9,9,9,9,1,1,1,9,9,9,1,9,9,9,9,   # 17
	# 	1,9,1,1,1,1,1,1,1,1,1,9,1,1,1,1,1,1,1,1,   # 18
	# 	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1    # 19
    # ]

	# WorldInfo = helper.WorldInfo(world_map, map_width, map_height)

	Simulator = helper.Simulator(WorldInfo)


	# define the start and goal
	start = [0, 0]
	end = [4, 10]
	# solve it
	path = AStarPython.FindPath(start, end, WorldInfo.world_map, WorldInfo.map_width, WorldInfo.map_height)

	num_steps = len(path)/2 - 1
	print(num_steps)

	# visualization
	Simulator = helper.Simulator(WorldInfo)
	Simulator.visualize(path)

