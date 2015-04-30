// #include <string>
#ifdef __cplusplus
extern "C" {
#endif



typedef struct Reading{
	char *name;
	double value;
	long timestamp;
};

typedef struct Reading_new{
	char *name;
	double value;
	char* timestamp;
};

void add_to_tx_buf(char *tx_buf, struct Reading *reading);
void add_to_tx_buf_new(unsigned char *tx_buf, struct Reading *reading);
void add_to_tx_buf_new_new(unsigned char *tx_buf, struct Reading_new *reading);

#ifdef __cplusplus
}
#endif
