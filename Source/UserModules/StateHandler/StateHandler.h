//
//	StateHandler.h		This file is a part of the IKAROS project
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

#ifndef StateHandler_
#define StateHandler_

#include "IKAROS.h"

class StateHandler: public Module
{
public:
    static Module * Create(Parameter * p) { return new StateHandler(p); }

    StateHandler(Parameter * p) : Module(p) {}
    virtual ~StateHandler();

    void 		Init();
    void 		Tick();

    //each inputs first spot will be if they wanna change or not while the others are the state(s) it belongs to
    float *     input1;
    float *     input2;
    float *     input3;

    //each output will be a 1x2 vector with 0 being current state and 1 being value.
    float *	output1;
    float *	output2;
    float *	output3;

    //float *     internal_input_array;
    //float *	internal_output_array

    float	internalState;
    double	startTime;
    bool	timerStarted;
    int		waitTime;

};

#endif
