#include <string>
#include <iostream>
#include <fstream>
#include <ostream>
#include <sstream>
#include <vector>
#include "File.h"
#include "Pixel.h"
using namespace std;

const float f = 0.5f;

//FUNCTIONS
void CompleteTask(int task);

bool Verify(vector<Pixel> a, string name, int task, int color);

void Multiply(File& obj, File& obj2, string fileOut);

void Subtract(File& obj, File& obj2, string fileOut);

void Overlay(File& obj, File& obj2, string fileOut);

void MultAndSub(File& obj, File& obj2, File& obj3, string fileOut);

void Screen(File& obj, File& obj2, string fileout);

void ChannelManip(File& obj, int option, string fileout);

void Combine(File& obj, File& obj2, File& obj3, string fileout);

void Rotate(File& obj, string fileout);

void Cycle(File& obj, string fileout);

void EightRGB(File& obj, string color, string fileout);
File access;
int option = 0;
string CT = "No";
string RT = "Rotate";
int CTint = 0;
File layer1("input/layer1.tga", CT, CTint);
File layer2("input/layer2.tga", CT, CTint);

File layerBlue("input/layer_blue.tga", CT, CTint);
File layerRed("input/layer_red.tga", CT, CTint);
File layerGreen("input/layer_green.tga", CT, CTint);

File pattern1("input/pattern1.tga", CT, CTint);
File pattern2("input/pattern2.tga", CT, CTint);

File text("input/text.tga", CT, CTint);
File text2("input/text2.tga", RT, CTint);

File circle("input/circles.tga", CT, CTint);



//if (testing.TaskNumber == 8) {

//string eightRGB = "Run";
//File car("input/car.tga", eightRGB);
//}


File car("input/car.tga", CT, CTint);
string Eight = "Run";
int EightB = 1;
int EightG = 2;
int EightR = 3;
File car8B("input/car.tga");
File car8G("input/car.tga", CT);
File car8R("input/car.tga", CT, CTint, EightR);

File ExR("examples/EXAMPLE_part8_r.tga", Eight, EightR);
File ExG("examples/EXAMPLE_part8_g.tga", Eight, EightG);
File ExB("examples/EXAMPLE_part8_b.tga", Eight, EightB);
//File EightB("input/car.tga", blueC);
//File EightR();
//File EightG();

vector<Pixel> func_choice;
vector<Pixel> combo;
vector<Pixel> rotateFunction;
vector<Pixel> task8;
vector<Pixel> overlayP;
vector<Pixel> screenP;
vector<Pixel> subtractP;
vector<Pixel> channelP;


int main() {

    for (int i = 0; i < 262144; i++) {


        Pixel curr;
        curr.blue = i;
        curr.red = i;
        curr.green = i;


        func_choice.push_back(curr);
    }
    for (int i = 0; i < 262144; i++) {


        Pixel curr;
        curr.blue = i;
        curr.red = i;
        curr.green = i;


        task8.push_back(curr);

    }
    //TASKS 1-10
    CompleteTask(1);

    CompleteTask(2);

    CompleteTask(3);

    CompleteTask(4);

    CompleteTask(5);

    CompleteTask(6);

    CompleteTask(7);

    CompleteTask(8);

    CompleteTask(9);

    CompleteTask(10);

    cout << "PROGRAM FINISHED";

    return 0;

}

