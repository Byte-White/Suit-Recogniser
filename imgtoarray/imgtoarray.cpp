#define STB_IMAGE_IMPLEMENTATION
#include"stb_image.h"
#include<stdio.h>
#include<sstream>
#include<fstream>
#include <iomanip>

int main (int argc, char *argv[]) 
{
	if(argc<3)
	{
		printf("Error: Not enough arguments!\nUsage:%s <imagefilename> <savetofilename>",argv[0]);		
		return 1;
	}
	
    int width, height, channels;
    unsigned char* image_data = stbi_load(argv[1], &width, &height, &channels, 1); // 1 indicates grayscale
	
    if (image_data == NULL) 
	{
		printf("Error: couldn't load image '%s'.\n",argv[1]);
		return 1;
	}

	std::stringstream ss;
	ss<<"float image["<<width*height<<"] = {";
	for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            float normalized_value = image_data[y * width + x] / 255.0f;
			printf("Pixel at (%d, %d): %.4f\n", x, y, normalized_value);
			
			ss<< std::fixed << std::setprecision(4) << normalized_value<<"f";
			if(x!=(width-1) || y!=(height-1))ss<<',';
        }
		ss<<"\n";
    }
	ss<<"};";
	//save to file
	std::ofstream out(argv[2]);
	if(!out.good())
	{
		printf("Error: couldn't save file '%s'.\n",argv[1]);
		return 1;
	}
	out<<ss.str();
	printf("Generated file with name '%s'",argv[2]);
	return 0;
}
