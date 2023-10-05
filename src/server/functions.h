#include <ESPAsyncWebServer.h>
#include <AsyncTCP.h>

#include "alarm\functions.h"
#include "filesystem\functions.h"
#include "html\functions.h"
#include "mesh\functions.h"

#include "variables.h"

void notFound(AsyncWebServerRequest *);
void initServer();