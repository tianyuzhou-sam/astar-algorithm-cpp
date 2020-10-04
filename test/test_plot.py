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
	# define the world
	map_width_meter = 10.0
	map_width_meter = 10.0
	map_resolution = 2
	# create a simulator
	Simulator = helper.Simulator(map_width_meter, map_width_meter, map_resolution)
	# number of obstacles
	num_obs = 20
	# generate random obstacles
	Simulator.generate_random_obs(num_obs)

	# define the start and goal
	start = [0, 0]
	end = [15, 15]
	
	# convert 2D numpy array to 1D list
	world_map = Simulator.map_array.flatten().tolist()
	# solve it
	path_full, path_short = AStarPython.FindPath(start, end, world_map, Simulator.map_width, Simulator.map_height)

	num_steps = len(path_full)/2 - 1
	print(num_steps)

	# visualization
	if len(path_full) > 0:
		Simulator.visualize(path_full, path_short)
	else:
		print("A Star didn't find a path!")

