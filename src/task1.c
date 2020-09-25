#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"


#include "task1.h"
//#include "getopt.h"







/*int main(int argc, char** argv)
{
    /*FILE *existance; 
    FILE *new_create; 

    size_t numRead;
    size_t numWrite;

    /*waveFileHeader wavHeader;
    waveFileHeader *ptrWavHeader = &wavHeader;

    riffHeader RIFF;
    riffHeader *ptrRIFF = &RIFF;

    fmtHeader FMT;
    fmtHeader *ptrFMT = &FMT;

    dataHeader DATA;
    dataHeader *ptrDATA = &DATA;

    params argument;


   // size_t bufSize, loop_cnt;


    uint32_t i;
    uint32_t j;
    uint8_t* pch; 
    float multiplier;
    char tp;

    char opt;
    int longind;


    uint8_t *type_str[TOTAL_TYPES_NUM] = {
    "delta",
    "step",
    "square",
    "white_noise",
    "sine",
    "chirp",
    "level_sweep"
};

    const char *options = "i:o:g:G:";
    const struct option long_options[] = {
                                            {"in",  required_argument, NULL, 'i'},
                                            {"out",  required_argument, NULL, 'o'},
                                            {"gain",    required_argument, NULL, 'g'},
                                            {"generator",    required_argument, NULL, 'G'} 
    };
                                            
    argument =(params){ NULL,
                NULL,
                0.0,
                NULL,
                0,
                0,
                0,
                0.0,
                0.0,
                NULL,
                0.0,
                0.0,
                0.0,
                0.0 };


    while ((opt = getopt_long(argc, argv, options, long_options, &longind)) != -1)
    {
        switch (opt) 
        {
            /* if we have input file, open it
            case 'i':
            {
                argument.in_add = optarg;
                printf("\nInput address: = %s\n", argument.in_add);
                break;
            }

            /* if we have output file, create it 
            case 'o':
            {
                argument.out_add = optarg;
                printf("Output address: = %s \n\n", argument.out_add);
                break;
            }

            /* if we have gain, calculates multiplier 
            case 'g':
            {
                argument.gain = atof(optarg);

                /*  Calculating Gain multiplier  

                if (effect_update_coeffs(&argument.gain, &multiplier) == 1)
                {
                    printf("Gain value %f is %f multiplier\n", argument.gain, multiplier);
                }

                break;
            }

            /* if we have generator parameter, create signal 
            case 'G':
            {               
                pch = strtok(optarg, ",");

                i = 0;

                while (pch != NULL && (i != 3))                     //mandatory generator parameters
                {
                    if (i == 0)
                    {
                        argument.sampleRate = atoi(pch);
                        printf("Sample rate : %d\n", argument.sampleRate);
                        pch = strtok(NULL, ",");
                    }

                    if (i == 1)
                    {
                        argument.length = atoi(pch);
                        printf("Dauration : %d\n", argument.length);
                        pch = strtok(NULL, ",");
                    }

                    if (i == 2)
                    {
                        argument.gen_type = pch;
                        printf("Generator : %s\n", argument.gen_type);
                        pch = strtok(NULL, ",");
                    }
                    i++;
                }

                /*
                for (i = 0; i < TOTAL_TYPES_NUM; i++)
                {
                    if (strcmp(argument.gen_type, type_str[i]) == 0)
                    {
                        tp = i;
                    }
                    break;
                }

                switch (tp)
                {
                    case DELTA:
                    {

                        break;
                    }

                }

                
                
                break;
            }

            default:
                break;
        }
    }
/*
    
    if ((existance = fopen(argument.in_add, "rb")) == NULL)
    {
        printf("ERROR in opening existance file!\n");
    }

    if ((new_create = fopen(argument.out_add, "w+b")) == NULL)
    {
        printf("ERROR in opening new file!\n");
    }
    /* read header */
    /*
    numRead = fread(ptrRIFF, sizeof(uint8_t), sizeof(riffHeader), existance);
    if (numRead == sizeof(riffHeader))
    {
        printf("ALL RIFF HEADER READED : %d from %d!\n", numRead, sizeof(riffHeader));
    }

    numRead = fread(ptrFMT, sizeof(uint8_t), sizeof(fmtHeader), existance);
    if (numRead == sizeof(fmtHeader))
    {
        printf("ALL FMT HEADER READED : %d from %d!\n", numRead, sizeof(fmtHeader));
    }

    fseek(existance, -2, SEEK_CUR);     //костыль

    numRead = fread(ptrDATA, sizeof(uint8_t), sizeof(dataHeader), existance);
    if (numRead == sizeof(dataHeader))
    {
        printf("ALL DATA HEADER READED : %d from %d!\n", numRead, sizeof(dataHeader));
    }

    printf("Length of fmt = %d\n", (FMT.length_of_fmt + 8));

    printHeader(ptrRIFF, ptrFMT, ptrDATA);

    bufSize = (FMT.sample_rate / BUFFER_DIV_COEFF) * FMT.block_align;
    printf("Buffer size = %d\n", bufSize);

    loop_cnt = DATA.data_size / bufSize;
    printf("Loops = %d\n", loop_cnt);

    numWrite = fwrite(ptrRIFF, sizeof(uint8_t), sizeof(riffHeader), new_create);
    numWrite = fwrite(ptrFMT, sizeof(uint8_t), (FMT.length_of_fmt + 8), new_create);
    numWrite = fwrite(ptrDATA, sizeof(uint8_t), sizeof(dataHeader), new_create);
 
    void *buffer = (uint8_t*)malloc(bufSize);
    int gain_loop_cnt = (bufSize / (FMT.block_align / FMT.channels));
    float *unit_sample = (float*)buffer;

    for (int i = 0; i < loop_cnt; i++)
    {

        numRead = fread(buffer, sizeof(uint8_t), bufSize, existance);

        for (int j = 0; j < gain_loop_cnt; j++)
        {
            unit_sample[j] *= multiplier;
        }

        numWrite = fwrite(buffer, sizeof(uint8_t), bufSize, new_create);
    }
    
   return 0;
}*/
 
