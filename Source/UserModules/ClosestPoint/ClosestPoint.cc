//
//	MyModule.cc		This file is a part of the IKAROS project
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

#include "ClosestPoint.h"
#include <iostream>
#include <math.h>
using namespace std;

// use the ikaros namespace to access the math library
// this is preferred to using <cmath>

using namespace ikaros;


void
ClosestPoint::Init()
{

    depth 		= GetInputMatrix("DEPTH");
    depthX		= GetInputSizeX("DEPTH");
    depthY		= GetInputSizeY("DEPTH");

    output 		= GetOutputMatrix("OUTPUT");
    connected		= InputConnected("DEPTH");
    Bind(divider, "matrixsize"); 

    //extensions to the module
    inputState		= GetInputArray("INSTATE");
    outputState		= GetOutputArray("OUTSTATE");
    value		= GetOutputArray("VALUE");

	inputState[0] = 0;
    
}



ClosestPoint::~ClosestPoint()
{

    

}



void
ClosestPoint::Tick()
{	

    if (connected){
        //cout << "depth: " <<  fixed << depth[50][50];
    }

	
    int depthYY= (depthY)/divider;
    int depthXX= (depthX)/divider;
    int numberOfParts = depthYY*depthXX;



    int count = 0;
    int count2 = 0;
 
    double views[numberOfParts];


    //basically loops through all pixels and add them together in matrices. Strange values are not added.
    while (count < numberOfParts-depthXX){
	views[count] = 0;
	int correctPixels = 0;
        for (int i = (count % depthXX)*divider; i <= (count % depthXX)*divider+divider; ++i){
	    for (int j = 0+(count2*divider); j < (count2*divider)+divider; ++j){

		if (depth[j][i] < 10000 && depth[j][i] > 500){
		    views[count] += depth[j][i];
		    correctPixels++;
		}
		
		
	    }   
        }
	
	views[count] = views[count] / (correctPixels);
	if (count%depthXX == 0) {
	    count2++;
	}
	
	count++;
	
	
    }

    double smallest = 100000;
    double smallestPart = 0;
    
    //Removes the matrices on the edge by setting their value too high so they don't count. (Often strange values)
    for (int i = 0; i <= numberOfParts-depthXX; i+=depthXX){
	if (!(i-1 < 0 && i+1 > numberOfParts-depthXX)){
	    views[i-1] = 10001;
	    views[i] = 10001;
	}
    }

    //finds the biggest part, can be done in the master loop so we don't have to do one more loop, will probably fix in the future
    for (int i = 0; i < numberOfParts; i++){
	if (views[i] < smallest && !(views[i] < 10) && !(views[i] > 10000)){
	    smallest = views[i];
	    smallestPart = i;
	}
    }

    
    int smallestPartInt = smallestPart;
    double xCoord = (smallestPartInt%depthXX)*divider+(divider/2);
    double yCoord = floor(smallestPartInt/depthXX)*divider+(divider/2);

    output[0][3] = xCoord;
    output[1][3] = yCoord;
    output[2][3] = smallest;
    output[0][0] = 1;
    output[1][1] = 1;
    output[2][2] = 1;
    output[3][3] = 1;
    
    double scaler = 1;



    if (inputState[0] == 0 || inputState[0] == 1 || inputState[0] == 3 || inputState[0] == 4){
        scaler = 0;
    } else if (inputState[0] == 2){
        scaler = 0.75;
    } else if (inputState[0] == 5){
	scaler = 1;
    }

    if (smallest <= 600){
        value[0]= 1*scaler;

    } else {
	value[0] = (600/(smallest))*scaler;
    } 
    	cout << "ClosestPoint value: " << value[0] << "\n";
    if (value[0] >= 0.9*scaler){
	cout << "ClosestPoint changing state \n";
        outputState[0] = 5;
    } 

}





// Install the module. This code is executed during start-up.

static InitClass init("ClosestPoint", &ClosestPoint::Create, "Source/UserModules/ClosestPoint/");


