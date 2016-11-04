//
//	StateHandler.cc		This file is a part of the IKAROS project
//
//    Copyright (C) 2012 <Author Name>
//
//    This program is free software; you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation; either version 2 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program; if not, write to the Free Software
//    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//
//    See http://www.ikaros-project.org/ for more information.
//
//  This example is intended as a starting point for writing new Ikaros modules
//  The example includes most of the calls that you may want to use in a module.
//  If you prefer to start with a clean example, use he module MinimalModule instead.
//

#include "StateHandler.h"
#include <time.h>
#include <stdlib.h> 

// use the ikaros namespace to access the math library
// this is preferred to using <cmath>

using namespace ikaros;


void
StateHandler::Init()
{

    input1 = GetInputArray("INPUT1");
    input2 = GetInputArray("INPUT2");
    input2 = GetInputArray("INPUT2");

    output1 = GetOutputArray("OUTPUT1");
    output2 = GetOutputArray("OUTPUT2");
    output3 = GetOutputArray("OUTPUT3");

    //internal_input_array = create_array(3);
    //internal_output_array = create_array(3);

    internalState = 0;
    startTime = 0;
    timerStarted = false;
    waitTime = 0;


}



StateHandler::~StateHandler()
{
    
}



void
StateHandler::Tick()
{

    if (timerStarted){
	time_t end = time(0);
	double time = difftime(end, startTime);
	if (time > (double) waitTime){
	    internalState = 0; //TODO:change this to either decrement or to the right state
	    startTime = 0;
	    waitTime = 0;
	    timerStarted = false;
	}
    }

    
    

    //checks if any module wants to change state.
    if (input1[0] != 0){
        if (input1[0] == 1){
	    internalState++;
	} else if (input1[0] == 2){
	    internalState--;
	} else if (input1[0] == 7 && !timerStarted){ //TODO:change this to the correct state
	    time_t start = time(0);
	    timerStarted = true;
	    waitTime = rand() % 3 + 1;
	}
    } else if (input2[0] != 0){
        if (input2[0] == 1){
	    internalState++;
	} else if (input2[0] == 2){
	    internalState--;
	} else if (input2[0] == 7 && !timerStarted){ //TODO:change this to the correct state
	    time_t start = time(0);
	    timerStarted = true;
	    waitTime = rand() % 3 + 1;
	}
    } else if (input3[0] != 0){
        if (input3[0] == 1){
	    internalState++;
	} else if (input3[0] == 2){
	    internalState--;
	} else if (input3[0] == 7 && !timerStarted){ //TODO:change this to the correct state
	    time_t start = time(0);
	    timerStarted = true;
	    waitTime = rand() % 3 + 1;
	}
    }

    output1[0] = internalState;
    output2[0] = internalState;
    output3[0] = internalState;
}



// Install the module. This code is executed during start-up.

static InitClass init("StateHandler", &StateHandler::Create, "Source/UserModules/StateHandler/");


