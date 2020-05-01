#include <iostream>
#include <fstream>
#include <cstdlib>
#include <random>
#include <omp.h>
#include <ctime>
#include <string>
#include <time.h>

using namespace std;




int main()
{
    clock_t tStart = clock();
    //Aqui se inicializan los stream que se abriran para trabajar
    std::ifstream archivoLee;
    std::ofstream archivoTemp;
    std::string linea;
    archivoLee.open("puntajes.csv");
    archivoTemp.open("Temp.csv");

    float puntajePromedio = 0;

    std::string LineaSplit[6];
    //mientras aun queden lineas en el archivo este loop continuara

        while(!archivoLee.eof()){        
            archivoLee>>linea;     
            try{
                //separamos puntajes y rut
                  
                LineaSplit[0] = linea.substr(0,8);
                  
                LineaSplit[1] = linea.substr(9,3);
                  
                LineaSplit[2] = linea.substr(13,3);
                  
                LineaSplit[3] = linea.substr(17,3);
                  
                LineaSplit[4] = linea.substr(21,3);
                  
                LineaSplit[5] = linea.substr(25,3);
                  
                LineaSplit[6] = linea.substr(29,3);

                //Obtenemos el puntajePromedio
                puntajePromedio = (std::stof(LineaSplit[1]) + std::stof(LineaSplit[2]) + std::stof(LineaSplit[3]) + std::stof(LineaSplit[4]) + std::stof(LineaSplit[5]) + std::stof(LineaSplit[6]))/6;
            
            
                archivoTemp << LineaSplit[0] << ";" << puntajePromedio << endl;
            
            }catch(std::out_of_range e){
                //Linea que no tiene los puntajes o no corresponden
                break;
            }
        }
    
    archivoLee.close();
    archivoTemp.close();
    remove("puntajes.csv");
    rename("Temp.csv","puntajes.csv");
    cout << "tiempo de ejecucion: " << ((double)(clock() - tStart)/CLOCKS_PER_SEC) << endl;
    return 0;
}