void CompleteTask(int task)
{


    access.TaskNumber = task;


    string blueC = "blue";
    string redC = "red";
    string greenC = "green";

    vector<Pixel> firstFile;
    vector <Pixel> secondFile;

    if (task == 1) {

        //MULTIPLY
        string fileOut = "output/part1.tga";
        string exFile = "examples/EXAMPLE_part1.tga";

        Multiply(layer1, pattern1, fileOut);

        if (Verify(func_choice, exFile, task, CTint) == true) {

            cout << "Task 1 Successful" << endl;

        }
        else {

            cout << "Task 1 Failed" << endl;

        }

    }

    else if (task == 2) {

        string fileOut = "output/part2.tga";
        string exFile = "examples/EXAMPLE_part2.tga";

        Subtract(layer2, car, fileOut);

        if (Verify(func_choice, exFile, task, CTint) == true) {

            cout << "Task 2 Successful" << endl;

        }
        else {

            cout << "Task 2 Failed" << endl;

        }

    }
    else if (task == 3) {



        string outFile = "output/part3.tga";
        string exFile = "examples/EXAMPLE_part3.tga";


        Multiply(layer1, pattern2, outFile);
        Screen(layer1, text, outFile);

        if (Verify(func_choice, exFile, task, CTint) == true) {

            cout << "Task 3 Successful" << endl;

        }
        else {

            cout << "Task 3 Failed" << endl;

        }


    }
    else if (task == 4) {



        string outFile = "output/part4.tga";
        string exFile = "examples/EXAMPLE_part4.tga";

        Multiply(layer2, circle, outFile);
        option = 1;
        Subtract(pattern2, circle, outFile);


        if (Verify(func_choice, exFile, task, CTint) == true) {

            cout << "Task 4 Successful" << endl;

        }
        else {

            cout << "Task 4 Failed" << endl;

        }


    }
    else if (task == 5) {

        string outFile = "output/part5.tga";
        string exFile = "examples/EXAMPLE_part5.tga";

        Overlay(layer1, pattern1, outFile);

        if (Verify(func_choice, exFile, task, CTint) == true) {

            cout << "Task 5 Successful" << endl;

        }
        else {

            cout << "Task 5 Failed" << endl;

        }


    }

    else if (task == 6) { //Add 200 Green to car.tga

        string outFile = "output/part6.tga";
        string exFile = "examples/EXAMPLE_part6.tga";

        ChannelManip(car, 1, outFile);

        if (Verify(func_choice, exFile, task, CTint) == true) {

            cout << "Task 6 Successful" << endl;

        }
        else {

            cout << "Task 6 Failed" << endl;

        }

    }
    else if (task == 7) {

        string outFile = "output/part7.tga";
        string exFile = "examples/EXAMPLE_part7.tga";

        ChannelManip(car, 2, outFile);

        if (Verify(func_choice, exFile, task, CTint) == true) {

            cout << "Task 7 Successful" << endl;

        }
        else {

            cout << "Task 7 Failed" << endl;

        }

    }
    else if (task == 8) {

        string r = "red";
        string b = "blue";
        string g = "green";
        string rotate = "NOrotate";
        string outFileB = "output/part8_b.tga";
        string outFileG = "output/part8_g.tga";
        string outFileR = "output/part8_r.tga";
        string exFileB = "examples/EXAMPLE_part8_b";
        EightRGB(car8B, b, outFileB);

        if (Verify(task8, exFileB, task, EightB) == true) {
            cout << "Task 8b Successful" << endl;
        }
        else {
            cout << "Task 8b Failed" << endl;
        }
        string exFileG = "examples/EXAMPLE_part8_g";

        EightRGB(car8G, g, outFileG);

        if (Verify(task8, exFileG, task, EightG) == true) {
            cout << "Task 8G Successful" << endl;
        }
        else {
            cout << "Task 8G Failed" << endl;
        }
        string exFileR = "examples/EXAMPLE_part8_r";
        EightRGB(car8R, r, outFileR);
        if (Verify(task8, exFileR, task, EightR) == true) {
            cout << "Task 8R Successful" << endl;
        }
        else {
            cout << "Task 8R Failed" << endl;
        }



        /*File TaskEightB("input/car.tga", b, rotate);
        File TaskEightG("input/car.tga", g, rotate);
        File TaskEightR("input/car.tga", r, rotate);*/

        /*File TaskEightB("input/car.tga", b);
        File TaskEightG("input/car.tga", g);
        File TaskEightR("input/car.tga", r);*/






        /*if (Verify(multiplicationP, exFileB) == true) {
        cout << "Task 8b Successful" << endl;
        }
        else {
        cout << "Task 8b Failed" << endl;
        }



        if (Verify(multiplicationP, exFileG) == true) {
        cout << "Task 2 Successful" << endl;
        }
        else {
        cout << "Task 2 Failed" << endl;
        }




        if (Verify(multiplicationP, exFileR) == true) {
        cout << "Task 2 Successful" << endl;
        }
        else {
        cout << "Task 2 Failed" << endl;
        }*/




    }
    else if (task == 9) {

        string outFile = "output/part9.tga";
        string exFile = "examples/EXAMPLE_part9.tga";

        Combine(layerBlue, layerGreen, layerRed, outFile);

        if (Verify(combo, exFile, task, CTint) == true) {
            cout << "Task 9 Successful" << endl;
        }
        else {
            cout << "Task 9 Failed" << endl;
        }

    }
    else if (task == 10) {

        string rotate = "rotate";
        string b = "x";
        //File Task10Flip("input/text2.tga", b, rotate);
        string outFile = "output/part10.tga";
        string exFile = "examples/EXAMPLE_part10.tga";
        Rotate(text2, outFile);

        if (Verify(rotateFunction, exFile, task, CTint) == true) {
            cout << "Task 10 Successful" << endl;
        }
        else {
            cout << "Task 10 Failed" << endl;
        }


    }
}

