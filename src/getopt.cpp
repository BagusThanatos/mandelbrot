//#include "getopt.h"

int getopt(
int argc,
char *argvp[],
char *optstring){
    
    if(optind >= argc){
        return -1;
    };
    char *opt = *argvp[optind];
    if (!opt || *opt != '-'){
        if (*(opt+1) == '-' && !*(opt+2)){
            ++optind;
            return -1;
        };
        if (!(opt+1))
            return -1;
    };
    char *optstr = *optstring;
    if(*optstr == ':') return ':';
    
    ++opt;
    while(*optstr != '\0'){
        if(*optstr == *opt){
            if (*(optstr+1) == ':') {
                if(optind + 1 >= argc) {
                    // error here
                    return '?';
                };
                
                optarg = argvp[optind+1];
                ++optind;
            };
        };
        ++optstr;
    };
    if(*optstr == '\0') return '?';
    ++optind;
    return *opt;;
};

int getopt_long(
int argc, 
char *argv[],
struct option *Longopts,
int *Longindex){
    
    return 0;
};

int getopt_long_only(
int argc,
char *argv[],
char *optstring,
struct option *Longopts,
int *Longindex){
    
    return 0;
};