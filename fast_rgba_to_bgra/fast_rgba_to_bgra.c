//
// Created by Cameron Roe on 2019-04-16.
//

#define SAMPLE_WIDTH 100
#define SAMPLE_HEIGHT 100

#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct _rgbaSample {
    uint32_t red: 8;
    uint32_t green: 8;
    uint32_t blue: 8;
    uint32_t alpha: 8;
} rgbaSample;

typedef struct _bgraSample {
    uint32_t blue: 8;
    uint32_t green: 8;
    uint32_t red: 8;
    uint32_t alpha: 8;
} bgraSample;

void rgbaToBgra(rgbaSample* src, bgraSample* dest) {
    dest->red = src->red;
    dest->green = src->green;
    dest->blue = src->blue;
    dest->alpha = src->alpha;
}

void bgraToRgba(bgraSample* src, rgbaSample* dest) {
    dest->red = src->red;
    dest->green = src->green;
    dest->blue = src->blue;
    dest->alpha = src->alpha;
}

rgbaSample* createRgbaSample(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha) {
    rgbaSample* sample = (rgbaSample*) malloc(sizeof(rgbaSample));
    sample->red = red;
    sample->green = green;
    sample->blue = blue;
    sample->alpha = alpha;
    return sample;
}

bgraSample* createBgraSample(uint8_t blue, uint8_t green, uint8_t red, uint8_t alpha) {
    bgraSample* sample = (bgraSample*) malloc(sizeof(bgraSample));
    sample->red = red;
    sample->green = green;
    sample->blue = blue;
    sample->alpha = alpha;
    return sample;
}

int main() {
    printf("%d\n", sizeof(rgbaSample));
    rgbaSample* testSample = createRgbaSample(15, 240, 255, 0);
    printf("red: %d\n", testSample->red);
    printf("blue: %d\n", testSample->blue);
    printf("green: %d\n", testSample->green);
    printf("alpha: %d\n", testSample->alpha);
    printf("hex: 0x%.8x\n", *testSample);

    printf("%d\n", sizeof(bgraSample));
    bgraSample* testSample2 = (bgraSample*) malloc(sizeof(bgraSample));
    rgbaToBgra(testSample, testSample2);
    printf("red: %d\n", testSample2->red);
    printf("blue: %d\n", testSample2->blue);
    printf("green: %d\n", testSample2->green);
    printf("alpha: %d\n", testSample2->alpha);
    printf("hex: 0x%.8x\n", *testSample2);

    printf("%d\n", sizeof(bgraSample));
    bgraSample* testSample3 = createBgraSample(255, 240, 15, 0);
    printf("red: %d\n", testSample3->red);
    printf("blue: %d\n", testSample3->blue);
    printf("green: %d\n", testSample3->green);
    printf("alpha: %d\n", testSample3->alpha);
    printf("hex: 0x%.8x\n", *testSample3);

    uint8_t* testSamples = (uint8_t*) testSample2;
    printf("testSamples[0]: %d => %.2x\n", testSamples[0], testSamples[0]);
    printf("testSamples[1]: %d => %.2x\n", testSamples[1], testSamples[1]);
    printf("testSamples[2]: %d => %.2x\n", testSamples[2], testSamples[2]);
    printf("testSamples[3]: %d => %.2x\n", testSamples[3], testSamples[3]);

    free(testSample);
    free(testSample2);
    free(testSample3);
    return 0;
}