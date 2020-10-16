#!/usr/bin/env python3
import os
import sys
sys.path.append(os.getcwd()+'/build')
sys.path.append(os.getcwd()+'/src')
import AStarPython
import numpy as np
import time
import matplotlib.pyplot as plt

import Simulator as helper


if __name__ == "__main__":
    # define the world
    map_width_meter = 20.0
    map_height_meter = 20.0
    map_resolution = 2
    value_non_obs = 1 # the cell is empty
    value_obs = 9 # the cell is blocked
    # create a simulator
    Simulator = helper.Simulator(map_width_meter, map_height_meter, map_resolution, value_non_obs, value_obs)
    # number of obstacles
    num_obs = 100
    # [width, length] size of each obstacle [meter]
    size_obs = [1, 1]
    # generate random obstacles
    Simulator.generate_random_obs(num_obs, size_obs)
    # convert 2D numpy array to 1D list
    world_map = Simulator.map_array.flatten().tolist()


    # define the start and goal
    start = [0, 0]
    end = [35, 18]
    # solve it
    t0 = time.time()
    path_short, steps_used = AStarPython.FindPath(start, end, world_map, Simulator.map_width, Simulator.map_height)
    t1 = time.time()
    print("Time used for a single path is [sec]:")
    print(t1-t0)
    print("This is the path. " + "Steps used:" + str(steps_used))
    for idx in range(0,len(path_short),2):
        str_print = str(path_short[idx]) + ', ' + str(path_short[idx+1])
        print(str_print)
    # visualization (uncomment next line if you want to visualize a single path)
    Simulator.plot_single_path(path_short)


    # This is for an agent and a set of targets
    agent_position = [0, 0]
    targets_position = [35,35, 10,38, 30,6, 25,29]
    # solve it
    t0 = time.time()
    path_many, steps_all = AStarPython.FindPathAll(agent_position, targets_position, world_map, Simulator.map_width, Simulator.map_height)
    t1 = time.time()
    print("Time used for many paths is [sec]:")
    print(t1-t0)

    print("These are all the paths:")
    for i in range(0,len(path_many),1):
        print("This is a path. " + "Steps used:" + str(steps_all[i]))
        for j in range(0,len(path_many[i]),2):
            str_print = str(path_many[i][j]) + ', ' + str(path_many[i][j+1])
            print(str_print)
    # visualization
    Simulator.plot_many_path(path_many, agent_position, targets_position)
