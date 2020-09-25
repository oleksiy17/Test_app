#ifndef TASK_1
#define TASK_1

#define BUFFER_DIV_COEFF            100        /* 1 / 10 ms*/
#define FMT_CHUNK_SIZE              24
#define FMT_CHUNK_AXILLARY_SIZE     26
#define MAX_GENERATOR_ARGS          7

#define SAMPLE_RATE_ID              0
#define DURATION_ID                 1
#define TYPE_GEN_ID                 2

#define ALL_GEN_TYPES_CNT           7
#define MS_IN_SEC                   1000

#define CHANNELS_NUM                2
#define BYTES_IN_CHANNEL            4
#define BITS_PER_SAMPLE             8

#define RIFF_BYTES                  4
#define WAVE_BYTES                  4
#define DATA_BYTES                  4
#define FMT_BYTES                   4
#define DATA_4BYTES                 4

#define PCM                         3

#include "stdint.h"


#include "gain_effect_control.h"
#include "gain_effect_process.h"
#include "../lib/LibGenerator/incGenerator/generator.h"



typedef enum {
    DELTA = 0,
    STEP = 1,
    SQUARE = 2,
    WHITE_NOISE = 3,
    SINE = 4,
    CHIRP = 5,
    LEVEL_SWEEP = 6,

    TOTAL_TYPES_NUM = 7
}type;


typedef struct {
    uint8_t* in_add;        // input path 
    uint8_t* out_add;       // output path 
    uint8_t*  gain;         // gain
    uint8_t* gen_type;      // generator string

}consoleArgs;

typedef struct {
    uint8_t    riff[4];                    // RIFF string
    uint32_t   overall_size;  	            // overall size of file in bytes
    uint8_t    wave[4];                    // WAVE string
} riffHeader;

typedef struct {
    uint8_t    fmt_chunk_marker[4];        // fmt string with trailing null char
    uint32_t   length_of_fmt;              // length of the format data
    uint16_t   format_type;                // format type
    uint16_t   channels;                   // # of channels
    uint32_t   sample_rate;                // sampling rate 
    uint32_t   byterate;                   // SampleRate * NumChannels * BitsPerSample/8
    uint16_t   block_align;                // NumChannels * BitsPerSample/8
    uint16_t   bits_per_sample;            // bits per sample, 8- 8bits, 16- 16 bits
    uint16_t   axillary_data;              // NOT USED BUT NECESSARY
}fmtHeader;

typedef struct {
    uint8_t    data_chunk_header[4];           // DATA string or FLLR string
    uint32_t   data_size;                  // NumSamples * NumChannels * BitsPerSample/8 - size of the next chunk that will be read
}dataHeader;

typedef struct {
    uint32_t sampleRate;
    uint32_t duration_ms;
    char* func;
}commonData;

typedef struct {
    uint32_t delay_ms;
}stepParams;

typedef struct {
    uint32_t period_ms;
}squareParams;

typedef struct {
    float amp_wh;
}whiteNoiseParams;

typedef struct {
    float freq_sin;
    float amp_sin;
}sineParams;

typedef struct {
    uint8_t* scale;
    float start_freq;
    float end_freq;
    float amp_chi;
}chirpParams;

typedef struct {
    float freq_sw;
    float start_amp;
    float end_amp;
}lvlSweepParams;

void copyWavFile(const char* inAddr, const char* outAddr);
void gainWavFile(const char* inAddr, const char* outAddr, const char* gain_val);
void generateWavFile(char* generator, const char* outAddr);

void printHeader(riffHeader* ptrRIFF, fmtHeader* ptrFMT, dataHeader* ptrDATA);
void fillHeader(riffHeader* ptrRIFF, fmtHeader* ptrFMT, dataHeader* ptrDATA, commonData* data);
#endif
