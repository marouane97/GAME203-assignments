#include <iostream>
#include "GameManager.h"
#include "MMath.h"
#include <string>
///#include <SDL.h>
using namespace MATH;

int main(int argc, char* args[]) { /// Standard C-style entry point, you need to use it
	
	GameManager *ptr = new GameManager();
	bool status  = ptr->OnCreate();
	if (status == true) {
		ptr->Run(); 
	} else if (status == false) {
		/// You should have learned about stderr (std::cerr) in Operating Systems 
		std::cerr << "Fatal error occured. Cannot start this program" << std::endl;
	}
	delete ptr;
	
	return 0;
}

//Press ESC to close the render window

//To do:
//Create the link between screen resolution units and space units
//GameManager has int screen resolution
//Scene01 has orthographic 

//The picture height and width are in body->getImage().h/w