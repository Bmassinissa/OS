int nFork(int nbProcs){
	int i;
	for(i=1;i<=nbProcs;i++)
		switch(fork()){
			case -1: return -1;
			case 0: return i;
		}
	return 0;
}
int int main(void)
{
	/* code */
	return 0;
}
