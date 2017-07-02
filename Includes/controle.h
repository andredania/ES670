/* ***************************************************************** */
/* File name:        controle.h                                    */
/* File description: Header file containing the functions/methods    */
/*                   interfaces for handling CONTROLE from the         */
/*                   peripheral board                                */
/* Author name:      Paulo e Marcus                                        */
/* Creation date:    29jun2017                                       */
/* Revision date:    29jun2017                                       */
/* ***************************************************************** */

#ifndef CONTROLE_H_
#define CONTROLE_H_

typedef struct PID_DATA{
	double PGain, DGain, IGain;
	double sensor_value_previous;  //find the derivative
	double error_sum; //cumulative error
}struct_PID_data;

void initSpeedController(struct_PID_data *structPID_Data);

double PIDUpdate(struct_PID_data *structPID_Data, double dSensorValue,double dReferenceValue);
#endif /* CONTROLE_H_ */
