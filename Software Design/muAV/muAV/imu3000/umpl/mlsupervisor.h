/*
 $License:
    Copyright (C) 2011 InvenSense Corporation, All Rights Reserved.
 $
 */

/******************************************************************************
 *
 * $Id: mlsupervisor.h 5762 2011-07-12 23:20:19Z kkeal $
 *
 *****************************************************************************/

#ifndef __INV_SUPERVISOR_H__
#define __INV_SUPERVISOR_H__

#include "mltypes.h"
#ifdef INV_INCLUDE_LEGACY_HEADERS
#include "mlsupervisor_legacy.h"
#endif

#define CAL_RUN             0
#define CAL_RESET           1
#define CAL_CHANGED_DATA    2
#define CAL_RESET_TIME      3
#define CAL_ADD_DATA        4
#define CAL_COMBINE         5

#define P_INIT  100000L

#define SF_NORMAL           0
#define SF_DISTURBANCE      1
#define SF_FAST_SETTLE      2
#define SF_SLOW_SETTLE      3
#define SF_STARTUP_SETTLE   4
#define SF_UNCALIBRATED     5

struct inv_supervisor_cb_obj {
     inv_error_t(*progressive_no_motion_supervisor_func) (unsigned long
                                                          deltaTime);
     inv_error_t(*sensor_fusion_advanced_func) (double *magFB,
                                                unsigned long deltaTime);
    void (*reset_advanced_compass_func) (void);
    void (*supervisor_reset_func) (void);
};

inv_error_t inv_reset_compass_calibration(void);
void inv_init_sensor_fusion_supervisor(void);
inv_error_t inv_accel_compass_supervisor(void);
inv_error_t inv_pressure_supervisor(void);

#endif // __INV_SUPERVISOR_H__

