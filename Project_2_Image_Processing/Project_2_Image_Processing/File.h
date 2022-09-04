#include "Pixel.h"
#include <vector>
#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>


using namespace std;

struct Header
{
    char idLength;
    char colorMapType;
    char dataTypeCode;
    short colorMapOrigin;
    short colorMapLength;
    char colorMapDepth;
    short xOrigin;
    short yOrigin;
    short width;
    short height;
    char bitsPerPixel;
    char imageDescriptor;


};


class File {



public:

    int TaskNumber;
    bool rotate;
    //string channel = "temp";


    Header fileHeader;
    vector<Pixel> Pixels;

    File();
    //File(string filename, string channel, int option, File& obj); //Basic multiplicationP that calls Read and stores data

    //void Read8(string filename, string channel, string rotate); //Reads file and seperates color channels

    vector<Pixel> GetPixels();

    File(string filename, string channel, int option);

    File(string filename); //Blue
    File(string filename, string channel);  //Red
    File(string filename, string channel, int option, int option2); //Green

    //File(string outName, vector<Pixel> pixels, Header& obj);
    //void Read(ifstream& myFile, string channel, int option, int option2);
    void Write(string outName, vector<Pixel> pixels, Header& obj);
    //bool Verify8ABC(vector<Pixel> a, string name);

    void TaskNum(File& obj);

    int numPixels;




};

File::File()
{

    //TaskNumber = 0;
    //rotate = false;
}
File::File(string filename, string channel, int option) //BASIC
{

    Header obj;
    vector<Pixel> pixels;

    ifstream myFile(filename, ios_base::binary);


    myFile.read(&obj.idLength, sizeof(obj.idLength));
    myFile.read(&obj.colorMapType, sizeof(obj.colorMapType));
    myFile.read(&obj.dataTypeCode, sizeof(obj.dataTypeCode));
    myFile.read((char*)&obj.colorMapOrigin, sizeof(obj.colorMapOrigin));
    myFile.read((char*)&obj.colorMapLength, sizeof(obj.colorMapLength));
    myFile.read(&obj.colorMapDepth, sizeof(obj.colorMapDepth));
    myFile.read((char*)&obj.xOrigin, sizeof(obj.xOrigin));
    myFile.read((char*)&obj.yOrigin, sizeof(obj.yOrigin));
    myFile.read((char*)&obj.width, sizeof(obj.width));
    myFile.read((char*)&obj.height, sizeof(obj.height));
    myFile.read(&obj.bitsPerPixel, sizeof(obj.bitsPerPixel));
    myFile.read(&obj.imageDescriptor, sizeof(obj.imageDescriptor));

    numPixels = obj.height * obj.width;

    for (int i = 0; i < numPixels; i++) {


        Pixel curr;
        myFile.read((char*)&curr.blue, sizeof(curr.blue));
        myFile.read((char*)&curr.green, sizeof(curr.green));
        myFile.read((char*)&curr.red, sizeof(curr.red));
        pixels.push_back(curr);



    }


    fileHeader = obj;
    Pixels = pixels;





    


}

File::File(string filename)
{

    Header obj;
    vector<Pixel> pixels;

    ifstream myFile(filename, ios_base::binary);
    //ifstream myFile(filename, ios_base::binary);

    myFile.read(&obj.idLength, sizeof(obj.idLength));
    myFile.read(&obj.colorMapType, sizeof(obj.colorMapType));
    myFile.read(&obj.dataTypeCode, sizeof(obj.dataTypeCode));
    myFile.read((char*)&obj.colorMapOrigin, sizeof(obj.colorMapOrigin));
    myFile.read((char*)&obj.colorMapLength, sizeof(obj.colorMapLength));
    myFile.read(&obj.colorMapDepth, sizeof(obj.colorMapDepth));
    myFile.read((char*)&obj.xOrigin, sizeof(obj.xOrigin));
    myFile.read((char*)&obj.yOrigin, sizeof(obj.yOrigin));
    myFile.read((char*)&obj.width, sizeof(obj.width));
    myFile.read((char*)&obj.height, sizeof(obj.height));
    myFile.read(&obj.bitsPerPixel, sizeof(obj.bitsPerPixel));
    myFile.read(&obj.imageDescriptor, sizeof(obj.imageDescriptor));

    numPixels = obj.height * obj.width;



    for (int i = 0; i < numPixels; i++) {
        Pixel curr;
        unsigned char colorData;
        unsigned char ignore;

      

            myFile.read((char*)&colorData, sizeof(colorData));
            myFile.read((char*)&ignore, sizeof(ignore));
            myFile.read((char*)&ignore, sizeof(ignore));

            curr.blue = colorData;
            curr.green = colorData;
            curr.red = colorData;
            pixels.push_back(curr);
        }
       /* else if (option == 2) {

            myFile.read((char*)&ignore, sizeof(ignore));
            myFile.read((char*)&colorData, sizeof(colorData));
            myFile.read((char*)&ignore, sizeof(ignore));

            curr.blue = colorData;
            curr.green = colorData;
            curr.red = colorData;

        } */
        

        
        fileHeader = obj;
        Pixels = pixels;
        //testing.at(i) = (curr);


}