void copyWavFile(const char* inAddr, const char* outAddr)
{
    FILE* existance;
    FILE* created;

    size_t numRead;
    size_t numWrite;

    riffHeader RIFF;
    riffHeader* ptrRIFF = &RIFF;

    fmtHeader FMT;
    fmtHeader* ptrFMT = &FMT;

    dataHeader DATA;
    dataHeader* ptrDATA = &DATA;

    size_t bufSize;
    size_t loop_cnt;
    uint32_t i;

    void* buffer;

    if ((existance = fopen(inAddr, "rb")) == NULL)      /*  Open existance .wav file    */
    {
        printf("ERROR in opening existance file!\n");
    }
    
    if ((created = fopen(outAddr, "w+b")) == NULL)      /*  Create new .wav file    */
    {
        printf("ERROR in creating new file!\n");
    }
    
    numRead = fread(ptrRIFF, sizeof(uint8_t), sizeof(riffHeader), existance);
    printf("NumRead : %d\n", numRead);
    if (numRead == sizeof(riffHeader))
    {
        printf("ALL RIFF HEADER READED : %d from %d!\n", numRead, sizeof(riffHeader));
    }

    numRead = fread(ptrFMT, sizeof(uint8_t), sizeof(fmtHeader), existance);
    if (numRead == sizeof(fmtHeader))
    {
        printf("ALL FMT HEADER READED : %d from %d!\n", numRead, sizeof(fmtHeader));
    }


    if ((ptrFMT->length_of_fmt + 8) == FMT_CHUNK_SIZE)
    {
        fseek(existance, -4, SEEK_CUR);
    }

    if ((ptrFMT->length_of_fmt + 8) == FMT_CHUNK_AXILLARY_SIZE)
    {
        fseek(existance, -2, SEEK_CUR);
    }

    numRead = fread(ptrDATA, sizeof(uint8_t), sizeof(dataHeader), existance);
    if (numRead == sizeof(dataHeader))
    {
        printf("ALL DATA HEADER READED : %d from %d!\n", numRead, sizeof(dataHeader));
    }

    printHeader(ptrRIFF, ptrFMT, ptrDATA);

    bufSize = (ptrFMT->sample_rate / BUFFER_DIV_COEFF) * ptrFMT->block_align;
     printf("Buffer size = %d\n", bufSize);

    loop_cnt = ptrDATA->data_size / bufSize;
    printf("Loops = %d\n", loop_cnt);

    buffer = (uint8_t*)malloc(bufSize);

    numWrite = fwrite(ptrRIFF, sizeof(uint8_t), sizeof(riffHeader), created);
    numWrite = fwrite(ptrFMT, sizeof(uint8_t), (ptrFMT->length_of_fmt + 8), created);
    numWrite = fwrite(ptrDATA, sizeof(uint8_t), sizeof(dataHeader), created);

    for (i = 0; i < loop_cnt; i++)
    {
        numRead = fread(buffer, sizeof(uint8_t), bufSize, existance);
        numWrite = fwrite(buffer, sizeof(uint8_t), bufSize, created);
    }

}

