struct intpair {
	int a;
	int b;
};

program ADD_PROG {
	version ADD_VERS {
		int ADD(intpair) = 1;
        int SUB(intpair) = 2;
        int DIVI(intpair) = 3;
        int MUL(intpair) = 4;
	} = 1;
} = 0x23451111;
