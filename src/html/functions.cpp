#include <Arduino.h>

#include "mesh\functions.h"

#include "variables.h"

String getNodeTable()
{
  String tableCode = "<tr><td>" + getMeshNodeId() + "</td><td>Controller</td><td>Online</td><td><button type=\"button\" onclick=\"resetFME(" + getMeshNodeId() + ")\">Neustart</button><button type=\"button\" disabled>Alarmieren</button></td></tr>";
  SimpleList<uint32_t> nodes = getMeshNodesIds();
  SimpleList<uint32_t>::iterator node = nodes.begin();
  while (node != nodes.end())
  {
    tableCode = tableCode + "<tr><td>" + String(*node) + "</td><td>Client</td><td>Online</td><td><button type=\"button\" onclick=\"resetFME(" + String(*node) + ")\">Neustart</button><button type=\"button\" onclick=\"sendSingle(" + String(*node) + ")\">Alarmieren</button></td></tr>";
    node++;
  }
  return tableCode;
}