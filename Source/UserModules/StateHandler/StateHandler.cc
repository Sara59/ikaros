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
#include <iostream>
#include <chrono>
//typedef std::chrono::high_resolution_clock Clock;
using namespace std;

// use the ikaros namespace to access the math library
// this is preferred to using <cmath>

using namespace ikaros;



void
StateHandler::Init()
{

    input1 = GetInputArray("INPUT1");
    input2 = GetInputArray("INPUT2");
    input3 = GetInputArray("INPUT3");
    input4 = GetInputArray("INPUT4");
    //input5 = GetInputArray("INPUT5");

    output1 = GetOutputArray("OUTPUT1");
    output2 = GetOutputArray("OUTPUT2");
    output3 = GetOutputArray("OUTPUT3");
    output4 = GetOutputArray("OUTPUT4");
    output5 = GetOutputArray("OUTPUT5");

    //internal_input_array = create_array(3);
    //internal_output_array = create_array(3);

    internalState = 0;
    //startTime = 0;
    timerStarted = false;
    waitTime = 0;
    previousState = 0;
    lookAway = false;
    
	input1[0] = 0;
	input2[0] = 0;

//./ikaros -R -t -r50 -p  ../Examples/Robots/EpiHead/EpiHead.ikc 

}



StateHandler::~StateHandler()
{
    
}

clock_t startTime;	

void
StateHandler::Tick()
{

         cout << "INTERNALSTATE: " <<  internalState ;

    //checks if any module wants to change state.
    cout << "Input1 value " << input1[0] << "\n";
    cout << "Input2 value " << input2[0] << "\n";
	cout << "Input3 value " << input3[0] << "\n";
	cout << "Input4 value " << input4[0] << "\n";
    
    if (input1[0] != internalState){
		cout << "fishin0";
		previousState = internalState;
	        internalState = input1[0];
		startTime = clock();
		//auto start = Clock::now();
	        waitTime = 1000000;
		timerStarted = true;
	if (internalState == 4 || internalState == 5){
	    waitTime = rand() % 100 + 50;
	    waitTime = waitTime/100;
	} else if (internalState == 3){
	    waitTime = rand() % 200 + 50;
	    waitTime = waitTime/100;
	} else if (internalState == 2){
	    waitTime = rand() % 900 + 300;
	    waitTime = waitTime/100;
	    lookAway = true;
	}
	
    } else if (input2[0] != internalState){
		cout << "fishin1";
		previousState = internalState;
	        internalState = input2[0];
		startTime = clock();
		//auto start = Clock::now();	
		timerStarted = true;
		waitTime = 1000000;
		if (internalState == 4 || internalState == 5){
		    waitTime = rand() % 100 + 50;
		    waitTime = waitTime/100;
		} else if (internalState == 3){
		    waitTime = rand() % 200 + 50;
		    waitTime = waitTime/100;
		} else if (internalState == 2){
		    waitTime = rand() % 900 + 300;
		    waitTime = waitTime/100;
		    lookAway = true;
		}
    } else if (input3[0] != internalState){
		previousState = internalState;
	        internalState = input3[0];
		startTime = clock();
		//auto start = Clock::now();
		timerStarted = true;
		waitTime = 1000000;
		if (internalState == 4 || internalState == 5){
		    waitTime = rand() % 100 + 50;
		    waitTime = waitTime/100;
		} else if (internalState == 3){
		    waitTime = rand() % 200 + 50;
		    waitTime = waitTime/100;
		} else if (internalState == 2){
		    waitTime = rand() % 900 + 300;
		    waitTime = waitTime/100;
		    lookAway = true;
		}
    } else if (input4[0] != internalState){
		previousState = internalState;
	        internalState = input4[0];
		startTime = clock();
		//auto start = Clock::now();
		timerStarted = true;
		waitTime = 1000000;
		if (internalState == 4 || internalState == 5){
		    waitTime = rand() % 100 + 50;
		    waitTime = waitTime/100;
		} else if (internalState == 3){
		    waitTime = rand() % 200 + 50;
		    waitTime = waitTime/100;
		} else if (internalState == 2){
		    waitTime = rand() % 900 + 300;
		    waitTime = waitTime/100;
		    lookAway = true;
		}
    } /*else if (input5[0] == internalState){
	previousState = internalState;
        internalState = input5[0];
	//time_t start = time(0);
	time_t start = clock();
	timerStarted = true;
	waitTime = 1000000;
	if (internalState == 4 || internalState == 5){
	    waitTime = rand() % 100 + 50;
	    waitTime = waitTime/100;
	} else if (internalState == 3){
	    waitTime = rand() % 200 + 50;
	    waitTime = waitTime/100;
	} else if (internalState == 2){
	    waitTime = rand() % 900 + 300;
	    waitTime = waitTime/100;
	    lookAway = true;
	}
    }
*/



    if (timerStarted){

		clock_t end = clock();	
		//auto end = Clock::now();
		//time_t end = time(0);
		//double t = difftime(end, startTime);
		cout << "starttime " << startTime << "\n";
		cout << "endtime " << end << "\n";
		clock_t wow = (end - startTime);
		double t = wow / CLOCKS_PER_SEC;
		//double t = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()/1000;
		//double t = (end - star);
		cout << "end-start" << t << "\n";;
		cout << "waittime " << waitTime << "\n";;
		if (t > waitTime){
		    if (lookAway){
			previousState = 2;
			internalState = 3;
			//waitTime = rand() % 200 + 50;
		    	//waitTime = waitTime/100;
			//timerStarted = true;
			lookAway = false;
		    } else {
			internalState = 2; 
			startTime = 0;
			
		    }
		    timerStarted = false;
		    waitTime = 0;
	    
		}
	
    }  
    cout << "fishinternal" << internalState;
   
    output1[0] = internalState;
    output2[0] = internalState;
    output3[0] = internalState;
    output4[0] = internalState;
    output5[0] = internalState;

}




// Install the module. This code is executed during start-up.

static InitClass init("StateHandler", &StateHandler::Create, "Source/UserModules/StateHandler/");


