#include <Arduino.h>

#include "mesh\functions.h"

#include "variables.h"

String getNodeTable()
{
  String tableCode = "<tr><td>" + getMeshNodeId() + "</td><td><img class=\"layout\" src=\"img/c_Device_Controller.jpg\" alt=\"Controller\" title=\"Controller\"	display=\"inline-block\" name=\"statusImage\" /></img></td><td><img class=\"layout\" src=\"img/c_Status_On.jpg\" alt=\"Online\" title=\"Online\" display=\"inline-block\" name=\"statusImage\" /></img><img class=\"layout\" src=\"img/c_BatCharge_24.jpg\" alt=\"100%\" title=\"100%\" display=\"inline-block\"	name=\"battImage\" /></img></td><td><button type=\"button\" onclick=resetFME(" + getMeshNodeId() + ")>Neustart</button></td></tr>";
  SimpleList<uint32_t> nodes = getMeshNodesIds();
  SimpleList<uint32_t>::iterator node = nodes.begin();
  while (node != nodes.end())
  {
    tableCode = tableCode + "<tr><td>" + String(*node) + "</td><td><img class=\"layout\" src=\"img/c_Device_FME.jpg\" alt=\"Client\" title=\"Client\"	display=\"inline-block\" name=\"statusImage\" /></img></td><td><img class=\"layout\" src=\"img/c_Status_On.jpg\" alt=\"Online\" title=\"Online\" display=\"inline-block\" name=\"statusImage\" /></img><img class=\"layout\" src=\"img/c_BatCharge_24.jpg\" alt=\"100%\" title=\"100%\" display=\"inline-block\"	name=\"battImage\" /></img></td><td><button type=\"button\" onclick=resetFME(" + String(*node) + ")>Neustart</button><button type=\"button\" onclick=\"sendSingle(" + String(*node) + ")\">Alarmieren</button></td></tr>";
    node++;
  }
  return tableCode;
}