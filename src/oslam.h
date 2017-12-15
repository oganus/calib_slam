#ifndef _OSLAM_H_
#define _OSLAM_H_

class OSLAM {
public:
	OSLAM(char **argv) : _argv(argv) {}
	void run();
private:
	char ** _argv;
};

#endif // _OSLAM_H_