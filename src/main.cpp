#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//#include <getopt.h> TODO(bagus): should rewrite getopt()

#define HEIGHT 300
#define WIDTH 300
#define DEPTH 256
#define ITER 256
#define XSTART -2.5
#define XEND 1.5
#define YSTART 1.5
#define YEND 1.5

void
mandel_basic(unsigned char *image){
    float xdiff = XSTART - XEND;
    float ydiff = YSTART - YEND;
    float iter_scale = 1.0f /ITER;
    float depth_scale = DEPTH - 1;
    
#pragma omp parallel for schedule(dynamic, 1)
    for(int y = 0; y < HEIGHT; ++y) {
        for(int x = 0; x < WIDTH; ++x) {
            float cr = x* xdiff / WIDTH + XSTART;
            float ci = y * ydiff / HEIGHT + YSTART;
            float zr = cr;
            float zi = ci;
            int k = 0;
            float mk = 0.0f;
            while(++k < ITER) {
                float zr1 = zr * zr - zi * zi + cr;
                float zi1 = zr * zi + zr * zi + ci;
                zr = zr1;
                zi = zi1;
                mk+= 1.0f ;
                if (zr * zr + zi * zi >=4.0f) break;
            };
            mk *= iter_scale;
            mk = sqrtf(mk);
            mk *= depth_scale;
            int pixel = mk;
            image[y * WIDTH * 3 + x*3+0] = pixel;
            image[y * WIDTH * 3 + x*3+1] = pixel;
            image[y * WIDTH * 3 + x*3+2] = pixel;
            
        };
        
    };
};


#ifdef _WIN64
int
main(int argc,
     char *argv[],
     char *envp[]){
    printf("bagus");
};

#else 
int
main(int argc, char *argv[], char *envp[]){
    //unsigned char *image = (unsigned char*) malloc(WIDTH * HEIGHT * 3);
    //fwrite(image, WIDTH * HEIGHT, 3, stdout);
    //free(image);
    printf("%f", XSTART);
    return 0;
};
#endif