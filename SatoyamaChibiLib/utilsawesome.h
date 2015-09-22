// #include <string>
#ifdef __cplusplus
extern "C" {
#endif




typedef struct Reading{
        unsigned int node_id;
        unsigned int sensor_id;
        double value;
        
        char timestamp[20]; // Ex. "2015-09-22 21:54:53"
} Reading;

void append(char *buf, Reading r)



#ifdef __cplusplus
}
#endif
