#!/usr/bin/env python3
import os
import sys
sys.path.append(os.getcwd()+'/src')
import numpy as np
import matplotlib.pyplot as plt
from dataclasses import dataclass
from random import randint


@dataclass
class WorldInfo:
	world_map: list
	map_width: int
	map_height: int


class Simulator(object):
	resolution: int
	map_width: int
	map_height: int
	obs_size: float


	def __init__(self, 
		map_width_meter: float, 
		map_height_meter: float, 
		resolution: int):
		"""
		Constructor
		"""

		# map resolution, how many cells per meter
		self.resolution = resolution
		# how many cells for width and height
		map_width = map_width_meter * resolution
		map_height = map_height_meter * resolution

		# check if these are integers
		assert (map_width.is_integer() == True)
		assert (map_height.is_integer() == True)

		self.map_width = int(map_width)
		self.map_height = int(map_height)

		# create an empty map
		self.map_array = np.array([1]*(self.map_width*self.map_height)).reshape(-1, self.map_width)

		# the length [meter] of box obstacles
		self.obs_size = 1.0 * self.resolution


	def generate_random_obs(self, num_obs):
		obs_half_size = round(self.obs_size/2)
		for idx_obs in range(0, num_obs):
			# [width, height]
			obs_center = [randint(1+obs_half_size,self.map_width-obs_half_size), randint(1+obs_half_size, self.map_height-obs_half_size)]
			
			obs_mat = self.map_array[obs_center[1]-obs_half_size:obs_center[1]-obs_half_size+1][:, obs_center[0]-obs_half_size:obs_center[0]-obs_half_size+1]
			self.map_array[obs_center[1]-obs_half_size:obs_center[1]-obs_half_size+1][:, obs_center[0]-obs_half_size:obs_center[0]-obs_half_size+1] = 
				9 * np.ones(obs_mat.shape)


	def visualize(self, traj):
		"""
		traj is a list for the trajectory. [x[0], y[0], x[1], y[1], ...]
		"""


		fig_map, ax_map = plt.subplots(1, 1)
		ax_map.imshow(self.map_array, cmap='binary')
		ax_map.scatter(traj[0], traj[1], label="start")
		ax_map.scatter(traj[-2], traj[-1], label="goal")
		if len(traj) > 4:
			ax_map.plot(traj[0::2], traj[1::2], label="path")
		ax_map.legend(bbox_to_anchor=(1.05, 1), loc='upper left')
		ax_map.set_xlabel("x")
		ax_map.set_ylabel("y")

		plt.show()
