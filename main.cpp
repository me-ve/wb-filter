#include <iostream>
#include <fstream>

const double R_RATIO = 0.299;
const double G_RATIO = 0.587;
const double B_RATIO = 0.114;
const int MAX_COLOR = 255;

int rgbtowb(int r, int g, int b){
    return r*R_RATIO + g*G_RATIO + b*B_RATIO;
}

int main(int argc, char* argv[]){
    if(argc!=3){
        return 1;
    }else{
        std::ifstream input(argv[1]);
        std::ofstream output(argv[2]);
        if(input && output){
            std::string mode;
            int width;
            int height;
            input >> mode >> width >> height;
            output << "P2" << "\n";
            output << width << " " << height << "\n";
            output << MAX_COLOR << "\n";
            for(int i=0; i<height; i++){
                for(int j=0; j<width; j++){
                    int r, g, b;
                    input >> r >> g >> b;
                    output << rgbtowb(r, g, b);
                    if (j<width-1) output << " ";
                }
                output << "\n";
            }
            input.close();
            output.close();
            return 0;
        }
    }
}
