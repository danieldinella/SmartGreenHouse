#include <iostream>
#include <random>
#include <hiredis/hiredis.h>
#include "pgsql.h"
#include <postgresql/libpq-fe.h>
#include <unistd.h>
#include "../../Camera/src/camera.h"
#include "../../Device/src/device.h"
#include "../../Sensor/src/sensor.h"
#include "../../Light/src/light.h"
#include "../../SensorGarden/src/sensorGarden.h"
#include "../../Conditioner/src/conditioner.h"
#include "../../Irrigator/src/irrigator.h"
#include <string.h>

#define HORIZON 10


typedef enum
{
    Camera,
    Conditioner,
    Device,
    Light,
    Sensor,
    SensorGarden,
    Irrigator
} components;

const char* componentToString(components comp);
void int2stateCamera(char *buf, camera_type x);
void int2stateConditioner(char *buf, conditioner_type x);
void int2stateDevice(char *buf, device_type x);
void int2stateLight(char *buf, light_type x);
void int2stateSensor(char *buf, sensor_type x);
void int2stateSensorGarden(char *buf, sensorGarden_type x);
void int2stateIrrigator(char *buf, irrigator_type x);
const char* colorToString(light_color color);
const char* nomeToString(nome_type nomeDev);