void Multiply(File& first, File& second, string outFile)
{



    Header obj;
    float resultBlue;
    float resultGreen;
    float resultRed;


    vector<Pixel> firstFile;
    vector <Pixel> secondFile;

    firstFile = first.GetPixels();

    secondFile = second.GetPixels();

    func_choice.resize(firstFile.size());

    int num = 0;
    for (int i = 0; i < firstFile.size(); i++) {
        Pixel curr;


        float blueP;
        blueP = (float)firstFile.at(i).blue;
        blueP /= 255;
        float blue2;
        blue2 = (float)secondFile.at(i).blue;
        blue2 /= 255;
        resultBlue = (blueP * blue2 * 255) + f;

        curr.blue = (unsigned int)resultBlue;



        float greenP;
        greenP = (float)firstFile.at(i).green;
        greenP /= 255;
        float green2;
        green2 = (float)secondFile.at(i).green;
        green2 /= 255;
        resultGreen = (greenP * green2 * 255) + f;

        curr.green = (unsigned char)resultGreen;



        float redP;
        redP = (float)firstFile.at(i).red;
        redP /= 255;
        float red2;
        red2 = (float)secondFile.at(i).red;
        red2 /= 255;
        resultRed = (redP * red2 * 255) + f;

        curr.red = (unsigned char)resultRed;


        func_choice.at(i) = curr;

    }


    //Subtract(first, second, outFile);
    first.Write(outFile, func_choice, obj);

}

void Subtract(File& first, File& second, string outFile)
{

    Header obj;
    float resultBlue;
    float resultGreen;
    float resultRed;


    vector<Pixel> firstFile;
    vector<Pixel> secondFile;


    firstFile = first.GetPixels();
    secondFile = second.GetPixels();

    if (option == 1) {

        secondFile = func_choice;

    }


    // SUBTRACT METHOD
    for (int i = 0; i < firstFile.size(); i++) {

        float blue1;
        blue1 = (float)firstFile.at(i).blue;
        float blue2;
        blue2 = (float)secondFile.at(i).blue;
        resultBlue = blue2 - blue1;

        float green1;
        green1 = (float)firstFile.at(i).green;
        float green2;
        green2 = (float)secondFile.at(i).green;
        resultGreen = green2 - green1;

        float red1;
        red1 = (float)firstFile.at(i).red;
        float red2;
        red2 = (float)secondFile.at(i).red;
        resultRed = red2 - red1;


        if (resultBlue > 255) {
            resultBlue = 255;
        }
        if (resultBlue < 0) {
            resultBlue = 0;
        }
        if (resultGreen > 255) {
            resultGreen = 255;
        }
        if (resultGreen < 0) {
            resultGreen = 0;
        }
        if (resultRed > 255) {
            resultRed = 255;
        }
        if (resultRed < 0) {
            resultRed = 0;
        }

        Pixel curr;

        curr.blue = (unsigned char)resultBlue;
        curr.green = (unsigned char)resultGreen;
        curr.red = (unsigned char)resultRed;

        func_choice.at(i) = curr;

    }
    first.Write(outFile, func_choice, obj);


}