File::File(string filename, string channel)
{

    Header obj;
    vector<Pixel> pixels;

    ifstream myFile(filename, ios_base::binary);
    //ifstream myFile(filename, ios_base::binary);

    myFile.read(&obj.idLength, sizeof(obj.idLength));
    myFile.read(&obj.colorMapType, sizeof(obj.colorMapType));
    myFile.read(&obj.dataTypeCode, sizeof(obj.dataTypeCode));
    myFile.read((char*)&obj.colorMapOrigin, sizeof(obj.colorMapOrigin));
    myFile.read((char*)&obj.colorMapLength, sizeof(obj.colorMapLength));
    myFile.read(&obj.colorMapDepth, sizeof(obj.colorMapDepth));
    myFile.read((char*)&obj.xOrigin, sizeof(obj.xOrigin));
    myFile.read((char*)&obj.yOrigin, sizeof(obj.yOrigin));
    myFile.read((char*)&obj.width, sizeof(obj.width));
    myFile.read((char*)&obj.height, sizeof(obj.height));
    myFile.read(&obj.bitsPerPixel, sizeof(obj.bitsPerPixel));
    myFile.read(&obj.imageDescriptor, sizeof(obj.imageDescriptor));

    numPixels = obj.height * obj.width;



    for (int i = 0; i < numPixels; i++) {
        Pixel curr;
        unsigned char colorData;
        unsigned char ignore;


        myFile.read((char*)&ignore, sizeof(ignore));
        myFile.read((char*)&colorData, sizeof(colorData));
        myFile.read((char*)&ignore, sizeof(ignore));

        curr.blue = colorData;
        curr.green = colorData;
        curr.red = colorData;

        pixels.push_back(curr);
    }


    fileHeader = obj;
    Pixels = pixels;




}

inline File::File(string filename, string channel, int option, int option2)
{

    Header obj;
    vector<Pixel> pixels;

    ifstream myFile(filename, ios_base::binary);


    myFile.read(&obj.idLength, sizeof(obj.idLength));
    myFile.read(&obj.colorMapType, sizeof(obj.colorMapType));
    myFile.read(&obj.dataTypeCode, sizeof(obj.dataTypeCode));
    myFile.read((char*)&obj.colorMapOrigin, sizeof(obj.colorMapOrigin));
    myFile.read((char*)&obj.colorMapLength, sizeof(obj.colorMapLength));
    myFile.read(&obj.colorMapDepth, sizeof(obj.colorMapDepth));
    myFile.read((char*)&obj.xOrigin, sizeof(obj.xOrigin));
    myFile.read((char*)&obj.yOrigin, sizeof(obj.yOrigin));
    myFile.read((char*)&obj.width, sizeof(obj.width));
    myFile.read((char*)&obj.height, sizeof(obj.height));
    myFile.read(&obj.bitsPerPixel, sizeof(obj.bitsPerPixel));
    myFile.read(&obj.imageDescriptor, sizeof(obj.imageDescriptor));

    numPixels = obj.height * obj.width;

    for (int i = 0; i < numPixels; i++) {

        Pixel curr;
        unsigned char colorData;
        unsigned char ignore;
      

        myFile.read((char*)&ignore, sizeof(ignore));
        myFile.read((char*)&ignore, sizeof(ignore));
        myFile.read((char*)&colorData, sizeof(colorData));

        curr.blue = colorData;
        curr.green = colorData;
        curr.red = colorData;

        pixels.push_back(curr);


    }


    fileHeader = obj;
    Pixels = pixels;



}

//File::File(string outName, vector<Pixel> pixels, Header& obj)
//{
//




void File::Write(string fileName, vector<Pixel> pixels, Header& obj) {

    //Header obj;
    obj = this->fileHeader;

    ofstream outFile(fileName, ios_base::binary);
    outFile.write(&obj.idLength, sizeof(obj.idLength));
    outFile.write(&obj.colorMapType, sizeof(obj.colorMapType));
    outFile.write(&obj.dataTypeCode, sizeof(obj.dataTypeCode));
    outFile.write((char*)&obj.colorMapOrigin, sizeof(obj.colorMapOrigin));
    outFile.write((char*)&obj.colorMapLength, sizeof(obj.colorMapLength));
    outFile.write(&obj.colorMapDepth, sizeof(obj.colorMapDepth));
    outFile.write((char*)&obj.xOrigin, sizeof(obj.xOrigin));
    outFile.write((char*)&obj.yOrigin, sizeof(obj.yOrigin));
    outFile.write((char*)&obj.width, sizeof(obj.width));
    outFile.write((char*)&obj.height, sizeof(obj.height));
    outFile.write(&obj.bitsPerPixel, sizeof(obj.bitsPerPixel));
    outFile.write(&obj.imageDescriptor, sizeof(obj.imageDescriptor));


    for (int i = 0; i < (int)pixels.size(); i++) {

        int loop = 1;


        while (loop == 1) { //So it
            Pixel currPixel = pixels.at(i);
            outFile.write((char*)&currPixel.blue, sizeof(currPixel.blue));
            outFile.write((char*)&currPixel.green, sizeof(currPixel.green));
            outFile.write((char*)&currPixel.red, sizeof(currPixel.red));
            loop = 2;
        }

    }




}

void File::TaskNum(File& obj)
{
    obj.TaskNumber = this->TaskNumber;


}

//bool File::Verify8ABC(vector<Pixel> a, string name) {}

// //string name1 = name;
// string c = "temp";
// File example1(name, c); //When this is called it changes the number of pixels
// vector <Pixel> example;
// example = example1.GetPixels();
//
// for (int i = 0; i < (int)a.size(); i++) {
// if (a.at(i) == example.at(i)) {
//
// }
// else {
// return false;
// }
// }
//
// return true;
//}

vector<Pixel> File::GetPixels() {
    return Pixels;
}







