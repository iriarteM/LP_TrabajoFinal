#include <iostream>
#include "Matrices.hpp"
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
    int kernel;
    int tam;
    int N;
    char pColor;
    Mat fotito = imread("gato.jpg");
    Mat mImage;
    Mat mImageG;
    cout << "Grupo 3 | Lenguajes de programacion" << endl
        << "1. Sobel" << endl
        << "2. Gaussian Blur" << endl
        << "3. Blox Blur" << endl
        << "Seleccione la matriz a aplicar: ";
    cin >> kernel;
    switch (kernel) {
    case 1:
        cout << "1. Sobel 3x3 " << endl
            << "2. Sobel 5x5" << endl;
        cout << "Indique la matriz: ";
        cin >> tam;
        cout << "Imagen a color o blanco y negro (C/B): ";
        cin >> pColor;
        switch (tam) {
        case 1:
            if (fotito.empty()) {
                cout << "No se pudo cargar la imagen." << endl;
                return -1;
            }
            switch (pColor) {
            case 'C':
                mImage = Sobel3x3FilterColor(fotito);
                calcularHistogramaColor(fotito, "imgO.csv");
                calcularHistogramaColor(mImage, "imgC.csv");
                break;
            case 'c':
                mImage = Sobel3x3FilterColor(fotito);
                calcularHistogramaColor(fotito, "imgO.csv");
                calcularHistogramaColor(mImage, "imgC.csv");
                break;
            case 'B':
                mImage = Sobel3x3FilterGray(fotito);
                calcularHistogramaColor(fotito, "imgO.csv");
                calcularHistogramaGray(mImage, "imgB.csv");
                break;
            case 'b':
                mImage = Sobel3x3FilterGray(fotito);
                calcularHistogramaColor(fotito, "imgO.csv");
                calcularHistogramaGray(mImage, "imgB.csv");
                break;
            default:
                break;
            }
            printImage(fotito, mImage);
            break;
        case 2:
            if (fotito.empty()) {
                cout << "No se pudo cargar la imagen." << endl;
                return -1;
            }
            switch (pColor) {
            case 'C':
                mImage = Sobel5x5FilterColor(fotito);
                calcularHistogramaColor(fotito, "imgO.csv");
                calcularHistogramaColor(mImage, "imgC.csv");
                break;
            case 'c':
                mImage = Sobel5x5FilterColor(fotito);
                calcularHistogramaColor(fotito, "imgO.csv");
                calcularHistogramaColor(mImage, "imgC.csv");
                break;
            case 'B':
                mImage = Sobel5x5FilterGray(fotito);
                calcularHistogramaColor(fotito, "imgO.csv");
                calcularHistogramaGray(mImage, "imgB.csv");
                break;
            case 'b':
                mImage = Sobel5x5FilterGray(fotito);
                calcularHistogramaColor(fotito, "imgO.csv");
                calcularHistogramaGray(mImage, "imgB.csv");
                break;
            default:
                break;
            }
            printImage(fotito, mImage);
            break;
        default:
            cout << "input invalido";
            break;
        }
        break;
    case 2:
        cout << "1. Gaussian Blur 3x3 " << endl
             << "2. Gaussian Blur 5x5" << endl
             << "3. Gaussian Blur NxN" << endl;
        cout << "Indique la matriz: ";
        cin >> tam;
        cout << "Imagen a color o blanco y negro (C/B): ";
        cin >> pColor;
        switch (tam) {
        case 1:
            if (fotito.empty()) {
                cout << "No se pudo cargar la imagen." << endl;
                return -1;
            }
            switch (pColor) {
            case 'C':
                mImage = Gaussian3x3FilterColor(fotito);
                calcularHistogramaColor(fotito, "imgO.csv");
                calcularHistogramaColor(mImage, "imgC.csv");
                break;
            case 'c':
                mImage = Gaussian3x3FilterColor(fotito);
                calcularHistogramaColor(fotito, "imgO.csv");
                calcularHistogramaColor(mImage, "imgC.csv");
                break;
            case 'B':
                mImageG = grayScale(fotito);
                mImage = Gaussian3x3FilterGray(mImageG);
                calcularHistogramaColor(fotito, "imgO.csv");
                calcularHistogramaGray(mImage, "imgB.csv");
                break;
            case 'b':
                mImageG = grayScale(fotito);
                mImage = Gaussian3x3FilterGray(mImageG);
                calcularHistogramaColor(fotito, "imgO.csv");
                calcularHistogramaGray(mImage, "imgB.csv");
                break;
            default:
                break;
            }
            printImage(fotito, mImage);
            break;
        case 2:
            if (fotito.empty()) {
                cout << "No se pudo cargar la imagen." << endl;
                return -1;
            }
            switch (pColor) {
            case 'C':
                mImage = Gaussian5x5FilterColor(fotito);
                calcularHistogramaColor(fotito, "imgO.csv");
                calcularHistogramaColor(mImage, "imgC.csv");
                break;
            case 'c':
                mImage = Gaussian5x5FilterColor(fotito);
                calcularHistogramaColor(fotito, "imgO.csv");
                calcularHistogramaColor(mImage, "imgC.csv");
                break;
            case 'B':
                mImageG = grayScale(fotito);
                mImage = Gaussian5x5FilterGray(mImageG);
                calcularHistogramaColor(fotito, "imgO.csv");
                calcularHistogramaGray(mImage, "imgB.csv");
                break;
            case 'b':
                mImageG = grayScale(fotito);
                mImage = Gaussian5x5FilterGray(mImageG);
                calcularHistogramaColor(fotito, "imgO.csv");
                calcularHistogramaGray(mImage, "imgB.csv");
                break;
            default:
                break;
            }
            printImage(fotito, mImage);
            break;
        case 3:
            if (fotito.empty()) {
                cout << "No se pudo cargar la imagen." << endl;
                return -1;
            }
            cout << "Ingrese N: "; cin >> N;
            switch (pColor) {
            case 'C':
                mImage = GaussianNxNFilterColor(fotito,N);
                calcularHistogramaColor(fotito, "imgO.csv");
                calcularHistogramaColor(mImage, "imgC.csv");
                break;
            case 'c':
                mImage = GaussianNxNFilterColor(fotito,N);
                calcularHistogramaColor(fotito, "imgO.csv");
                calcularHistogramaColor(mImage, "imgC.csv");
                break;
            case 'B':
                mImageG = grayScale(fotito);
                mImage = GaussianNxNFilterGray(mImageG,N);
                calcularHistogramaColor(fotito, "imgO.csv");
                calcularHistogramaGray(mImage, "imgB.csv");
                break;
            case 'b':
                mImageG = grayScale(fotito);
                mImage = GaussianNxNFilterGray(mImageG, N);
                calcularHistogramaColor(fotito, "imgO.csv");
                calcularHistogramaGray(mImage, "imgB.csv");
                break;
            default:
                break;
            }
            printImage(fotito, mImage);
            break;
        default:
            cout << "input invalido";
            break;
        }
        break;
    case 3:
        if (fotito.empty()) {
            cout << "No se pudo cargar la imagen." << endl;
            return -1;
        }
        mImage = BoxBlurFilter(fotito);
        calcularHistogramaColor(fotito, "imgO.csv");
        calcularHistogramaColor(mImage, "imgC.csv");
        printImage(fotito, mImage);
        break;
    default:
        cout << "input invalido";
        break;
    };
    return 0;
}