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

#include "ClosestPointTest.h"

// use the ikaros namespace to access the math library
// this is preferred to using <cmath>

using namespace ikaros;


void
ClosestPointTest::Init()
{

    red			= GetInputMatrix("RED");
    green		= GetInputMatrix("GREEN");
    blue		= GetInputMatrix("BLUE");
    depth 		= GetInputMatrix("DEPTH");
    
    redc		= GetOutputMatrix("REDC");
    greenc		= GetOutputMatrix("GREENC");
    bluec		= GetOutputMatrix("BLUEC");
    depthc		= GetOutputMatrix("DEPTHC");
    output		= GetOutputArray("OUTPUT");
    
}



ClosestPointTest::~ClosestPointTest()
{

    

}



void
ClosestPointTest::Tick()
{
	
    redc = red;
    greenc = green;
    bluec = blue;
    depthc = depth;
    int small = 1;
    int smallestRow = 0;
    int smallestCol = 0;
    int nrows = sizeof(depth);
    int ncols = sizeof(depth[0]);

    for (int i = 0; i < nrows; ++i) {
        for (int j = 0; j < ncols; ++j){
            if (small < depth[i][j]){
                small = depth[i][j];
		smallestRow = i;
		smallestCol = j;
            }
        }

    }
    output[0] = smallestRow;
    output[1] = smallestCol;
/*
    int rowDiff1 = sizeof(depth)-(smallestRow+50);
    if (rowDiff1 < 0){
        rowDiff1 = smallestRow+50+rowDiff1;
    }
    int rowDiff2 = smallestRow-50;
    if (rowDiff2 < 0){
        rowDiff2 = smallestRow-50-rowDiff2;
    }
    int colDiff1 = sizeof(depth[0])-(smallestCol+50);
    if (colDiff1 < 0){
	colDiff1 = smallestCol+50+colDiff1;
    }
    int colDiff2 = smallestCol-50;
    if (colDiff2 < 0) {
	colDiff2 = smallestRow-50-rowDiff2;
    }

    for (int i = 0; i <rowDiff1; ++i){
        redc[smallestRow+i][smallestCol] = 0;
        greenc[smallestRow+i][smallestCol] = 0;
        bluec[smallestRow+i][smallestCol] = 0;
        depthc[smallestRow+i][smallestCol] = 0;
    }
    for (int i = 0; i <rowDiff2; ++i){
        redc[smallestRow-i][smallestCol] = 0;
        greenc[smallestRow-i][smallestCol] = 0;
        bluec[smallestRow-i][smallestCol] = 0;
        depthc[smallestRow-i][smallestCol] = 0;
    }
    for (int i = 0; i <colDiff1; ++i){
        redc[smallestRow][smallestCol+i] = 0;
        greenc[smallestRow][smallestCol+i] = 0;
	bluec[smallestRow][smallestCol+i] = 0;
	depthc[smallestRow][smallestCol+i] = 0;
    }
    for (int i = 0; i <colDiff2; ++i){
        redc[smallestRow][smallestCol-i] = 0;
        greenc[smallestRow][smallestCol-i] = 0;
	bluec[smallestRow][smallestCol-i] = 0;
	depthc[smallestRow][smallestCol-i] = 0;
    }
*/
}



// Install the module. This code is executed during start-up.

static InitClass init("ClosestPointTest", &ClosestPointTest::Create, "Source/UserModules/ClosestPointTest/");