void gainWavFile(const char* inAddr, const char* outAddr, const char* gain_val)
{
    float gain;
    float multiplier;

    float* unit_sample;
    void* buffer;

    FILE* existance;
    FILE* created;

    size_t numRead;
    size_t numWrite;

    riffHeader RIFF;
    riffHeader* ptrRIFF = &RIFF;

    fmtHeader FMT;
    fmtHeader* ptrFMT = &FMT;

    dataHeader DATA;
    dataHeader* ptrDATA = &DATA;

    size_t bufSize;
    size_t loop_cnt;
    size_t gain_loop_cnt;
    uint32_t i;
    uint32_t j;

    gain = atof(gain_val);

    if (gain_effect_update_coeffs(&gain, &multiplier) == 1)
    {
        printf("Gain value %f is %f multiplier\n", gain, multiplier);
    }

    if ((existance = fopen(inAddr, "rb")) == NULL)      /*  Open existance .wav file    */
    {
        printf("ERROR in opening existance file!\n");
    }

    if ((created = fopen(outAddr, "w+b")) == NULL)      /*  Create new .wav file    */
    {
        printf("ERROR in creating new file!\n");
    }

    numRead = fread(ptrRIFF, sizeof(uint8_t), sizeof(riffHeader), existance);
    printf("NumRead : %d\n", numRead);
    if (numRead == sizeof(riffHeader))
    {
        printf("ALL RIFF HEADER READED : %d from %d!\n", numRead, sizeof(riffHeader));
    }

    numRead = fread(ptrFMT, sizeof(uint8_t), sizeof(fmtHeader), existance);
    if (numRead == sizeof(fmtHeader))
    {
        printf("ALL FMT HEADER READED : %d from %d!\n", numRead, sizeof(fmtHeader));
    }

    if ((ptrFMT->length_of_fmt + 8) == FMT_CHUNK_SIZE)
    {
        fseek(existance, -4, SEEK_CUR);
    }

    if ((ptrFMT->length_of_fmt + 8) == FMT_CHUNK_AXILLARY_SIZE)
    {
        fseek(existance, -2, SEEK_CUR);
    }

    numRead = fread(ptrDATA, sizeof(uint8_t), sizeof(dataHeader), existance);
    if (numRead == sizeof(dataHeader))
    {
        printf("ALL DATA HEADER READED : %d from %d!\n", numRead, sizeof(dataHeader));
    }

    printHeader(ptrRIFF, ptrFMT, ptrDATA);

    bufSize = (ptrFMT->sample_rate / BUFFER_DIV_COEFF) * ptrFMT->block_align;
    printf("Buffer size = %d\n", bufSize);

    loop_cnt = ptrDATA->data_size / bufSize;
    printf("Loops = %d\n", loop_cnt);

    buffer = (uint8_t*)malloc(bufSize);

    gain_loop_cnt = (bufSize / (FMT.block_align / FMT.channels));
    unit_sample = (float*)buffer;

    numWrite = fwrite(ptrRIFF, sizeof(uint8_t), sizeof(riffHeader), created);
    numWrite = fwrite(ptrFMT, sizeof(uint8_t), (ptrFMT->length_of_fmt + 8), created);
    numWrite = fwrite(ptrDATA, sizeof(uint8_t), sizeof(dataHeader), created);

    for (i = 0; i < loop_cnt; i++)
    {
        numRead = fread(buffer, sizeof(uint8_t), bufSize, existance);

        for (int j = 0; j < gain_loop_cnt; j++)
        {
            unit_sample[j] *= multiplier;
        }

        numWrite = fwrite(buffer, sizeof(uint8_t), bufSize, created);
    }
  
}







void generateWavFile(char* generator, const char* outAddr)
{
    FILE* created;
    size_t numWrite;

    riffHeader RIFF;
    riffHeader* ptrRIFF = &RIFF;

    fmtHeader FMT;
    fmtHeader* ptrFMT = &FMT;

    dataHeader DATA;
    dataHeader* ptrDATA = &DATA;


    uint8_t* pch;
    uint32_t i;

    size_t totalSamples;
    size_t bufferSize;
    size_t loop_cnt;
    commonData mandat;

    void* buffer;

    char* arguments[] = { NULL, NULL, NULL, NULL, NULL, NULL, NULL };
    char* present_gen[ALL_GEN_TYPES_CNT] = {"delta", "step", "square", "whitenoise", "sine", "chirp", "sweep"};
  
    pch = strtok(generator, ",:");
    for (i = 0; pch != NULL; i++)
    { 
        arguments[i] = pch;             //filling aruments for nex processing
        printf("%s\n", arguments[i]);
        pch = strtok(NULL, ",:");
    }

    
    mandat.sampleRate = atoi(arguments[SAMPLE_RATE_ID]);
    mandat.duration_ms = atoi(arguments[DURATION_ID]);
    mandat.func = arguments[TYPE_GEN_ID];

    totalSamples = (mandat.sampleRate * mandat.duration_ms) / 1000;
    bufferSize = (ptrFMT->sample_rate / BUFFER_DIV_COEFF) * ptrFMT->block_align;
    loop_cnt = ptrDATA->data_size / bufferSize;

    buffer = (float*)malloc(bufferSize);

    fillHeader(ptrRIFF, ptrFMT, ptrDATA, &mandat);

    if ((created = fopen(outAddr, "w+b")) == NULL)      /*  Create new .wav file    */
    {
        printf("ERROR in creating new file!\n");
    }

    numWrite = fwrite(ptrRIFF, sizeof(uint8_t), sizeof(riffHeader), created);
    numWrite = fwrite(ptrFMT, sizeof(uint8_t), (size_t)(ptrFMT->length_of_fmt + DATA_4BYTES + FMT_BYTES), created);
    numWrite = fwrite(ptrDATA, sizeof(uint8_t), sizeof(dataHeader), created);

    for (i = 0; strcmp(mandat.func, present_gen[i]) != 0; i++)
    {
        
    }

    switch (i)
    {
        case DELTA:
        {

        }

    default:
        break;
    }

}










