/* ***************************************************************** */
/* File name:        controle.c                                    */
/* File description: File dedicated to the hardware abstraction layer*/
/*                   related CONTROLE       */
/* Author name:      Paulo e Marcus                                        */
/* Creation date:    29jun2017                                       */
/* Revision date:    29jun2017                                       */
/* ***************************************************************** */

#include "controle.h"

int cont = 0;

void initSpeedController(struct_PID_data *structPID_Data){
	structPID_Data->PGain = 1;
	structPID_Data->IGain = 0;
	structPID_Data->DGain = 1;
	structPID_Data->error_sum = 0;
	structPID_Data->sensor_value_previous = 0;
	return;
}

double PIDUpdate(struct_PID_data *structPID_Data, double dSensorValue,double dReferenceValue){
	double dPTerm, dITerm, dDTerm;
	double dError, dDifference;

	dError = dReferenceValue - dSensorValue;

	dPTerm = structPID_Data->PGain * dError; //proportional term

	structPID_Data->error_sum += dError; //current + cumulative
	dITerm = structPID_Data->IGain * structPID_Data->error_sum;

	dDifference = structPID_Data->sensor_value_previous - dSensorValue;

	structPID_Data->sensor_value_previous = dSensorValue;

	dDTerm = structPID_Data->DGain * dDifference;

	if(dDifference == 0){
		cont++;
	}else{
		cont = 0;
	}
	if(cont == 100){
		cont = 0;
	}

	return (dPTerm + dITerm + dDTerm);
}
