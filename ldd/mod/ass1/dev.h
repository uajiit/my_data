struct dev_ops{
void (*open)( void);
//int (*read)();
//int (*write)(int);
void (*close)( void);
};

void dev1_open( void);

void dev1_close( void);
int dev2_init2(void);
void dev2_exit2(void);
void dev2_open( void);
void dev2_close( void);