void Overlay(File& first, File& second, string fileOut)
{

    Header obj;
    float resultBlue;
    float resultGreen;
    float resultRed;


    vector<Pixel> firstFile;
    vector<Pixel> secondFile;


    firstFile = first.GetPixels();
    secondFile = second.GetPixels();

    /*for (int i = 0; i < firstFile.size(); i++) {


        Pixel curr;
        curr.blue = i;
        curr.red = i;
        curr.green = i;


        overlayP.push_back(curr);

    }*/

    func_choice.resize(firstFile.size());


    for (int i = 0; i < (int)firstFile.size(); i++) {
        float resultBlue;
        float resultGreen;
        float resultRed;

        float blue1;
        blue1 = (float)firstFile.at(i).blue / 255;
        float blue2;
        blue2 = (float)secondFile.at(i).blue / 255;

        float green1;
        green1 = (float)firstFile.at(i).green / 255;
        float green2;
        green2 = (float)secondFile.at(i).green / 255;

        float red1;
        red1 = (float)firstFile.at(i).red / 255;
        float red2;
        red2 = (float)secondFile.at(i).red / 255;


        if (blue2 <= 0.5) {
            resultBlue = (blue1 * blue2 * 255 * 2) + f;
        }
        else {
            resultBlue = f + ((1 - 2 * ((1 - blue1) * (1 - blue2))) * 255);

            if ((resultBlue) > 255) {
                resultBlue = 255;
            }
            else if ((resultBlue) < 0) {
                resultBlue = 0;
            }
        }
        if (green2 <= 0.5) {

            resultGreen = (green1 * green2 * 255 * 2) + f;

        }
        else {
            resultGreen = f + ((1 - 2 * ((1 - green1) * (1 - green2))) * 255);

            if (green2 - green1 > 255) {
                resultGreen = 255;
            }
            else if (((resultGreen) < 0)) {
                resultGreen = 0;
            }
        }
        if (red2 <= 0.5) {
            resultRed = ((red1) * (red2) * (255) * (2)) + f;
        }
        else {
            resultRed = f + ((1 - 2 * ((1 - red1) * (1 - red2))) * 255);

            if ((resultRed) > 255) {
                resultRed = 255;
            }
            else if ((resultRed) < 0) {
                resultRed = 0;
            }

        }

        Pixel curr;
        curr.blue = (unsigned char)resultBlue;
        curr.green = (unsigned char)resultGreen;
        curr.red = (unsigned char)resultRed;
        func_choice.at(i) = curr;

    }
    layer1.Write(fileOut, func_choice, obj);
}

void MultAndSub(File& first, File& second, File& third, string fileOut)
{

    //NOT USED ANYMORE


}

void Screen(File& first, File& second, string outFile)
{
    Header obj;
    float resultBlue;
    float resultGreen;
    float resultRed;


    vector<Pixel> firstFile;
    vector <Pixel> secondFile;

    firstFile = first.GetPixels();

    secondFile = second.GetPixels();

    firstFile = func_choice;

    func_choice.resize(firstFile.size());

    for (int i = 0; i < (int)firstFile.size(); i++) {
        float blue1;
        blue1 = (float)firstFile.at(i).blue / 255;
        float blue2;
        blue2 = (float)secondFile.at(i).blue / 255;
        resultBlue = f + ((1 - (1 - blue1) * (1 - blue2)) * 255);

        float green1;
        green1 = (float)firstFile.at(i).green / 255;
        float green2;
        green2 = (float)secondFile.at(i).green / 255;
        resultGreen = f + ((1 - (1 - green1) * (1 - green2)) * 255);

        float red1;
        red1 = (float)firstFile.at(i).red / 255;
        float red2;
        red2 = (float)secondFile.at(i).red / 255;
        resultRed = f + ((1 - (1 - red1) * (1 - red2)) * 255);

        Pixel curr;

        curr.blue = (unsigned char)resultBlue;
        curr.green = (unsigned char)resultGreen;
        curr.red = (unsigned char)resultRed;

        func_choice.at(i) = (curr);

    }


    first.Write(outFile, func_choice, obj);
}

