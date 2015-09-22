#include "utilsawesome.h"
/*
 *    Concatenates the information from one Reading to the tx_buf
 *
 *    The format of one reading string is:
 *        reading->name:reading->value:reading->timestamp;
 *
 *    With real information coming from sensors should look like:
 *        "distance:205.00:5623;"
 *
 *    When many Readings have been attached having called this function several times
 *      this is how the tx_buf looks like:
 *        "distance:205.00:18323;temperature:24.00:18323;humidity:45.10:1832"
 *
 */

void append(char *buf, Reading r){
    char size = sizeof(r);
    char tmp[size];
    memset(tmp, 0, size);
    sprintf(tmp, "%u,%u,%.2f,%s;", r.node_id, r.sensor_id, r.value, r.timestamp);
    strcat(buf, tmp);
}
