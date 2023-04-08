#include "ordenacion.h"
#include "ui_ordenacion.h"
#include "fstream"
#include "iostream"
#include "vector"
#include "algorithm"
#include "chrono"
#include "filesystem"

using namespace std;
Ordenacion::Ordenacion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Ordenacion)
{
    ui->setupUi(this);
}

Ordenacion::~Ordenacion()
{
    delete ui;
}

void Ordenacion::on_pushButton_clicked()
{
    //seleccionar el archivo
}


void Ordenacion::on_pushButton_2_clicked()
{
    //ORDENAR
    //std::ifstream inputFile("numerosNoOrdenados.txt");
    //std::ifstream outputFile("numerosOrdenados.txt");

    // Pedimos al usuario que seleccione el archivo de entrada
    std::filesystem::path inputFilePath;
    std::cout << "Seleccione el archivo de entrada" << std::endl;
    std::cin >> inputFilePath;

    // Abrimos el archivo de entrada
    std::ifstream inputFile(inputFilePath);


    // Pedimos al usuario que seleccione el archivo de salida
    std::filesystem::path outputFilePath;
    std::cout << "Seleccione el archivo de salida" << std::endl;
    std::cin >> outputFilePath;

    // Abrimos el archivo de salida
    std::ofstream outputFile(outputFilePath);

    std::vector<int> numeros;

    //leemos los numeros del archivo no ordenados y los almacenamos en el vector
    int num;

    while(inputFile >> num){
        numeros.push_back(num);//push_back lo que hace es meter el num en el verctor de numeros
    }
    auto start = std::chrono::high_resolution_clock::now;//empieza a contar el crono para saber cuanto tarda en ejecutarse
    std::sort(numeros.begin(), numeros.end());//la funcion en c++ sort los ordena con un puntero en el principio(begin) y otro al final (end)
    auto end = std::chrono::high_resolution_clock::now;

    for(int i = 0; i < numeros.size(); i++){//escribo los numeros ordenados en el archivo de salida
        outputFile << numeros[i] << "\n";
    }

    inputFile.close();
    outputFile.close();

    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "El código tardó " << duration.count() << " milisegundos en ejecutarse." << std::endl;
    }
