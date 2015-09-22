// #include <string>
#ifdef __cplusplus
extern "C" {
#endif

    typedef struct Reading{
        unsigned int node_id;
        unsigned int sensor_id;
        double value;
        //len('2015-09-22 21:54:53')
        char timestamp[20];
    } Reading;

    void append_reading(char *buf, Reading *r);


#ifdef __cplusplus
}
#endif