void fillHeader(riffHeader* ptrRIFF, fmtHeader* ptrFMT, dataHeader* ptrDATA, commonData* data)
{
    size_t numberOfSamples;
    size_t dataSize;

    numberOfSamples = (data->duration_ms * data->sampleRate) / MS_IN_SEC;
    dataSize = numberOfSamples * CHANNELS_NUM * BYTES_IN_CHANNEL;

    /*  RIFF    */
    ptrRIFF->riff[0] = 'r';
    ptrRIFF->riff[1] = 'i';
    ptrRIFF->riff[2] = 'f';
    ptrRIFF->riff[3] = 'f';

    ptrRIFF->overall_size = dataSize + DATA_BYTES + FMT_CHUNK_SIZE + WAVE_BYTES;

    ptrRIFF->wave[0] = 'w';
    ptrRIFF->wave[1] = 'a';
    ptrRIFF->wave[2] = 'v';
    ptrRIFF->wave[3] = 'e';

    /*  FMT */
    ptrFMT->fmt_chunk_marker[0] = 'f';
    ptrFMT->fmt_chunk_marker[1] = 'm';
    ptrFMT->fmt_chunk_marker[2] = 't';
    ptrFMT->fmt_chunk_marker[3] = 0x20;

    ptrFMT->length_of_fmt = FMT_CHUNK_SIZE - FMT_BYTES - DATA_4BYTES;
    ptrFMT->format_type = PCM;
    ptrFMT->channels = CHANNELS_NUM;
    ptrFMT->sample_rate = data->sampleRate;
    ptrFMT->byterate = data->sampleRate * CHANNELS_NUM * BYTES_IN_CHANNEL;
    ptrFMT->block_align = CHANNELS_NUM * BYTES_IN_CHANNEL;
    ptrFMT->bits_per_sample = BYTES_IN_CHANNEL * 8;////

    /*  DATA    */
    ptrDATA->data_chunk_header[0] = 'd';
    ptrDATA->data_chunk_header[1] = 'a';
    ptrDATA->data_chunk_header[2] = 't';
    ptrDATA->data_chunk_header[3] = 'a';

    ptrDATA->data_size = dataSize;
}













void printHeader(riffHeader * ptrRIFF, fmtHeader * ptrFMT, dataHeader * ptrDATA)
{
        printf("******** WAV HEADER PARSING! ********\n\n");

        printf("Chunk ID : %X %X %X %X\n",
            ptrRIFF->riff[0], ptrRIFF->riff[1], ptrRIFF->riff[2], ptrRIFF->riff[3]);
        printf("Overall size : %d\n", ptrRIFF->overall_size);
        printf("Format : %c%c%c%c\n\n", ptrRIFF->wave[0], ptrRIFF->wave[1], ptrRIFF->wave[2], ptrRIFF->wave[3]);

        printf("SubChunk_1 ID : %c%c%c%c\n",
            ptrFMT->fmt_chunk_marker[0], ptrFMT->fmt_chunk_marker[1], ptrFMT->fmt_chunk_marker[2], ptrFMT->fmt_chunk_marker[3]);
        printf("SubChunk 1 size : %d\n", ptrFMT->length_of_fmt);
        printf("Audio format : ( %d ) IEEE-754 \n", ptrFMT->format_type);
        printf("Channels number : %d\n", ptrFMT->channels);
        printf("Sample rate : %d\n", ptrFMT->sample_rate);
        printf("Byterate : %d\n", ptrFMT->byterate);
        printf("Block allign : %d\n", ptrFMT->block_align);
        printf("Bits per sample : %d\n", ptrFMT->bits_per_sample);
        printf("Axillary data : %d\n\n", ptrFMT->axillary_data);

        printf("SubChunk_2 ID : %c%c%c%c\n",
            ptrDATA->data_chunk_header[0], ptrDATA->data_chunk_header[1], ptrDATA->data_chunk_header[2], ptrDATA->data_chunk_header[3]);
        printf("Data size : %d\n\n", ptrDATA->data_size);

    

}