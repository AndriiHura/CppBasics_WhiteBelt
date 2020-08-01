// 2_ClassFunction.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Image {
    double quality;
    double freshness;
    double rating;
};

struct Params {
    double a;
    double b;
    double c;
};

class FunctionPart {
public:
    FunctionPart(char new_operation, double new_value) {
        operation = new_operation;
        value = new_value;
    }

    double Apply(double source_value) const {
        if (operation == '+'){
            return source_value + value;
        }
        else {
            return source_value - value;
        }
    }

    void Invert() {
        if (operation == '+') {
            operation = '-';
        }
        else{
            operation = '+';
        }
    }

private:
    char operation;
    double value;
};

class Function {
public:
    void AddPart(char operation, double value) {
        parts.push_back(FunctionPart(operation, value));
    }

    double Apply(double value) const {
        for (const FunctionPart&  part : parts) {
            value = part.Apply(value);
        }
        return value;
    }

    void Invert() {
        for (FunctionPart& part : parts) {
            part.Invert();
        }
        reverse(begin(parts), end(parts));
    }
private:
    vector<FunctionPart> parts;
};

Function MakeWeightFunction(const Params& params, const Image& image) {
    Function function;
    function.AddPart('-.', image.freshness * params.a + params.b);
    function.AddPart('+', image.rating * params.c);
    return function;
}

double ComputeImageWeight(const Params& params, const Image& image) {
    Function function = MakeWeightFunction(params, image);
    return function.Apply(image.quality);
}

double ComputeQualityByWeight(const Params& params, const Image& image, double weight) {
    Function function = MakeWeightFunction(params, image);
    function.Invert();
    return function.Apply(weight);
}
//
//int main()
//{
//    Image image = { 10, 2, 6 };
//    Params params = { 4, 2, 6 };
//    //10-2*4-2+6*6 == 36
//
//    cout << ComputeImageWeight(params, image) << endl;
//    cout << ComputeQualityByWeight(params, image, 46) << endl;
//}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
