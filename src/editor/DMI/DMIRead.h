#ifndef DMIREAD_H
#define DMIREAD_H

#include <string>
#include <vector>

struct DMIState
{
	// Name of the state
	std::string name;
	// Number of directions the sprite has
	int dirs;
	// Number of animation frames per direction
	int frames;
	// Delay for each frame
	std::vector<unsigned int> delay;
	// Whether the animation should loop automatically
	bool loop;
};

struct DMIData
{
	// DMI version
	std::string version;
	// Width and height of the sprite
	unsigned int width, height;
	// Contains all DMIStates of this image
	std::vector<DMIState> states;
};

DMIData * DMIReadData(const char * path);

#endif