void ChannelManip(File& first, int selection, string fileout)
{

    Header obj;
    float resultBlue;
    float resultGreen;
    float resultRed;

    float AddGreen = 200.0f;

    vector<Pixel> firstFile;

    //Add 200 to Green


    firstFile = first.GetPixels();

    func_choice.resize(firstFile.size());


    for (int i = 0; i < firstFile.size(); i++) {


        if (selection == 1) {

            float green = (float)firstFile.at(i).green;
            float red = (float)firstFile.at(i).red;
            float blue = (float)firstFile.at(i).blue;

            float resultBlue = blue;
            float resultGreen = green + AddGreen; //+ AddGreen
            float resultRed = red;

            if (resultGreen > 255) {

                resultGreen = 255;

            }

            Pixel currPixel;

            currPixel.blue = (unsigned char)resultBlue;
            currPixel.green = (unsigned char)resultGreen;
            currPixel.red = (unsigned char)resultRed;

            func_choice.at(i) = (currPixel);

        }
        else {

            float green = (float)firstFile.at(i).green;

            float red = ((float)firstFile.at(i).red / 255.0f) * (4.0f) * (255.0f);
            float blue = (float)firstFile.at(i).blue * 0.0f;

            float resultBlue = blue;
            float resultGreen = green;
            float resultRed = red;

            if (resultRed > 255) {
                resultRed = 255;
            }
            Pixel currPixel;
            currPixel.blue = (unsigned char)resultBlue;
            currPixel.green = (unsigned char)resultGreen;
            currPixel.red = (unsigned char)resultRed;
            func_choice.at(i) = (currPixel);


        }

    }
    first.Write(fileout, func_choice, obj);

}

void Combine(File& first, File& second, File& third, string fileout)
{

    Header obj;
    float resultBlue;
    float resultGreen;
    float resultRed;


    vector<Pixel> firstFile;
    vector <Pixel> secondFile;
    vector<Pixel> thirdFile;

    firstFile = first.GetPixels();
    secondFile = second.GetPixels();
    thirdFile = third.GetPixels();

    //firstFile = multiplicationP;
    for (int i = 0; i < firstFile.size(); i++) {


        Pixel curr;
        curr.blue = i;
        curr.red = i;
        curr.green = i;


        combo.push_back(curr);

    }
    int num = 0;
    for (int i = 0; i < firstFile.size(); i++) {
        Pixel curr;

        float blue;
        blue = (float)firstFile.at(i).blue;
        float green;
        green = (float)secondFile.at(i).green;
        float red;
        red = (float)thirdFile.at(i).red;


        float resultBlue;
        resultBlue = blue;
        float resultGreen;
        resultGreen = green;
        float resultRed;
        resultRed = red;


        curr.blue = (unsigned char)resultBlue;
        curr.green = (unsigned char)resultGreen;
        curr.red = (unsigned char)resultRed;
        //multiplicationP.at(i) = (curr);
        combo.at(i) = (curr);
        //combo.push_back(curr);

    }

    first.Write(fileout, combo, obj);

}

void Rotate(File& first, string fileout)
{

    Header obj;
    float resultBlue;
    float resultGreen;
    float resultRed;


    vector<Pixel> firstFile;


    firstFile = first.GetPixels();

    for (int i = 0; i < firstFile.size(); i++) {


        Pixel curr;
        curr.blue = i;
        curr.red = i;
        curr.green = i;


        rotateFunction.push_back(curr);

    }

    int x = 0;
    for (int i = 0; i < firstFile.size(); i++) {
        Pixel curr;
        int temp = firstFile.size() - 1 - i;
        //int temp = firstFile.size() - i;

        float blue;
        blue = (float)firstFile.at(temp).blue;
        float resultBlue = blue;

        float green;
        green = (float)firstFile.at(temp).green;
        float resultGreen = green;

        float red;
        red = (float)firstFile.at(temp).red;
        float resultRed = red;



        curr.blue = (unsigned char)resultBlue;
        curr.green = (unsigned char)resultGreen;
        curr.red = (unsigned char)resultRed;

        rotateFunction.at(i) = curr;

        /*if (i == 1) {

        rotateFunction.at(x) = (curr);

        }
        else if (i >= 2 && i < firstFile.size()) {

        rotateFunction.at(x) = (curr);

        }*/
    }

    first.Write(fileout, rotateFunction, obj);


}

void EightRGB(File& first, string color, string fileout)
{


    Header obj;
    //float resultBlue;
    //float resultGreen;
    //float resultRed;


    vector<Pixel> firstFile;
    //vector <Pixel> secondFile;

    firstFile = first.GetPixels();


    
    //secondFile = second.GetPixels();
   
    //firstFile = multiplicationP;


    Pixel curr;


    task8.resize(firstFile.size());

    for (int i = 0; i < firstFile.size(); i++) {

        task8.at(i) = firstFile.at(i);

    }

    ////Subtract(first, second, outFile);
    //first.Write(fileout, multiplicationP, obj);


    if (color == "blue") {

        string name = "output/part8_b.tga";
        string exFileB = "examples/EXAMPLE_part8_b";
        first.Write(name, firstFile, obj);





    }
    else if (color == "green") {

        string name = "output/part8_g.tga";
        first.Write(name, firstFile, obj);
        string exFileG = "examples/EXAMPLE_part8_g";



        /*if (Verify8ABC(pixels, exFileG) == true) {
        // cout << "Task 8g Successful" << endl;
        // }
        // else {
        // cout << "Task 8g Failed" << endl;
        // }*/

    }



    else if (color == "red") {
        string name = "output/part8_r.tga";
        first.Write(name, firstFile, obj);
        string exFileR = "examples/EXAMPLE_part8_r";



        /*if (Verify8ABC(pixels, exFileR) == true) {
        cout << "Task 8r Successful" << endl;
        }
        else {
        cout << "Task 8r Failed" << endl;
        }*/


    }
    else {

        // //string name = "output/part10.tga";
        // //Write(name, pixels, obj);

    }



}

bool Verify(vector<Pixel> a, string name, int task, int color)
{
    access.TaskNum(access);
    if (task == 8) {

        //File example1(name, CT, color, access);

        if (color == 1) {

            vector <Pixel> example;
            example = ExB.GetPixels();

            for (int i = 0; i < (int)a.size(); i++) {

                if (a.at(i) == example.at(i)) {

                    continue;

                }
                else {
                    return false;
                }
            }
            return true;


        }
        else if (color == 2) {
            vector <Pixel> example;
            example = ExG.GetPixels();

            for (int i = 0; i < (int)a.size(); i++) {

                if (a.at(i) == example.at(i)) {

                    continue;

                }
                else {
                    return false;
                }
            }
            return true;

        }
        else {

            vector <Pixel> example;
            example = ExR.GetPixels();

            for (int i = 0; i < (int)a.size(); i++) {

                if (a.at(i) == example.at(i)) {

                    continue;

                }
                else {
                    return false;
                }
            }
            return true;

        }





    }
    else {

        File example1(name, CT, task);
        vector <Pixel> example;
        example = example1.GetPixels();

        for (int i = 0; i < (int)a.size(); i++) {

            if (a.at(i) == example.at(i)) {

                continue;

            }
            else {
                return false;
            }
        }

        return true;

    }


}

